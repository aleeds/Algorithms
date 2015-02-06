#include <iostream>
#include "order.h"

using std::cout;
using std::vector;

void test1(int index);
void test2(int index);

struct cmp {
	int operator() (int i, int j) const {
		if (i <= j) {
			return -1;
		}
		else {
			return 1;
		}
	}
};

int main(int argc, char* argv[]) {

	cmp compareFunc;

	vector<int> v{5,4,7,6,9,8};

	int x = findMin<int, cmp>(v, 2, compareFunc);
	
	cout << "The min value is: " << x << "\n";

	test1(1);
	test1(2);
	test1(3);
	test1(4);
	test1(5);
	test1(6);
	test1(7);
	test1(8);

	test2(1);
	test2(2);
	test2(3);
	test2(4);
	test2(5);
	test2(8);
	
	return 0;
}

//Without lambda
void test1(int index) {

	cout << "\n==================  Diagnostic Level 1 ===================\n";

	vector<int> v{2,5,1,4,7,6,9,8};

	cmp compareFunc;

	int x = findNth<int, cmp>(v, index, compareFunc);

	cout << "The " << index << " value is " << x << "\n";

	cout << "The Vector contains: ";

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
 	cout << "\n";

}

//With Lambdas
void test2(int index) {

	cout << "\n==================  Diagnostic Level 2 ===================\n";

	vector<int> v{2,5,1,4,7,6,9,8};
	
	int x = findNth<int>(v, index, [](int i, int j) { return i - j; });

	cout << "The " << index << " value is " << x << "\n";
}
