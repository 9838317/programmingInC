#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "8080"
#define MAXDATASIZE 100 // max number of bytes we can get at once

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) 
    {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    int rv;
    char s[INET6_ADDRSTRLEN];
    struct addrinfo   standerAddrinfoSample;
    struct addrinfo*  pointerAddrinfoFunctional, *p;

    // Following are to initialize the sample addrinfo.
    memset(&standerAddrinfoSample, 0, sizeof standerAddrinfoSample); 
    standerAddrinfoSample.ai_family = AF_UNSPEC;
    standerAddrinfoSample.ai_socktype = SOCK_STREAM; 



    int status;
        status = getaddrinfo("127.0.0.1", "80", &standerAddrinfoSample, &pointerAddrinfoFunctional);
    if (status != 0)
    {
        return 2;
    }
    printf("using getaddrinfo to get a res, status is %d \n", status); 
    

    int i = 0;
    for(p = pointerAddrinfoFunctional; p != NULL; p = p->ai_next) 
    {
    printf("we are in the loop, i is %d", i);
    i++;

        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        connect(sockfd, p->ai_addr, p->ai_addrlen); 
        
        break;
    }

    freeaddrinfo(pointerAddrinfoFunctional); 

    numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
    
    printf("%s \n", sizeof numbytes); 
    
    buf[numbytes] = '\0';


    printf("client: received '%s'\n",buf);
    close(sockfd);

    return 0;

}
