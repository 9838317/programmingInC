#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

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
        status = getaddrinfo("127.0.0.1", "8080", &standerAddrinfoSample, &pointerAddrinfoFunctional);
    if (status != 0)
    {
        return 2;
    }
    printf("status is %d \n", status); 
    

    int s = socket(pointerAddrinfoFunctional->ai_family, pointerAddrinfoFunctional->ai_socktype, pointerAddrinfoFunctional->ai_protocol);
    printf("%d \n", s); 


    int stat = bind(s, pointerAddrinfoFunctional->ai_addr, pointerAddrinfoFunctional->ai_addrlen);
    printf("%d \n", stat); 

    freeaddrinfo(pointerAddrinfoFunctional); 
}
