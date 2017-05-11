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


    char* requestString = "GET /index.html HTTP/1.1 \n";
   
    strncpy(seeStringS, requestString, length);
    seeStringS[length] = '\n';

    int j;
    for (j = 0; j < length+1; j++)
    {
        printf("%c\t", seeStringS[j]); 
    }
    printf("%s \n", "test str"); 
    for (j = 0; j < length + 1; j++)
    {
        printf("%d\t", j);      
    }

    printf("%c \n", seeStringS[length-3]); 
    printf("%c \n", seeStringS[length-2]); 
    printf("%c \n", seeStringS[length-1]); 
    printf("%c \n", seeStringS[length-0]); 
    
    char buffer[1024];

    int readFlag; 

    write(clientfd, seeStringS, length);


    
while(1)
{
    readFlag = read(clientfd, buffer, 45); 
    printf("%d \n",readFlag);
    if (readFlag <= 0)
    {break;}
}
    printf("%d \n", readFlag); 
    printf("%d \n", readFlag); 
        assert(readFlag > 0, "no more to read");
        printf("%s \n", buffer);

    close(clientfd);
}
