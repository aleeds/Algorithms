FLAGS = -std=c++11 -Wall -pedantic -Ofast -funroll-loops

# <Name Of Output File>: <Other Files that the file depends on> \
	<Command to compile the output file>

main: main.o
	g++ $(FLAGS) -o main main.o

main.o: main.cpp radix.h
	g++ $(FLAGS) -c main.cpp
