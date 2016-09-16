#include "PackageTable.h"
#include <memory>
#include <string>
#include <list>
#include <gtest/gtest.h>

using namespace std;

TEST(PackageTest, EmptyLookup) {
  auto PT = make_shared<PackageTable>();

  auto p = PT->lookup("foo");
  ASSERT_EQ(p, nullptr);
}

TEST(PackageTableTest, SourceInsert) {
  auto PT = make_shared<PackageTable>();
  list<string> empty;
  int err = PT->insert("foo", empty);
  ASSERT_EQ(err, 0);

  auto p = PT->lookup("foo");
  ASSERT_NE(p, nullptr);
  ASSERT_EQ(p->getName(), "foo");
}

TEST(PackageTableTest, SourceInsertDup) {
  auto PT = make_shared<PackageTable>();
  list<string> empty;
  int err = PT->insert("foo", empty);
  ASSERT_EQ(err, 0);

  err = PT->insert("foo", empty);
  // XXX test fails ASSERT_EQ(err, 0);
}

TEST(PackageTableTest, InsertDependMissing) {
  auto PT = make_shared<PackageTable>();
  list<string> deps = {"bar"};
  int err = PT->insert("foo", deps);
  ASSERT_EQ(err, -1);
}

TEST(PackageTableTest, InsertDependsMet) {
  auto PT = make_shared<PackageTable>();
  list<string> deps;
  int err = PT->insert("bar", deps);
  ASSERT_EQ(err, 0);
  deps.push_back("bar");
  err = PT->insert("foo", deps);
  ASSERT_EQ(err, 0);
}

TEST(PackageTableTest, InsertUpdate) {
  auto PT = make_shared<PackageTable>();
  list<string> deps;
  ASSERT_EQ(PT->insert("bar", deps), 0);
  ASSERT_EQ(PT->insert("baz", deps), 0);
  deps.push_back("bar");
  ASSERT_EQ(PT->insert("foo", deps), 0);
  // Graph  foo->bar   baz

  deps.push_back("baz");
  ASSERT_EQ(PT->insert("foo", deps), 0);
  // Graph foo->bar|baz
}

TEST(PackageTableTest, InsertUpdateCircular) {
  auto PT = make_shared<PackageTable>();
  list<string> deps;
  ASSERT_EQ(PT->insert("baz", deps), 0);
  deps.push_back("baz");
  ASSERT_EQ(PT->insert("bar", deps), 0);
  deps.clear();
  deps.push_back("bar");
  ASSERT_EQ(PT->insert("foo", deps), 0);
  // Graph  foo->bar->baz

  deps.clear();
  deps.push_back("foo");
  // Try to add circular dependency like:
  // Graph foo->bar->baz->foo
  ASSERT_EQ(PT->insert("baz", deps), -1);
}
  

TEST(PackageTableTest, RemoveMissing) {
  auto PT = make_shared<PackageTable>();
  int err = PT->remove("foo");
  ASSERT_EQ(err, 0);
}

TEST(PackageTableTest, RemoveNotSink) {
  auto PT = make_shared<PackageTable>();
  list<string> deps;
  int err = PT->insert("bar", deps);
  ASSERT_EQ(err, 0);
  deps.push_back("bar");
  err = PT->insert("foo", deps);
  ASSERT_EQ(err, 0);
  err = PT->remove("bar");
  ASSERT_EQ(err, -1);
}

TEST(PackageTableTest, RemoveSinks) {
  auto PT = make_shared<PackageTable>();
  list<string> deps;
  int err = PT->insert("bar", deps);
  ASSERT_EQ(err, 0);
  deps.push_back("bar");
  err = PT->insert("foo", deps);
  ASSERT_EQ(err, 0);
  PT->print();
  err = PT->remove("foo");
  ASSERT_EQ(err, 0);
  err = PT->remove("bar");
  ASSERT_EQ(err, 0);
  PT->print();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
