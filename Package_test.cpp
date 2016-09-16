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


TEST(PackageTest, SearchTest) {
  Package *pA = new Package("A");
  Package *pB = new Package("B");
  Package *pC = new Package("C");
  int err = pA->addDependency(pB);
  ASSERT_EQ(err, 0);
  err = pA->addDependency(pC);
  ASSERT_EQ(err, 0);

  ASSERT_EQ((pA->search("C"))->getName(), "C");
  ASSERT_EQ((pA->search("B"))->getName(), "B");
  ASSERT_EQ((pA->search("A"))->getName(), "A");
  ASSERT_EQ(pA->search("foo"), nullptr);
  delete pA;
  delete pB;
  delete pC;
}

TEST(PackageTest, DeepSearchTest) {
  Package *pA = new Package("A");
  int i,j;
  list<Package *> testobjs;
  for (i = 0; i < 10; ++i) {
    Package *newP = new Package((to_string(i)));
    testobjs.push_back(newP);
    pA->addDependency(newP);
    for (j=100; j < 110; ++j) {
      Package *newnewP = new Package((to_string(j*i+1)));
      testobjs.push_back(newnewP);
      newP->addDependency(newnewP);
    }
  }

  ASSERT_EQ(pA->search(to_string(901))->getName(), to_string(901));
  for (auto p : testobjs) {
    delete p;
  }
  delete pA;
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

