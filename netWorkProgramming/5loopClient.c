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
    
    char c[2];
    int i = 15;
    
    
    // Actually the idea is simple, we can just read the file descriptor until there is no more to read.
    while (i--)
    {
        int readFlag = read(clientfd, c, 1);  assert(readFlag > 0, "no more to read");
        printf("%c", c[0]);
    }
    close(clientfd);
}
