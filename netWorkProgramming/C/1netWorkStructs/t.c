#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name
{
    char* name;
    struct name* next;
};

int main()
{
    struct name instanceA;
    struct name instanceB;


    instanceA.name = "asdf";
    instanceB.name = "asdfasd";
    instanceA.next = &instanceB;

    printf("%s \n", instanceA.name);
    printf("%s \n", instanceA.next->name); 

    


}
