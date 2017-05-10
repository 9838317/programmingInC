#include <l1head.h>

int main()
{   

    // If success, then we have an available socket.
    // The situation is that, when we are able to 
    int clientfd = getclientfd("127.0.0.1", 8080);
    
    char c[2];
    int i = 15;
    
    
    // Actually the idea is simple, we can just read the file descriptor until there is no more to read.
    while (i--)
    {
        int readFlag = read(clientfd, c, 1);  assert(readFlag > 0, "no more to read");
        printf("%c", c[0]);
    }
}
