#include <l0typedef.h> 
#include <l1head.h>

int main(int argc, char** argv)
{   


    int clientlen;
    int confd;
    struct sockaddr_in clientSocket;

    // If success, then we have an available socket.
    // The situation is that, when we are able to 

    int PORT = atoi(argv[1]);
    int serverfd = getserverfd(PORT);
    
    char buffer[128];
    
    while(1)
    {
        printf("%s", "connected!");
        clientlen = sizeof(clientSocket); 
        confd     = accept(serverfd, (SA* )&clientSocket, &clientlen);
        write(confd, "stringing", 9);
        close(confd);
     }
     close(serverfd);
}
