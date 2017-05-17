#include <l0typedef.h> 
#include <l1head.h>
#define BUFFERSIZE 1024




int main(int argc, char** argv)
{   
    int serverfd, confd, PORT, clientlen;
    struct sockaddr_in clientSocket;

    PORT = atoi(argv[1]);
    serverfd = getserverfd(PORT);


    char buffer[BUFFERSIZE + 1];
    
    char c;

    while(1)
    {
        clientlen = sizeof(clientSocket); 

        int confd   = accept(serverfd, (SA* )&clientSocket, &clientlen);
        printf("%s \n", "connected!");
       
        // print client words
        int readFlag = read(confd, buffer, BUFFERSIZE);
        printf("%s \n", buffer); 
         

        // print server words
        char* serverWords = "This is server taking to you.\n";
        while(1)
        {
            write(confd, serverWords, sizeof(serverWords));
        }
        close(confd);
      
    }
    close(serverfd);
}
