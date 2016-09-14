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

  p->addDependency(pdep);

  // Cannot be a source with a dependency
  ASSERT_FALSE(p->isSource());
  // Still a sink with no dependents
  ASSERT_TRUE(p->isSink());

}
  
 
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

