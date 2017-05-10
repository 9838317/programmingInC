#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

int main()
{
    int i = socket(2, 1, 6);
    printf("%d \n", i); 

}
