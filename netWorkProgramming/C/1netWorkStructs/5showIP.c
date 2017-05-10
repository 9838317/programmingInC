#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


// This is a program shows how to get the ip address of a domain name.
int main(int argc, char* argv[])
{
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[100];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0)
    {
        printf("%s \n", "cannot getaddrinfo, error."); 
        return 2;
    }

    printf("IP addresses for %s:\n\n", argv[1]);
    
    for(p = res;p != NULL; p = p->ai_next)
    {
        void *addr;
        char *ipver;
        
        if (p->ai_family == AF_INET) 
        { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        }
        else 
        { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }
    
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf(" %s: %s\n", ipver, ipstr);
    }
    
    freeaddrinfo(res); // free the linked list
    return 0;
}
