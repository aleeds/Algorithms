#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

using std::cout;
using std::vector;
using std::string;
using std::pair;

#define endl "\n"

template<typename T>
void printVector(vector<T> v);

//Print Vector prints out the vector in a readable format
template<typename T>
void printVector(vector<T> v) {
	cout << "Vector: ";	
	for (auto itr = v.begin(); itr != v.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
}

template<typename T>
bool isSorted(T begin, T end);

pair<double,vector<int>> knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values);
double knapsackRecursive(int weightLimit, const vector<int> &weights, const vector<double> &values);

void startTests();
void test1();
void test2();
void test3();
void test4();
void test6();

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
  	begin = clock();
	test3();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "========================================================" << "\n";
  	begin = clock();
	test4();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "========================================================" << "\n";
  	begin = clock();
	test6();
  	end = clock();
  	cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "========================================================" << "\n";
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

double getMaxValue(vector<int> indexes, vector<double> values);
/*
	double getMaxValue(vector<int> indexes, vector<double> values) {
	double sum = 0;
	for (auto itr = indexes.begin(); itr != indexes.end(); ++itr) {
		sum += values[*itr]; 
	}
	return sum;
}
*/

bool indexesAddToMax(double maxValue, vector<int> indexes, vector<double> values) {
	double sum = 0;
	for (auto itr = indexes.begin(); itr != indexes.end(); ++itr) {
		sum += values[*itr]; 
	}
	return (sum == maxValue);
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
	vector<int> iValues{1,0};
	pair<double, vector<int>> solution(7, iValues);
	pair<double, vector<int>> result = knapsack(weightLimit, weights, values);
	cout << "Max Value: " << result.first << endl; 
	cout << "Values: [";
	for (auto itr = result.second.begin(); itr != result.second.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
	(solution == result)? cout << "PASSED" << endl : cout << "FAILED" << endl;
	(indexesAddToMax(result.first, result.second, values))? cout << "PASSED, ADD TO MAX" << endl : cout << "FAILED" << endl;
}

//Small int test
void test6() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "================= SMALL KNAPSACK TEST 2 ================" << "\n";
	cout << "========================================================" << "\n";
	int weightLimit = 4;
	const vector<int> weights{4,3,2,1,1};
	const vector<double> values{10,10,10,10,11};
	vector<int> iValues{4,3,2};
	pair<double, vector<int>> solution(31, iValues);
	pair<double, vector<int>> result = knapsack(weightLimit, weights, values);
	cout << "Max Value: " << result.first << endl; 
	cout << "Values: [";
	for (auto itr = result.second.begin(); itr != result.second.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
	(solution == result)? cout << "PASSED" << endl : cout << "FAILED" << endl;
	(indexesAddToMax(result.first, result.second, values))? cout << "PASSED, ADD TO MAX" << endl : cout << "FAILED" << endl;
}

//Big Int Test
void test2() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "==================== MED KNAPSACK TEST =================" << "\n";
	cout << "========================================================" << "\n";
	int weightLimit = 170;
	const vector<int> weights{41,50,49,59,55,57,60};
	const vector<double> values{442,525,511,593,546,564,617};
	vector<int> iValues{6,3,1};
	pair<double, vector<int>> solution(1735, iValues);
	pair<double, vector<int>> result = knapsack(weightLimit, weights, values);
	cout << "Max Value: " << result.first << endl; 
	cout << "Values: [";
	for (auto itr = result.second.begin(); itr != result.second.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
	(solution == result)? cout << "PASSED" << endl : cout << "FAILED" << endl;
	(indexesAddToMax(result.first, result.second, values))? cout << "PASSED, ADD TO MAX" << endl : cout << "FAILED" << endl;
}

//Big Int Test
void test3() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "==================== MED KNAPSACK TEST =================" << "\n";
	cout << "========================================================" << "\n";
	int weightLimit = 750;
	const vector<int> weights{70,73,77,80,82,87,90,94,98,106,110,113,115,118,120};
	const vector<double> values{135,139,149,150,156,163,173,184,192,201,210,214,221,229,240};
	vector<int> iValues{14,13,8,7,6,4,2,0};
	pair<double, vector<int>> solution(1458, iValues);
	pair<double, vector<int>> result = knapsack(weightLimit, weights, values);
	cout << "Max Value: " << result.first << endl; 
	cout << "Values: [";
	for (auto itr = result.second.begin(); itr != result.second.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
	(solution == result)? cout << "PASSED" << endl : cout << "FAILED" << endl;
	(indexesAddToMax(result.first, result.second, values))? cout << "PASSED, ADD TO MAX" << endl : cout << "FAILED" << endl;
}


//Big Int Test
void test4() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "=================== RAND KNAPSACK TEST =================" << "\n";
	cout << "========================================================" << "\n";
	int weightLimit = 5000;
	vector<int> weights;
	vector<double> values;
	for (int i = 0; i < 8000; ++i) {
		int tempWeight = rand() % 500;
		double tempValue = rand() % 90000 + (double)rand()/RAND_MAX;
		weights.push_back(tempWeight); 
		values.push_back(tempValue);
	}
	//vector<int> iValues{0,1,3,4,5,9,10,12,15,21,22,23};
	//std::reverse(iValues.begin(), iValues.end());
	//pair<double, vector<int>> solution(13549094, iValues); 
	pair<double, vector<int>> result = knapsack(weightLimit, weights, values);
	cout << "Max Value: " << result.first << endl; 
	cout << "Indices: [";
	for (auto itr = result.second.begin(); itr != result.second.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
	//(solution == result)? cout << "PASSED" << endl : cout << "FAILED" << endl;
	//((double)result.first == (double)getMaxValue(result.second, values))? cout << "PASSED, ADD TO MAX" << endl : cout << "FAILED" << endl;
	double r = (double)result.first;
	cout << "Max Value Computed from Knapsack: " << r << endl;
	double m = (double)getMaxValue(result.second, values);
	cout << "Max Value Computed from Indices: " << m << endl;
	//((double)result.first == (double)getMaxValue(result.second, values))? cout << "PASSED, ADD TO MAX" << endl : cout << "FAILED" << endl;
	if (m == r) cout << "PASSED" << endl;
	else cout << "FAILED" << endl;
}

//Big Int Test
void test5() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "==================== BIG KNAPSACK TEST =================" << "\n";
	cout << "========================================================" << "\n";
	int weightLimit = 6404180;
	const vector<int> weights{382745, 799601, 909247, 729069, 467902, 44328, 34610, 698150, 823460, 903959, 853665, 551830, 610856, 670702, 488960, 951111, 323046, 446298, 931161, 31385, 496951, 264724, 224916, 169684};
	const vector<double> values{825594, 1677009, 1676628, 1523970, 943972, 97426, 69666, 1296457, 1679693, 1902996, 1844992, 1049289, 1252836, 1319836, 953277, 2067538, 675367, 853655, 1826027, 65731, 901489, 577243, 466257, 369261};
	vector<int> iValues{0,1,3,4,5,9,10,12,15,21,22,23};
	std::reverse(iValues.begin(), iValues.end());
	pair<double, vector<int>> solution(13549094, iValues); 
	pair<double, vector<int>> result = knapsack(weightLimit, weights, values);
	cout << "Max Value: " << result.first << endl; 
	cout << "Values: [";
	for (auto itr = result.second.begin(); itr != result.second.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
	(solution == result)? cout << "PASSED" << endl : cout << "FAILED" << endl;
	(indexesAddToMax(result.first, result.second, values))? cout << "PASSED, ADD TO MAX" << endl : cout << "FAILED" << endl;
}
