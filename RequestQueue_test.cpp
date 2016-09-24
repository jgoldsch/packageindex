#include "RequestQueue.h"
#include <memory>
#include <gtest/gtest.h>

using namespace std;

TEST(RequestQueueTest, TestPush1) {
  auto RQ = make_shared<RequestQueue>();

  RQ->push(1);
  ASSERT_EQ(RQ->pop(), 1);
}

TEST(RequestQueueTest, TestPush3) {
  auto RQ = make_shared<RequestQueue>();

  RQ->push(1);
  RQ->push(2);
  RQ->push(3);
  ASSERT_EQ(RQ->pop(), 1);
  ASSERT_EQ(RQ->pop(), 2);
  ASSERT_EQ(RQ->pop(), 3);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
