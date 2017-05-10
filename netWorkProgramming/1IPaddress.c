#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// This offers 2 functions that can allows you to transfer bidirection a network address.
int main()
{
    struct in_addr netTypeIPAddress;

    char* ipReadable = "192.168.0.10";
    
    // This is to transfer the human readable IP address to the struct in_addr
    inet_pton(AF_INET, ipReadable, &netTypeIPAddress);


    //Now the struct netTypeIPAddress stores the network representation of the ip, we can transfer the ip out.
    char getIPAddressFromIn_addr[100];
    inet_ntop(AF_INET, &netTypeIPAddress, getIPAddressFromIn_addr ,INET_ADDRSTRLEN);

    printf("%s \n", getIPAddressFromIn_addr); 

}
