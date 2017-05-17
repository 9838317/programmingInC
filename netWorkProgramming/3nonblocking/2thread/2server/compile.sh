#!/bin/sh

gcc 1cannotForeverWrite.c -ll2net -llas -o 1cannotForeverWrite;
gcc 2usingFileToBlock.c -ll2net -llas -o 2usingFileToBlock;
gcc 3threadServerRace.c -ll2net -llas -lpthread -o 3threadServerRace;
gcc 4threadServerNoRace.c -ll2net -llas -lpthread -o 4threadServerNoRace;