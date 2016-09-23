#include <iostream>
#include <string>
#include <thread>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include "Request.h"


int main(int argc, char** argv)
{
  int workers = 10;
  int port = 8080;
  int backlog = 100;
  string ip;

  if (argc == 2) {
    workers = atoi(argv[1]);
  }
 
  // Create our instances of the PackageTable and the RequestQueue
  // These become parameters for our RequestHandler Worker threads.
  PackageTable *PT = new PackageTable();
  RequestQueue *RQ = new RequestQueue();

  for (int i = 0; i < workers; i++) {
    std::thread worker(&RequestHandler::handleRequests, RequestHandler(PT, RQ));
    worker.detach();
  }
 
  int listen_sd = socket(PF_INET, SOCK_STREAM, 0);
 
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = PF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = INADDR_ANY;
  socklen_t socklen = sizeof(address);
  int optval = 1;
  setsockopt(listen_sd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
 
  int result = bind(listen_sd, (struct sockaddr*)&address, sizeof(address));
  if (result != 0) {
    cerr << "bind() failed" << endl;
    delete PT;
    delete RQ;
    return -1;
  }
  result = listen(listen_sd, backlog);
  if (result != 0) {
    cerr << "bind() failed" << endl;
    delete PT;
    delete RQ;
    return -1;
  }

  // Add a work item to the queue for each connection
  while (1) {
    int accept_sd = accept(listen_sd, (struct sockaddr*)&address, &socklen);
    if (accept_sd < 0) {
      // XXX add debug info
      cerr << "accept failed" << endl;
      continue;
    }

    RQ->push(accept_sd);
  }
 
  // not reached
  delete PT;
  delete RQ;
  exit(0);
}
