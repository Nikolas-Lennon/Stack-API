#
# makefile for stack project
#

CC = g++ -std=c++11 -Wall -Wextra -I.

all: fstack.x

fstack.x: tstack.h id.h fstack.cpp
	$(CC) -o fstack.x fstack.cpp

fstack.o: tstack.h id.h fstack.cpp
	$(CC) -c fstack.cpp
