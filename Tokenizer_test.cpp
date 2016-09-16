#include "Tokenizer.h"
#include <memory>
#include <gtest/gtest.h>

using namespace std;

TEST(TokenizerTest, TestEmpty) {
  auto t = make_shared<Tokenizer>("");

  auto result = t->getTokenized();
  ASSERT_EQ(result, nullptr);
}

TEST(TokenizerTest, Toofew1) {
  auto t = make_shared<Tokenizer>("a");

  auto result = t->getTokenized();
  ASSERT_EQ(result, nullptr);
}

TEST(TokenizerTest, Toofew2) {
  auto t = make_shared<Tokenizer>("a|b");

  auto result = t->getTokenized();
  ASSERT_EQ(result, nullptr);
}

TEST(TokenizerTest, TooNoNewline) {
  auto t = make_shared<Tokenizer>("a|b|c");

  auto result = t->getTokenized();
  ASSERT_EQ(result, nullptr);
}

TEST(TokenizerTest, Onlynewline) {
  auto t = make_shared<Tokenizer>("\n");

  auto result = t->getTokenized();
  ASSERT_EQ(result, nullptr);
}

TEST(TokenizerTest, Emptiesandnewline) {
  auto t = make_shared<Tokenizer>("||\n");

  auto result = t->getTokenized();
  ASSERT_EQ(result, nullptr);
}

TEST(TokenizerTest, GoodNodeps) {
  auto t = make_shared<Tokenizer>("a|b|\n");

  auto result = t->getTokenized();
  ASSERT_NE(result, nullptr);
  ASSERT_EQ(result->m_command, "a");
  ASSERT_EQ(result->m_package, "b");
  ASSERT_TRUE((result->m_dependencies).empty());
}

TEST(TokenizerTest, GoodDep1) {
  auto t = make_shared<Tokenizer>("a|b|c\n");

  auto result = t->getTokenized();
  ASSERT_NE(result, nullptr);
  ASSERT_EQ(result->m_command, "a");
  ASSERT_EQ(result->m_package, "b");
  ASSERT_EQ(result->m_dependencies[0], "c");
}

TEST(TokenizerTest, GoodDep2) {
  auto t = make_shared<Tokenizer>("a|b|c,d\n");

  auto result = t->getTokenized();
  ASSERT_NE(result, nullptr);
  ASSERT_EQ(result->m_command, "a");
  ASSERT_EQ(result->m_package, "b");
  ASSERT_EQ(result->m_dependencies[0], "c");
  ASSERT_EQ(result->m_dependencies[1], "d");
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
