FLAGS = -std=c++11 -Wall -pedantic

# <Name Of Output File>: <Other Files that the file depends on> \
	<Command to compile the output file>

main: main.o huffman.o
	g++ $(FLAGS) -o main main.o huffman.o

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

huffman.o: huffman.cpp
	g++ $(FLAGS) -c huffman.cpp
