#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
/*

struct addrinfo 
{
    int ai_flags;                        // AI_PASSIVE, AI_CANONNAME, etc.
    int ai_family;                       // AF_INET, AF_INET6, AF_UNSPEC
    int ai_socktype;                     // SOCK_STREAM, SOCK_DGRAM
    int ai_protocol;                     // use 0 for "any"
    size_t ai_addrlen;                   // size of ai_addr in bytes
    struct sockaddr *ai_addr;            // struct sockaddr_in or _in6
    char *ai_canonname;                  // full canonical hostname
    struct addrinfo *ai_next;            // linked list, next node
};

int getaddrinfo
(
    const char *node,     // e.g. "www.example.com" or IP
    const char *service, // e.g. "http" or port number
    const struct addrinfo *hints,
    struct addrinfo **res
);

*/


int main()
{
    struct addrinfo   standerAddrinfoSample;
    struct addrinfo*  pointerAddrinfoFunctional;

    // Following are to initialize the sample addrinfo.
    memset(&standerAddrinfoSample, 0, sizeof standerAddrinfoSample); 
    standerAddrinfoSample.ai_flags = AI_PASSIVE;
    standerAddrinfoSample.ai_family = AF_UNSPEC;
    standerAddrinfoSample.ai_socktype = SOCK_STREAM; 


    int status;
        status = getaddrinfo("127.0.0.1", "80", &standerAddrinfoSample, &pointerAddrinfoFunctional);
    printf("status is %d \n", status); 

    int s = socket(pointerAddrinfoFunctional->ai_family, pointerAddrinfoFunctional->ai_socktype, pointerAddrinfoFunctional->ai_protocol);

    printf("%d \n", s); 
    printf("%d \n", pointerAddrinfoFunctional->ai_family); 
    printf("%d \n", pointerAddrinfoFunctional->ai_socktype); 
    printf("%d \n", pointerAddrinfoFunctional->ai_protocol); 
    printf("%d \n", pointerAddrinfoFunctional->ai_addr); 

    // Finally we free it.
    freeaddrinfo(pointerAddrinfoFunctional); 
}
