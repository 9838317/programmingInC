#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>



int main()
{
    // This proram shows AF_INET which is ipv4 and AF_INET6 which is ipv6
    printf("%d \n", AF_INET);
    printf("%d \n", AF_INET6);
}
