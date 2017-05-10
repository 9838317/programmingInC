#include <l1head.h>

/* Internet-style socket address  structure */
/*
struct sockaddr_in 
{
    unsigned short sin_family; //ipv4 || ip v6
    unsigned short sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8]; //Pad to sizeof(struct sockaddr)
};
*/
#define MAXUSER 1024
typedef struct sockaddr SA;

int main()
{

    int PORT = 80;

    int optval = 1;

    int socketfdServer = getnetfd();                                                     assert(socketfdServer > 0, "cannot create socketfd");
    printf("%d \n", socketfdServer); 
    
    if (setsockopt(socketfdServer, SOL_SOCKET, SO_REUSEADDR,(const void *)&optval , sizeof(int)) < 0)
        return -1;


    struct sockaddr_in serverSocket;
    bzero((char* )(&serverSocket), sizeof serverSocket);

    serverSocket.sin_family = AF_INET;
    serverSocket.sin_addr.s_addr = htonl(INADDR_ANY);
    serverSocket.sin_port = htons( (unsigned short)PORT );  
 
    int goodBind =  bind(socketfdServer, (SA *)&serverSocket, sizeof(serverSocket)) < 0;   assert(goodBind >= 0, "cannot bind to the socket");

    int goodListen = listen(socketfdServer, MAXUSER);                                     assert(goodListen >=0,  "cannot listen");
    
    return socketfdServer;
    
}
