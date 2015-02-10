FLAGS = -std=c++11 -Wall -pedantic -Ofast

# <Name Of Output File>: <Other Files that the file depends on> \
	<Command to compile the output file>

main: main.o subsequence.o
	g++ $(FLAGS) -o main main.o subsequence.o

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

subsequence.o: subsequence.cpp
	g++ $(FLAGS) -c subsequence.cpp

