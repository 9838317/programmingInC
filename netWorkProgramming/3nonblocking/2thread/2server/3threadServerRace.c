#include <l0typedef.h> 
#include <l1head.h>
#define BUFFERSIZE 27


//Assuming that the client send a GET request to the server.
//    GET /file HTTP/1.0/r/n/r/n

int hugeWrite(int* fileDescriptorPara)
{   // Assume that this is a huge buffer that doesn't overflow
    char buffer[BUFFERSIZE + 1];
    
    int getTxtFd = open("txt", O_RDWR); assert(getTxtFd > 0, "cannot open disk file.");

    int readFlag;
    int writeFlag;
    while(1)
    {
        readFlag = read(getTxtFd, buffer, BUFFERSIZE);
        buffer[0] = *fileDescriptorPara + '0';
        if (readFlag > 0)
        {       
            writeFlag = write(*fileDescriptorPara, buffer, readFlag);
            
            //An exception should be throw here since we need to make sure that the client is still alive.
            if (writeFlag <= 0)
            { break; }
        }
        else
        { break; }
    }
    close(getTxtFd);
    close(*fileDescriptorPara);
}

void readAll(int fileDescriptorPara)
{
    char buffer[BUFFERSIZE + 1];
    int readFlag;

    while(1)
    {
        readFlag = read(fileDescriptorPara, buffer, BUFFERSIZE);
        if (readFlag == 0) { break; }
        else 
        {
            buffer[BUFFERSIZE] = '\0';
            printf("%s \n", buffer);
        }
    }
}



int main(int argc, char** argv)
{   
    int serverfd, confd, PORT, clientlen;
    struct sockaddr_in clientSocket;

    PORT = atoi(argv[1]);
    serverfd = getserverfd(PORT);


    char buffer[BUFFERSIZE + 1];
    
    char c;


    int* confdPointer;
 
    while(1)
    {
        clientlen = sizeof(clientSocket);

        // For each client, we need to address them a new confd, so what we can to is to initiate a new confd each time.
        int confd = accept(serverfd, (SA* )&clientSocket, &clientlen);
        printf("client with fd %d is connected\n", confd);
      
        //This is wrong since the &confd that is used inside the pthread_create might be the address of the next round confd.
        pthread_t newTid;
        pthread_create(&newTid, NULL, (void* )&hugeWrite, &confd);
        
        // The following join is not required. Recall previously when we call join is for the main thread to end as the last thread. Now main thread forever loops, so all the thread will be executed. No need pthread_join.
        //pthread_join(newTid, NULL);

        printf("%s \n", "test str"); 
    }
    close(serverfd);
}
