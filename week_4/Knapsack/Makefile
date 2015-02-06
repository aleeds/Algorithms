FLAGS = -std=c++11 -Wall -pedantic

# <Name Of Output File>: <Other Files that the file depends on> \
	<Command to compile the output file>

main: main.o knapsack.o
	g++ $(FLAGS) -o main main.o knapsack.o

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

knapsack.o: knapsack.cpp
	g++ $(FLAGS) -c knapsack.cpp
