#include <string>
#include <memory>
#include <iostream>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <thread>
#include "Tokenizer.h"
#include "PackageTable.h"
#include "RequestQueue.h"

using namespace std;

class RequestHandler {
  PackageTable *m_PT;
  RequestQueue *m_RQ;

public:
  RequestHandler(PackageTable *in_PT, RequestQueue *in_RQ) {
    m_PT = in_PT;
    m_RQ = in_RQ;
  }

  RequestHandler(PackageTable *in_PT) {
    m_PT = in_PT;
    m_RQ = nullptr;
  }


  string getResponse(string inStr) {
    auto tokenizer = make_shared<Tokenizer>(inStr);
    Tokenized_t * myT = tokenizer->getTokenized();
    int err = 0;

    if (myT == nullptr) {
      // error case, request cannot be tokenized
#ifndef NDEBUG
      cout << "Thread id " << std::this_thread::get_id() << " string " << inStr
	   << " produced token parsing error" << endl;
#endif	/* !NDEBUG */
      err = 1;
    } else if (myT->m_command == "INDEX") {
      err = m_PT->insert(myT->m_package, myT->m_dependencies);
    } else if (myT->m_command == "REMOVE") {
      err = m_PT->remove(myT->m_package);
    } else if (myT->m_command == "QUERY") {
      err = m_PT->query(myT-> m_package);
    } else {
      // error case
      err = 1;
    }

    return GetResponseCode(err);
  }

  void handleRequests() {
    if (m_RQ == nullptr) {
      cerr << "no RequestQueue has been allocated." << endl;
      assert(0);
      return;
    }
    while (1) {
      int sd = m_RQ->pop();
      int nbytes = 0;
      char buffer[4096];

      while ((nbytes = read(sd, buffer, 4095)) > 0) {
	buffer[nbytes] = '\0';
	string request(buffer);
#ifndef NDEBUG
	cout << "Thread id " << std::this_thread::get_id() << " received \"" << request << "\"" << endl;
#endif	/* !NDEBUG */
	string response = getResponse(request);
	nbytes = write(sd, response.c_str(), response.size() + 1);
	if (nbytes < 0) {
	  cerr << "Thread id " << std::this_thread::get_id() << " error writting socket" << endl;
	}
#ifndef NDEBUG
	cout << "Thread id " << std::this_thread::get_id() << " sent nbytes " << nbytes
	   << "\"" << response << "\"" << endl;
#endif	/* !NDEBUG */
	bzero(buffer, 4096);
      }

      // nothing more from client
#ifndef NDEBUG
      cout << "Thread id " << std::this_thread::get_id() << " client has closed connection " << sd << endl;
#endif	/* !NDEBUG */
      close(sd);
    }
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
