#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using std::cout;
using std::vector;
using std::string;
using std::pair;

#define endl "\n"

template<typename T>
void printVector(vector<T> v);

template<typename T>
bool isSorted(T begin, T end);

pair<double,vector<int>> knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values);

void startTests();
void test1();
void test2();

int main(int argc, char* argv[]) {
	startTests();
	return 0;
}

void startTests() {
	cout << "========================================================" << "\n";
	cout << "=================== KNAPSACK PROBLEM ===================" << "\n";
	cout << "========================================================" << "\n";
	cout << "==================== STARTING TESTS ====================" << "\n";
	cout << "========================================================" << "\n";
  	clock_t begin = clock();
	test1();
  	clock_t end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "========================================================" << "\n";
  	begin = clock();
	test2();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "========================================================" << "\n";
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
	cout << "================= SMALL KNAPSACK TEST ==================" << "\n";
	cout << "========================================================" << "\n";
	int weightLimit = 5;
	const vector<int> weights{2,3,4,5};
	const vector<double> values{3,4,5,6};
	vector<int> sValues{0,2};
	vector<int> tValues{0,2};
	pair<double, vector<int>> solution(9.0, sValues);
	pair<double, vector<int>> result = knapsack(weightLimit, weights, values);
	(solution == result)? cout << "PASSED" << endl : cout << "FAILED" << endl;
}

//Big Int Test
void test2() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "==================== BIG KNAPSACK TEST =================" << "\n";
	cout << "========================================================" << "\n";
/*
	vector<int> v;
	for (int i = 0; i < 1000000; ++i) {
		v.push_back(rand() % 5000);
	}
   if (isSorted(v.begin(), v.end())) cout << "The collection is sorted" << endl;
   else cout << "The collection is NOT sorted" << endl;
	cout << endl;
*/
}

