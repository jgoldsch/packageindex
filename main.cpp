int main(int argc, char** argv)
{
  int workers = 10;
  int port = 8080
  string ip;
 
  // Create the queue and consumer (worker) threads
  wqueue<WorkItem*>  queue;
  for (int i = 0; i < workers; i++) {
    ConnectionHandler* handler = new ConnectionHandler(queue);
    if (!handler) {
      printf("Could not create ConnectionHandler %d\n", i);
      exit(1);
    } 
    handler->start();
  }
 
  // Create an acceptor then start listening for connections
  WorkItem* item;
  TCPAcceptor* connectionAcceptor;
  if (ip.length() > 0) {
    connectionAcceptor = new TCPAcceptor(port, (char*)ip.c_str());
  }
  else {
    connectionAcceptor = new TCPAcceptor(port);        
  }                                        
  if (!connectionAcceptor || connectionAcceptor->start() > 0) {
    printf("Could not create an connection acceptor\n");
    exit(1);
  }
 
  // Add a work item to the queue for each connection
  while (1) {
    TCPStream* connection = connectionAcceptor->accept(); 
    if (!connection) {
      printf("Could not accept a connection\n");
      continue;
    }
    item = new WorkItem(connection);
    if (!item) {
      printf("Could not create work item a connection\n");
      continue;
    }
    queue.add(item);
  }
 
  // Should never get here
  exit(0);
}
