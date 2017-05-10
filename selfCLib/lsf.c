#include <stdio.h>
#include <stdlib.h>

void sayHello()
{
    printf("hello"); 
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printIntArray(int intArray[], int arrayLength)
{
    int i;
    for (i = 0; i < arrayLength; i++)
    {
        printf("%d ", intArray[i]);      
    }
    printf("\n"); 
}




// take the argument of an array of pointers and its length as input, then print
void print2dArray(char* arrayOFPointers[], int length)
{
    int i = 0;
    while(length--)
    {
        printf("%s \n", arrayOFPointers[i++]);
    }
}

// get input from stdIn
int getLineFromStdIn(char charArray[], int maxLength)
{
    int c;
    int i = 0;
    while (--maxLength > 0 && (c=getchar()) != EOF && c != '\n')
    {
        charArray[i++] = c;
    }

    if (c == '\n')
    {
        charArray[i++] = c;
    }
    charArray[i] = '\0';
    return i;
}

// get input from a FILE* pointer, and save it to a allocated char* pointer
int getLineFromFsVPointer(char* pointerToArrayPara, FILE* fs)
{
    char c;
    int i = 0;

    assert(pointerToArrayPara != NULL);
    char* operatingPointer = pointerToArrayPara;
    
    while (  ((c = fgetc(fs)) != '\n') && (c != EOF) )    // parenthesis: "!=" is stronger than "="
    {
        i++;
        *operatingPointer++ = c;
    }
    if (c == '\n')
    {    
        i++;
        *operatingPointer++ = '\n';
    }
    *operatingPointer  = '\0';
    printf("%s \n", pointerToArrayPara);

    return i;
}

// This version uses a tempStoreArray to implement the same function.
int getLineFromFsVArray(char* pointerToArray, FILE* fs)
{
    assert(pointerToArray != NULL);

    char c;
    int MAX = 100;

    char tempStoreArray[MAX];
    int i = 0;

    while (  ((c = fgetc(fs)) != '\n') && (c != EOF)  )    // parenthesis: "!=" is stronger than "="
    {
        tempStoreArray[i++] = c;
    }
  
    if (c == '\n')
    {
        tempStoreArray[i++] = '\n';
    }
    tempStoreArray[i]   = '\0';
    strcpy(pointerToArray, tempStoreArray);
    printf("%s \n", pointerToArray);
    
    return i;
}


int assert(int expression)
{
    if (expression)
    {
        printf(""); 
    }
    else
    {
        printf("expression value error %d, quitting.\n", expression); 
        exit(-1);
    }
}
