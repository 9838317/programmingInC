#!/bin/sh

rm ser;
rm cli;
rm textser;

gcc 6loopServer.c -ll2net -llas -o ser;
gcc 5loopClient.c -ll2net -llas -o cli;
gcc echoserveri.c -ll2net -llas -o textser;