#include <iostream>
#include <cstdlib>
#include "heapsort.h"
#include <vector>
#include <ctime>

using std::cout;
using std::vector;
using std::string;

#define endl "\n"

template<typename T>
void printVector(vector<T> v);

template<typename T>
bool isSorted(T begin, T end);

void test1();
void test2();
void test3();
void test4();

int main(int argc, char* argv[]) {

	cout << "==================================================" << "\n";
	cout << "==================== HEAPSORT ====================" << "\n";
	cout << "==================================================" << "\n";
  	clock_t begin = clock();
	test1();
  	clock_t end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "==================================================" << "\n";
  	begin = clock();
	test2();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "==================================================" << "\n";
  	begin = clock();
	test3();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "==================================================" << "\n";
  	begin = clock();
	test4();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "==================================================" << "\n";

	return 0;
}

//Print Vector prints out the vector in a readable format
template<typename T>
void printVector(vector<T> v) {
	cout << "Vector: ";	
	for (auto itr = v.begin(); itr != v.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
}

//Returns whether or not the collection specified by the iterators
//is sorted or not
template<typename T>
bool isSorted(T begin, T end) {
	for (T i = begin; i != end-1; ++i) {
	   if (*i > *(i+1))
         return false;
	}
	return true;
}

//Small int test
void test1() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "==================== SMALL INT TEST ====================" << "\n";
	cout << "========================================================" << "\n";
   vector<int> v{10,5,24,47,3,7,19,20,201,45,63,41}; 
	printVector(v);	
	heapsort(v.begin(), v.end());
	printVector(v);	
   if (isSorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}

//Small string test
void test2() {
	cout << endl;
	cout << "===========================================================" << "\n";
	cout << "==================== SMALL STRING TEST ====================" << "\n";
	cout << "===========================================================" << "\n";
	vector<string> v{"s","c","f","a","z","b","r","t","u"};
	printVector(v);	
	heapsort(v.begin(), v.end());
	printVector(v);	
   if (isSorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}

//Big Int Test
void test3() {
	cout << endl;
	cout << "======================================================" << "\n";
	cout << "==================== BIG INT TEST ====================" << "\n";
	cout << "======================================================" << "\n";
	srand(1);
	vector<int> v;
	for (int i = 0; i < 1000000; ++i) {
		v.push_back(rand() % 5000);
	}
	heapsort(v.begin(), v.end());
   if (isSorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}

//Big String Test
void test4() {
	cout << endl;
	cout << "=========================================================" << "\n";
	cout << "==================== BIG STRING TEST ====================" << "\n";
	cout << "=========================================================" << "\n";
	srand(1);
	vector<string> v;
	for (int i = 0; i < 3000000; ++i) {
		string s = "";
		int len = rand() % 10 + 1;
		for (int z = 0; z < len; z++) {
			int r = rand() % 26;
			char c = 65 + r;
			s += c;
		}
		v.push_back(s);
	}
	heapsort(v.begin(), v.end());
   if (isSorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}
