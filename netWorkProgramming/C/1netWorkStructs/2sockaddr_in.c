#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

/*

struct sockaddr_in 
{
    short int sin_family;          //  Address family, AF_INET
    unsigned short int sin_port;   // Port number
    struct in_addr sin_addr;       // Internet address
    unsigned char sin_zero[8];     
};

*/


int main()
{
    struct sockaddr_in sockaddr_inInstance;

    inet_pton(AF_INET, "127.0.0.1", &(sockaddr_inInstance.sin_addr)); // IPv4
    printf("%d \n", sockaddr_inInstance.sin_addr.s_addr); 

 
    char presentationIP[100];

    inet_ntop(AF_INET, &(sockaddr_inInstance.sin_addr), presentationIP, 16);

    printf("%s \n", presentationIP); 



}
