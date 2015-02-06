FLAGS = -std=c++11 -Wall -pedantic -Ofast

# <Name Of Output File>: <Other Files that the file depends on> \
	<Command to compile the output file>

main: main.o anything.o
	g++ $(FLAGS) -o main main.o anything.o

anything.o: anything.cpp
	g++ $(FLAGS) -c anything.cpp

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp
