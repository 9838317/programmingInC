#include <l1head.h>
#include "l3io.c"

int main()
{
    int fd = open("utf", O_RDWR);
    printf("%d \n", fd); 

    char buf[100];
    int k = 20;

    //testing readn_whether;
    int readn_whether;
    readn_whether = rio_readn(fd, buf, k);
    printf("%d \n", readn_whether); 
    

    readn_whether = rio_readn(fd, buf, k);
    printf("%d \n", readn_whether); 
}
