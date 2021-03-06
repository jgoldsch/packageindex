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
  ASSERT_EQ(r->getResponse("INDEXP|foo|bar\n"), "ERROR\n");
  ASSERT_EQ(r->getResponse("foo|foo|bar\n"), "ERROR\n");
  ASSERT_EQ(r->getResponse("INDEXQUERY|INDEXREMOVE|\n"), "ERROR\n");
  ASSERT_EQ(r->getResponse("insert|INDEXREMOVE|\n"), "ERROR\n");

  delete PT;
}

TEST(RequestTest, RequestINDEXfail) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INDEX|foo|bar\n"), "FAIL\n");

  ASSERT_EQ(r->getResponse("INDEX|foo|bar,baz,\n"), "FAIL\n");

  delete PT;
}

TEST(RequestTest, RequestINDEXOK) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INDEX|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|foo|bar\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|foo|bar,baz\n"), "OK\n");


  delete PT;
}

TEST(RequestTest, RequestINDEXCircular) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INDEX|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|bar|foo\n"), "ERROR\n");

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

  ASSERT_EQ(r->getResponse("INDEX|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|foo|bar,baz\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|foo|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("REMOVE|baz|\n"), "OK\n");
  delete PT;
}

TEST(RequestTest, RequestREMOVEFailDepends) {
  PackageTable *PT = new PackageTable();
  auto r = make_shared<RequestHandler>(PT);

  ASSERT_EQ(r->getResponse("INDEX|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|foo|bar,baz\n"), "OK\n");
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

  ASSERT_EQ(r->getResponse("INDEX|bar|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|baz|\n"), "OK\n");
  ASSERT_EQ(r->getResponse("INDEX|foo|bar,baz\n"), "OK\n");
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
