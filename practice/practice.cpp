#include <iostream>
#include <string>

using std::cout;

class Foo {
	int a;
	int *b;
	std::string s;
public:

	//Initialization lists 

	// This is a default constructor
	Foo():a(0),b(nullptr),s("") {} 
	Foo(int i):a(i),b(nullptr),s("") {}

	// This is a copy constructor
	// The parameter needs to be a const reference
	Foo(const Foo &f):a(f.a), b(nullptr), s(f.s) { 
		cout << "made a copy\n";
		if (f.b != nullptr) {
			b = new int;
			*b = *(f.b);
		} else b = nullptr;
	}

	// This is also a copy constructor when you use = (Assignments)
	const Foo &operator=(const Foo &f) {
		if (&f == this) return f;
		if (b != nullptr) delete b;
		a = f.a;
		if (f.b != nullptr) {
			b = new int;
			*b = *(f.b);
		} else b = nullptr;
		s = f.s;
	}

	//Move constructor
	//&&f is an rvalue reference
	//std::move() the thing that you pass in you cannot use anymore
	//Basically a copy constructor but it moves the memory from one object to the other
	Foo(Foo &&f):a(f.a), b(f.b), s(std::move(f.s)) {
		f.b = nullptr;
	}

	//Foo(const Foo &f) = default; This is rather redundant, if you don't define one,
	//The default constructor is already used

	//This is a copy constructor that prevents the use of a copy constructor
	//Foo(const Foo &f) = delete;

	// This is a destructor (Usually use it to free any resources)
	~Foo() {
		delete b;
	}

};

int main(int argc, char* argv[]) {

	cout << "This is a template of a program in c++" << "\n";
	
	Foo f;
	
	return 0;
}
