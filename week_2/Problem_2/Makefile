FLAGS = -std=c++11 -Wall -pedantic -O2

# <Name Of Output File>: <Other Files that the file depends on> \
	<Command to compile the output file>

main: main.o
	g++ $(FLAGS) -o main main.o

main.o: main.cpp heapsort.h
	g++ $(FLAGS) -c main.cpp
