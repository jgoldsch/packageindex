#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
  int client_fd = socket(AF_INET, SOCK_STREAM, 0);

  sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family=AF_INET;
  serv.sin_port=htons(8080);
  inet_aton("127.0.0.1", &(serv.sin_addr));

  connect(client_fd, (sockaddr*)(&serv), sizeof(serv));
  int n, m;
  char data[256];
  char recvd[256];
  while (1) {
    fgets(data, 256, stdin);
    n = strlen(data);
    while(n > 0) {  
      m = write(client_fd, data, n);
      n = n - m;
    }

    n = read(client_fd, recvd, 100);
    string resp(recvd);
    
    cout << "package server response is " << resp << endl;

  }
}
