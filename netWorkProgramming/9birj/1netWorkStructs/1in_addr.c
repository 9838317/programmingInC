#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

/*

// Internet address (a structure for historical reasons)
struct in_addr 
{
    uint32_t s_addr; // that's a 32-bit int (4 bytes)
}

*/

int main()
{

    // This program starts to show the basic structure of in_addr. 
    // And the related function inet_pton, and inet_ntop.

    printf("%d \n", INET_ADDRSTRLEN); 

    struct in_addr in_addrInstance;
    printf("%d \n", sizeof in_addrInstance);          // out: 4
    printf("%d \n", in_addrInstance.s_addr);          // out: unitialized

    in_addrInstance.s_addr = 256;
    printf("%d \n", in_addrInstance.s_addr);          // out: 256

    inet_pton(AF_INET, "192.168.0.1", &(in_addrInstance)); // IPv4
    printf("%d \n", in_addrInstance.s_addr); 
    
    char tempArray[100];
    inet_ntop(AF_INET, &(in_addrInstance), tempArray, INET_ADDRSTRLEN);
    printf("The IPv4 address is: %s\n", tempArray);

}

