#include <l1head.h>

void sayHello()
{
    printf("hello"); 
}

int assert(int expression, char* outputString)
{
    if (expression > 0)
    {
        printf("");
        return 0;
    }
    else
    {

        printf("\n");  
        printf("expression value error %d, %s.\n", expression, outputString); 
        exit(-1);
    }
}
