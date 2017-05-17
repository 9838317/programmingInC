#include <l1head.h>
#define BUFFERSIZE 1024


int main(int argc, char** argv)
{   

    int PORT;
    char* ipAddressString;

    if (argc == 2)
    {
        ipAddressString = "127.0.0.1";
        PORT = atoi(argv[1]);    
    }
    else if (argc == 3)
    {
        ipAddressString = argv[1];
        PORT = atoi(argv[2]);
    }

    else
    {
        printf("%s \n", "argc error");
        exit(-1);
    }


    int clientfd = getclientfd(ipAddressString, PORT);
    printf("\n");

    char* requestString = "Sending message to server.\n";

    int readFlag; 

    write(clientfd, requestString, strlen(requestString));
    char buffer[BUFFERSIZE + 1];
    printf("%s \n", "Start to read string from server."); 

while(1)
{
    readFlag = read(clientfd, buffer, BUFFERSIZE); 
    printf("%s \n", buffer);
    if (readFlag <= 0)
    {break;}
}

    close(clientfd);
}
