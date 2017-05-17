#!/bin/sh

rm ser;
rm cli;
rm textser;

gcc 6loopServer.c -ll2net -llas -o ser;
gcc 5loopClient.c -ll2net -llas -o cli;
gcc test5loopClient.c -ll2net -llas -o test5loopClient;
gcc userfriendlyClient.c -ll2net -llas -o  userfriendlyClient
gcc test6loopServer.c -ll2net -llas -o test6loopServer