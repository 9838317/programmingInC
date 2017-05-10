#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
/*

struct addrinfo 
{
    struct sockaddr *ai_addr;            // struct sockaddr_in or _in6
};

*/


int main()
{
    struct addrinfo   standerAddrinfoSample;
    struct addrinfo*  pointerAddrinfoFunctional;


    // Following are to initialize the sample addrinfo.
    memset(&standerAddrinfoSample, 0, sizeof standerAddrinfoSample); 
    standerAddrinfoSample.ai_flags = AI_PASSIVE;
    //standerAddrinfoSample.ai_family = AF_UNSPEC;
    standerAddrinfoSample.ai_family = AF_INET;
    standerAddrinfoSample.ai_socktype = SOCK_STREAM; 


    int status;
        status = getaddrinfo("127.0.0.1", "80", &standerAddrinfoSample, &pointerAddrinfoFunctional);
    printf("status is %d \n", status); 


   printf("%d \n",  ((struct sockaddr_in*)(pointerAddrinfoFunctional -> ai_addr))-> sin_port);

 
    printf("%s \n", pointerAddrinfoFunctional -> ai_addr ->sa_data ); 
    printf("%d \n", sizeof pointerAddrinfoFunctional -> ai_addr ->sa_data ); 


    char presentationIP[100];
    
    // After writing this pointer casting, this is the reason why there is a pointer casting function of (*get_in_addr)
    // But here, the situation is that, the function getaddrinfo return us the pointerAddrinfoFunctional pointer, in this pointer, it is already stores the ip address of our input, that is, the file descriptor has already stores some valuable infomations.
    inet_ntop(AF_INET,  &(((struct sockaddr_in*)(pointerAddrinfoFunctional -> ai_addr)) -> sin_addr), presentationIP, 16);

    
    printf("%s \n", presentationIP); 

    printf("%d \n", ((struct sockaddr_in*)(pointerAddrinfoFunctional -> ai_addr)) -> sin_port); 
    


}
