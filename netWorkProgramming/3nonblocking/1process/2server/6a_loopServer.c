#include <l0typedef.h> 
#include <l1head.h>

int main(int argc, char** argv)
{   
    int serverfd, confd, PORT, clientlen;
    struct sockaddr_in clientSocket;

    PORT = atoi(argv[1]);
    serverfd = getserverfd(PORT);
    printf("%s %d \n", "listing file descriptor is", serverfd);  
    while(1)
    {
        clientlen = sizeof(clientSocket); 
        confd     = accept(serverfd, (SA* )&clientSocket, &clientlen);
        fork();
        printf("%s %d \n", "accepting file descriptor is", confd);  
        printf("%s \n", "connected!");
        write(confd, "string", 6);
        close(confd);
     }
     close(serverfd);
}
