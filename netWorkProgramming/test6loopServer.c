#include <l0typedef.h> 
#include <l1head.h>
#define BUFFERSIZE 1024


//Assuming that the client send a GET request to the server.
//    GET /file HTTP/1.0/r/n/r/n

int readline(char* buffer, int fileDescriptorPara)
{   // Assume that this is a huge buffer that doesn't overflow
    char c;
    //while ( c = read(fileDescriptorPara) )  
}

void readAll(int fileDescriptorPara)
{
    char buffer[BUFFERSIZE + 1];
    int readFlag;

    while(1)
    {
        readFlag = read(fileDescriptorPara, buffer, BUFFERSIZE);
        if (readFlag == 0) { break; }
        else 
        {
            buffer[BUFFERSIZE] = '\0';
            printf("%s \n", buffer);
        }
    }
}



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
        confd     = accept(serverfd, (SA* )&clientSocket, &clientlen);
        printf("%s \n", "connected!");
        write(confd, "You've enterd server", 20);
        readAll(confd);
     }

        close(confd);
     close(serverfd);
}
