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

// This file should be compiled with -llas -ll2net

typedef struct sockaddr SA;

int main()
{

    char* IPAddress = "127.0.0.1";
    int PORT        = 80;

    int socketfdClient = getnetfd();                                                     assert(socketfdClient > 0, "cannot create socketfd");
    printf("%d \n", socketfdClient); 
    
    struct hostent* newHostent;
    newHostent = gethostbyname(IPAddress);                                      assert(newHostent != NULL, "cannot connect domain");

    struct sockaddr_in serverSocket;
    bzero((char* )(&serverSocket), sizeof serverSocket);

    serverSocket.sin_family = AF_INET;
    bcopy((char* )newHostent -> h_addr_list[0], (char* )&serverSocket.sin_addr.s_addr, newHostent -> h_length);
    serverSocket.sin_port = htons(PORT);  
 
    int goodConnect = connect(socketfdClient,  (SA*) &serverSocket, sizeof serverSocket);   assert(goodConnect >= 0, "cannot connect server");
    return socketfdClient;
    
}
