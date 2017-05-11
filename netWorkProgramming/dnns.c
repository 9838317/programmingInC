#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <l1head.h>


int main()
{
    struct in_addr* addr;
    char** pp;
    struct hostent* newHostent;

    newHostent = gethostbyname("cs.cmu.eu");
    printf("%s \n", newHostent -> h_name);
}
