#include <iostream>
#include <cstdlib>
#include "radix.h"
#include <vector>
#include <ctime>
#include <algorithm>

using std::cout;
using std::vector;
using std::string;
using std::is_sorted;

#define endl "\n"

template<typename T>
void printVector(vector<T> v);

template<typename T>
bool isSorted(T begin, T end);

//template<typename T, typename K>
//void radixSort(T begin, T end, K keyFunc);

void startTests();
void testCountingSort();
void test1();
void test2();
void test3();
void test4();

int main(int argc, char* argv[]) {

	startTests();
	//testCountingSort();

	return 0;
}

void testCountingSort() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "================== COUNTING SORT TEST ==================" << "\n";
	cout << "========================================================" << "\n";
   vector<int> v{1,5,2,4,3,7,9,6,10,8}; 
	printVector(v);	
	vector<int> cts(v.end() - v.begin());
	//countingSort(v.begin(), v.end(), [](int x) { return x; }, 0, cts.begin(), cts.end());
	printVector(cts);	
   if (isSorted(cts.begin(), cts.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}

void startTests() {
	cout << "==================================================" << "\n";
	cout << "=================== RADIX SORT ===================" << "\n";
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
	cout << "==================================================" << "\n";
  	begin = clock();
	test3();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "==================================================" << "\n";
	cout << "==================================================" << "\n";
  	begin = clock();
	test4();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "==================================================" << "\n";
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
	cout << "==================== SMALL DOUBLE TEST =================" << "\n";
	cout << "========================================================" << "\n";
   //vector<int> v{10,5,24,47,3,7,19,20,201,45,63,41}; 
   vector<int> v{1,3,5,2,4,3,7,9,8,10,6}; 
	printVector(v);	
	radixSort(v.begin(), v.end(), [](int x) { return (double)x; });
	printVector(v);	
   if (isSorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}

//Big Int Test
void test2() {
	cout << endl;
	cout << "======================================================" << "\n";
	cout << "================== MEDIUM DOUBLE TEST ================" << "\n";
	cout << "======================================================" << "\n";
	//srand(25);
	srand(1);
	vector<int> v;
	for (int i = 0; i < 100; ++i) {
		v.push_back(rand() % 50);
	}
	radixSort(v.begin(), v.end(), [](int x) { return (double)x; });
   if (is_sorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}
//Big Int Test
void test3() {
	cout << endl;
	cout << "======================================================" << "\n";
	cout << "==================== BIG DOUBLE TEST ===================" << "\n";
	cout << "======================================================" << "\n";
	//srand(25);
	srand(1);
	vector<int> v;
	for (int i = 0; i < 10000000; ++i) {
		v.push_back(rand() % 50000);
	}
	radixSort(v.begin(), v.end(), [](int x) { return (double)x; });
   if (is_sorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}

void test4() {
	cout << endl;
	cout << "======================================================" << "\n";
	cout << "==================== BIG INT TEST ====================" << "\n";
	cout << "======================================================" << "\n";
	//srand(25);
	srand(1);
	vector<int> v;
	for (int i = 0; i < 10000000; ++i) {
		v.push_back(rand() % 5000000);
	}
	radixSort(v.begin(), v.end(), [](int x) { return (double)x; });
   if (is_sorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
}


