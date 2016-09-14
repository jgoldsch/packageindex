#include "Package.h"
#include <memory>
#include <gtest/gtest.h>

using namespace std;

TEST(PackageTest, SourceNode) {
  auto p = make_shared<Package>("testpackage");
  // package with no dependencies is a source in DAG
  ASSERT_TRUE(p->isSource());
}

TEST(PackageTest, SinkNode) {
  auto p = make_shared<Package>("testpackage");
  // a new package is also a sink
  ASSERT_TRUE(p->isSink());
}

TEST(PackageTest, AddDependency) {
  auto p = make_shared<Package>("testpackage");
  Package *pdep = new Package("testdepend");

  int err = p->addDependency(pdep);

  ASSERT_EQ(err, 0);

  // Our Graph:  testpackage->testdepend

  // Cannot be a source with a dependency
  ASSERT_FALSE(p->isSource());
  // Still a sink with no dependents
  ASSERT_TRUE(p->isSink());

  // The dependent object is a source, as it has no dependencies in our graph
  ASSERT_TRUE(pdep->isSource());
  // The dependent object is not a sink, because p depends on it.
  ASSERT_FALSE(pdep->isSink());

  delete pdep;
}

TEST(PackageTest, AddSelfDependency) {
  auto p = make_shared<Package>("testpackage");
  Package *pdep = new Package("testpackage");

  int err = p->addDependency(pdep);

  // insert will fail, because of circular dependency
  ASSERT_EQ(err, -1);
  // package ist still a source, no dependencies
  ASSERT_TRUE(p->isSource());
  // Still a sink with no dependents
  ASSERT_TRUE(p->isSink());

  delete pdep;
}

TEST(PackageTest, AddDependent) {
  auto p = make_shared<Package>("testpackage");
  Package *pdep = new Package("testdependent");

  int err = p->addDependent(pdep);

  // Our Graph:  testdependent->testpackage

  ASSERT_EQ(err, 0);

  // Still a source, no dependencies
  ASSERT_TRUE(p->isSource());
  // Not a sink, since there is a dependent
  ASSERT_FALSE(p->isSink());

  delete pdep;
}

TEST(PackageTest, RemoveDependency) {
  auto p = make_shared<Package>("testpackage");
  Package *pdep = new Package("testdepend");

  int err = p->addDependency(pdep);

  ASSERT_EQ(err, 0);

  // Our Graph:  testpackage->testdepend

  err = p->removeDependency(pdep);
  delete pdep;

  // Our Graph:  testpackage

  ASSERT_EQ(err, 0);

  // package is a source, no dependencies
  ASSERT_TRUE(p->isSource());
  // package is a sink with no dependents
  ASSERT_TRUE(p->isSink());

}

/*
TEST(PackageTest, RemoveDependencyFail) {
  Package *pA = new Package("A");
  Package *pB = new Package("B");
  Package *pC = new Package("C");

  int err = pA->addDependency(pB);
  ASSERT_EQ(err, 0);
  err = pB->addDependency(pC);
  ASSERT_EQ(err, 0);

  // Our Graph:  A->B->C

}
*/

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

