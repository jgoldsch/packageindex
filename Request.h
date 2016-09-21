#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Tokenizer.h"
#include "PackageTable.h"

class RequestHandler {
  PackageTable *PT;
public:
  RequestHandler(PackageTable *inPT) {
    PT = inPT;
  }

  string getResponse(string inStr) {
    auto tokenizer = make_shared<Tokenizer>(inStr);
    Tokenized_t * myT = tokenizer->getTokenized();
    int err = 0;

    if (myT == nullptr) {
      // error case, request cannot be tokenized
      err = 1;
    } else if (myT->m_command == "INSERT") {
      list<string> dependsList(myT->m_dependencies.begin(), myT->m_dependencies.end());
      err = PT->insert(myT->m_package, dependsList);
    } else if (myT->m_command == "REMOVE") {
      err = PT->remove(myT->m_package);
    } else if (myT->m_command == "QUERY") {
      err = PT->query(myT-> m_package);
    } else {
      // error case
      err = 1;
    }

    return GetResponseCode(err);
  }

  static string GetResponseCode(int err) {
    switch (err) {
    case 0:
      return "OK\n";
    case 1:
      return "ERROR\n";
    case -1:
      return "FAIL\n";
    default:
      assert(0);
      return "ERROR\n";
    }
  }    
};
