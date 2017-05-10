#include <l1head.h>
#define MAXUSER 1024
typedef struct sockaddr SA;






// This method has been tested.
int getnetfd()
{   
    int netfd = socket(AF_INET, SOCK_STREAM, 0);
    if (netfd == 0)
    { return -1; }
    else
    {
        printf("successfully get netfd, which is %d", netfd); 
        return netfd; 
    }
}


// This method has been tested
int getclientfd(char* ipArgs, int port)
{
    char* IPAddress = ipArgs;
    int PORT        = port;

    int socketfdClient = getnetfd();                                                     assert(socketfdClient > 0, "cannot create socketfd");
    printf("%d \n", socketfdClient); 
    
    struct hostent* newHostent;
    newHostent = gethostbyname(IPAddress);                                              assert(newHostent != NULL, "cannot connect domain");

    struct sockaddr_in serverSocket;
    bzero((char* )(&serverSocket), sizeof serverSocket);

    serverSocket.sin_family = AF_INET;
    bcopy((char* )newHostent -> h_addr_list[0], (char* )&serverSocket.sin_addr.s_addr, newHostent -> h_length);
    serverSocket.sin_port = htons(PORT);  
 
    int goodConnect = connect(socketfdClient,  (SA*) &serverSocket, sizeof serverSocket);   assert(goodConnect >= 0, "cannot connect server");
    return socketfdClient;
}


// This method has been tested
int getserverfd()
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

    int goodListen = listen(socketfdServer, MAXUSER);                                      assert(goodListen >=0,  "cannot listen");
    
    return socketfdServer;
}
