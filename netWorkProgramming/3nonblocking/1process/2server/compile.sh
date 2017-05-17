#!/bin/sh

gcc 6a_loopServer.c -ll2net -llas -o 6a_loopServer;
gcc 6b_testForkServer.c -ll2net -llas -o 6b_testForkServer;
gcc 6c_sendFileServerNonBlocking.c -ll2net -llas -o 6c_sendFileServerNonBlocking;
