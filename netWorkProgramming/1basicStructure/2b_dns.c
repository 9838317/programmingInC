#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>


/*
struct hostent // gethostbyname returns a pointer of hostent
{
    char*   h_name;
    char**  h_aliases;
    int     h_addrtype;
    int     h_length;
    char**  h_addr_list;   // this is a long list  
 };
*/

int main()
{
    struct in_addr* addr;
    char** pp;
    struct hostent* newHostent;

    newHostent = gethostbyname("cs.cmu.edu");
    printf("%s \n", newHostent -> h_name);

    char getIPAddressFromIn_addr[100];
    for (pp = newHostent->h_addr_list; *pp != NULL; pp++)
    {
        addr = ((struct in_addr* )*pp);

        inet_ntop(AF_INET,  addr, getIPAddressFromIn_addr ,16);
        //inet_ntop(AF_INET,  &(((struct in_addr* )*pp)->s_addr), getIPAddressFromIn_addr ,16);
        printf("%s \n", getIPAddressFromIn_addr); 
    }

}
