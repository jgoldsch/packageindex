#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Tokenizer.h"


class RequestFactory {
public:
  RequestFactory() {}

  static auto getFactory(string inStr) {
    auto tokenizer = make_shared<Tokenizer>(inStr);
    Tokenized_t * myT = tokenizer->getTokenized();

    if (myT == nullptr) {
      return new RequestError();
    }

    switch (myT->m_command) {
    case "INSERT": 
    case "REMOVE":
    case "QUERY":
    default:
      return new RequestError();
    
    }
  }
};

class Request {
  
public:

  
  bool isError() { return false; }

};


class RequestError public Request {

  boot isError() { return true; }

};
