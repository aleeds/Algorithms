#include <iostream>
#include <string>

using std::cout;

class Foo {
	int *b;
	std::string s;
public:
	int a;
	
	Foo operator+(Foo other) {
		return {other.a+a};
	}
	//Initialization lists 

	// This is a default constructor
	Foo():a(0),b(nullptr),s("") {} 
	Foo(int n):a(n),b(nullptr),s("") {}

	// This is a destructor (Usually use it to free any resources)
	~Foo() {
		delete b;
	}

};

int main(int argc, char* argv[]) {

	cout << "This is a template of a program in c++" << "\n";

	Foo a(1);
	Foo b(2);

	cout << (a+b).a << "\n";
	
	Foo f;
	
	return 0;
}
