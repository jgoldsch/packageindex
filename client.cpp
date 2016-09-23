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
  int clifd;
  clifd=socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
  sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family=AF_INET;
  serv.sin_port=htons(8080);
  inet_aton("127.0.0.1", &(serv.sin_addr));

  connect(clifd, (sockaddr*)(&serv), sizeof(serv));//blocking call
  int n,m;
  char data[100];
  char recvd[100];
  for(;;)
    {
      fgets(data, 100,stdin );
      n=strlen(data);
      cout<<"You have written "<<n<<endl;

      if(n>0)
        {
	  while(n>0)
            {  
	      m=write(clifd,data,n);
	      n=n-m;
            }
        }

      n=read(clifd, recvd, 100);
      string resp(recvd);
      cout<<"Server echoed back "<< resp <<endl;

      if(n>0)
        {
	  while(n>0)
            {
	      m=fputs(data,stdout);
	      fflush(stdout);
	      n=n-m;
            }
	  //cout<<data<<endl;
        }
    }
}
