#include <stdio.h>
#include <netdb.h>
#include <string.h>

/*

struct sockaddr 
{
    // address family, AF_xxx
    unsigned short sa_family;

    // 14 bytes of protocol address
    char sa_data[14];
};


// Same size as struct sockaddr
struct sockaddr_in 
{
    short int sin_family;          //  Address family, AF_INET
    
    unsigned short int sin_port;   // Port number
    
    struct in_addr sin_addr;       // Internet address
    
    unsigned char sin_zero[8];     
};

// Internet address (a structure for historical reasons)
struct in_addr 
{
    uint32_t s_addr; // that's a 32-bit int (4 bytes)
}

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

#include<netdb.h>
int getaddrinfo
(
    const char *node,     // e.g. "www.example.com" or IP
    const char *service, // e.g. "http" or port number
    const struct addrinfo *hints,
    struct addrinfo **res
);


























*/
int
main(int argc, char **argv)
{

// Following we have 4 structures:    

    // 1. struct in_addr is to store the ip address;
    struct in_addr in_addrInstance;

    // 2. Struct sockaddr is to store the ip address and version(v4, v6), definition is as following
    struct sockaddr     sockaddrInstance;

    // 3. This structure is just the same as above, but specically for ipv4, notice that it contains in_addr.
    struct sockaddr_in	sockaddr_inInstance;

    // 4.
    struct addrinfo     addrinfoInstance;

    printf("%d \n", sizeof(in_addrInstance)); 
    printf("%d \n", sizeof(sockaddrInstance)); 
    printf("%d \n", sizeof(sockaddr_inInstance)); 
    printf("%d \n", sizeof(addrinfoInstance)); 

//--------------------------------------------------------


    char ip4IntegerAddress[INET_ADDRSTRLEN] = "10.12.110.57";    // space to hold the IPv4 string

    // This function goess to the address of sockaddr_in, and change the value of sockaddr_in.s_addr
    inet_pton(AF_INET, ip4IntegerAddress, &(sockaddr_inInstance.sin_addr)); // IPv4
    //inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6
    printf("%d \n", sockaddr_inInstance.sin_addr.s_addr); 
    
    // This function reversely change the s_addr into a readable 4 byte ip address.
    inet_ntop(AF_INET, &(sockaddr_inInstance.sin_addr), ip4IntegerAddress, INET_ADDRSTRLEN);
    printf("The IPv4 address is: %s\n", ip4IntegerAddress);

    printf(" %d\n", INET_ADDRSTRLEN); 

    // Following again shows that inet_pton actually change sockaddr_in.s_addr.
    sockaddr_inInstance.sin_addr.s_addr = 16;
    printf("%d \n", sockaddr_inInstance.sin_addr.s_addr); 


/*
    In a word, in_addr stores a computer readable ipv4 address, and it is wrapped into a struct of sockaddr_in, 
    this is an analogue of sockaddr. And the sockaddr_in is furtuer wrapped into the addrinfo struct. 
    Following we will see how the addrinfo is used to operate something.

*/
    
    // getaddrinfo will return a int; 

    struct addrinfo standerAddrinfoSample;
    memset(&standerAddrinfoSample, 0, sizeof standerAddrinfoSample); 

    standerAddrinfoSample.ai_flags = AI_PASSIVE;
    standerAddrinfoSample.ai_family = AF_UNSPEC;

    standerAddrinfoSample.ai_socktype = SOCK_STREAM; 


    struct addrinfo* pointerAddrinfoFunctional;


    int status;
        status = getaddrinfo("127.0.0.1", "80", &standerAddrinfoSample, &pointerAddrinfoFunctional);
    printf("status is %d \n", status); 

    
    printf("%d \n", pointerAddrinfoFunctional->ai_family); 
    printf("%d \n", pointerAddrinfoFunctional->ai_socktype); 
    printf("%d \n", pointerAddrinfoFunctional->ai_protocol); 
    int s = socket(pointerAddrinfoFunctional->ai_family, pointerAddrinfoFunctional->ai_socktype, pointerAddrinfoFunctional->ai_protocol);

    printf("%d \n", s); 

    // Finally we free it.
    freeaddrinfo(pointerAddrinfoFunctional); 

 }
