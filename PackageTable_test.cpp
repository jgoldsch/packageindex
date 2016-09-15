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

TEST(PackageTest, SourceInsert) {
  auto PT = make_shared<PackageTable>();
  list<string> empty;
  int err = PT->insert("foo", empty);
  ASSERT_EQ(err, 0);

  auto p = PT->lookup("foo");
  ASSERT_NE(p, nullptr);
  ASSERT_EQ(p->getName(), "foo");
}

TEST(PackageTest, SourceInsertDup) {
  auto PT = make_shared<PackageTable>();
  list<string> empty;
  int err = PT->insert("foo", empty);
  ASSERT_EQ(err, 0);

  err = PT->insert("foo", empty);
  // XXX test fails ASSERT_EQ(err, 0);
}

TEST(PackageTest, InsertDependMissing) {
  auto PT = make_shared<PackageTable>();
  list<string> deps = {"bar"};
  int err = PT->insert("foo", deps);
  ASSERT_EQ(err, -1);
}

TEST(PackageTest, InsertDependsMet) {
  auto PT = make_shared<PackageTable>();
  list<string> deps;
  int err = PT->insert("bar", deps);
  ASSERT_EQ(err, 0);
  deps.push_back("bar");
  err = PT->insert("foo", deps);
  ASSERT_EQ(err, 0);
  PT->print();
}

TEST(PackageTest, RemoveMissing) {
  auto PT = make_shared<PackageTable>();
  int err = PT->remove("foo");
  ASSERT_EQ(err, 0);
}

TEST(PackageTest, RemoveNotSink) {
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

TEST(PackageTest, RemoveSinks) {
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
  PT->print();
  err = PT->remove("bar");
  ASSERT_EQ(err, 0);
}
 
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
