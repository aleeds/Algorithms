#include <iostream>
#include <stdlib.h>

#define endl "\n"

using std::cout;

int numCells(double endTime, double minSplit, double maxSplit);
void testMinPriorityQueue();

void test1();
void test2();
void test3();
void test4();

int main(int argc, char* argv[]) {

	cout << "CELL DIVISION EVENT SIMULATION" << endl;

	test1();
	test2();
	test3();
	test4();

	//testMinPriorityQueue();
	
	return 0;
}

void test1() {
	cout << "The number of cells is: " << numCells(10, 1.0, 5.0) << endl;
}

void test2() {
	cout << "The number of cells is: " << numCells(3.0, 1.0, 1.0) << endl;
}
void test3() {
	cout << "The number of cells is: " << numCells(400, 5.0, 30.0) << endl;
}
void test4() {
	cout << "The number of cells is: " << numCells(10, 1.0, 5.0) << endl;
}
