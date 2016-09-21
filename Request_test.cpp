#include "Request.h"
#include <memory>
#include <gtest/gtest.h>

using namespace std;

TEST(RequestTest, RequestTokenFail) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("foo"), "ERROR\n");
  delete PT;
}

TEST(RequestTest, RequestLizard) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("LIZARD|foo|bar\n"), "ERROR\n");
  ASSERT_EQ(r->getResponse("INSERTP|foo|bar\n"), "ERROR\n");
  ASSERT_EQ(r->getResponse("foo|foo|bar\n"), "ERROR\n");
  ASSERT_EQ(r->getResponse("INSERTQUERY|INSERTREMOVE|\n"), "ERROR\n");
  ASSERT_EQ(r->getResponse("insert|INSERTREMOVE|\n"), "ERROR\n");

  delete PT;
}

TEST(RequestTest, RequestINSERTfail) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INSERT|foo|bar\n"), "FAIL\n");

  ASSERT_EQ(r->getResponse("INSERT|foo|bar,baz,\n"), "FAIL\n");

  delete PT;
}

TEST(RequestTest, RequestINSERTOK) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INSERT|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|foo|bar\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|foo|bar,baz\n"), "OK\n");


  delete PT;
}

TEST(RequestTest, RequestINSERTCircular) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INSERT|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|bar|foo\n"), "ERROR\n");

  delete PT;
}

TEST(RequestTest, RequestREMOVEmissing) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("REMOVE|foo|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|foo|bar\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|f.\to\no|\n"), "OK\n");

  delete PT;
}

TEST(RequestTest, RequestREMOVEOK) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INSERT|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|foo|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|baz|\n"), "OK\n");
  delete PT;
}

TEST(RequestTest, RequestREMOVEFailDepends) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INSERT|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|baz|\n"), "FAIL\n");
  ASSERT_EQ(r->getResponse("REMOVE|bar|\n"), "FAIL\n");
  delete PT;
}

TEST(RequestTest, RequestQUERYfail) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("QUERY|foo|\n"), "FAIL\n");
  ASSERT_EQ(r->getResponse("QUERY|foo|bar\n"), "FAIL\n");

  delete PT;
}

TEST(RequestTest, RequestQUERYOK) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INSERT|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INSERT|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("QUERY|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("QUERY|foo|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("QUERY|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("QUERY|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|foo|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("QUERY|foo|\n"), "FAIL\n");
  delete PT;
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
