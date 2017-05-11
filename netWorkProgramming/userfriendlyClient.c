#include <l1head.h>

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

    // If success, then we have an available socket.
    // The situation is that, when we are able to 
    int clientfd = getclientfd(ipAddressString, PORT);
    printf("\n");
   

    int length = 26;
    char seeStringS[length+1];


    char* requestString = "GET / HTTP/1.0\r\n\r\n";

    write(clientfd, requestString, 128);
    
    int BUFFERSIZE = 1024;
    char buffer[BUFFERSIZE + 1];
    int readFlag; 

    
while(1)
{
    readFlag = read(clientfd, buffer, BUFFERSIZE); 
    assert(readFlag > 0, "cannot read from the server");
    
    

        buffer[readFlag+1] = '\n';
        printf("we've read %d strings \n",readFlag);
        printf("%s \n", buffer); 

}
     

    close(clientfd);
}
