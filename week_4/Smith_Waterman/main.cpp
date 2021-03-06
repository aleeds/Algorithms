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
#define DIAGNOSTIC_LEVEL 0

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


int matchingBases(string strand);

int recursiveMatches(string strand);

void startTests();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main(int argc, char* argv[]) {
	startTests();
	return 0;
}

void startTests() {
	cout << "========================================================" << "\n";
	cout << "================== SUBSEQUENCE PROBLEM =================" << "\n";
	cout << "========================================================" << "\n";
	cout << "==================== STARTING TESTS ====================" << "\n";
	cout << "========================================================" << "\n";
  	clock_t begin = clock();
  	clock_t end = clock();
	switch(DIAGNOSTIC_LEVEL) {
		case 1:
			begin = clock();
			test1();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			break;
		case 2:
			begin = clock();
			test2();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			break;
		case 3:
			begin = clock();
			test3();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			break;
		case 4:
			begin = clock();
			test4();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			break;
		case 5:
			begin = clock();
			test5();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			break;
		case 6:
			begin = clock();
			test6();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			break;
		default:
			begin = clock();
			test1();
			end = clock();
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
			test5();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			begin = clock();
			test6();
			end = clock();
			cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
			cout << "========================================================" << "\n";
			break;
	}
}

void test1() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";

	int result = matchingBases("CCACUGAACAGUG"); 
	
	cout << "MATCHING BASES: ";
	(result == 5) ? cout << "PASSED" << endl : cout <<"FAILED, " << " Result:  " << result << endl;

	result = recursiveMatches("CCACUGAACAGUG"); 
	cout << "RECURSIVE MATCHING BASES: ";
	(result == 5) ? cout << "PASSED" << endl : cout <<"FAILED, " << " Result: " << result << endl;


}

void test2() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	int result = matchingBases("ACGUGCCACGAUUCAACGUGGCACAG");
	cout << "MATCHING BASES: ";
	(result == 11) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result <<  endl;

	result = recursiveMatches("ACGUGCCACGAUUCAACGUGGCACAG");
	cout << "RECURSIVE MATCHING BASES: ";
	(result == 11) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result << endl;
}

void test3() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	int result = matchingBases("CACAGUGACAC");
	cout << "MATCHING BASES: ";
	(result == 3) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result <<  endl;

	result = recursiveMatches("CACAGUGACAC");
	cout << "RECURSIVE MATCHING BASES: ";
	(result == 3) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result << endl;
}

void test4() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	int result = matchingBases("CACUGUCAGUCAGUCCCAAACCGGUUCCUUGGAA");
	cout << "MATCHING BASES: ";
	(result == 10) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result <<  endl;

	result = recursiveMatches("CACUGUCAGUCAGUCCCAAACCGGUUCCUUGGAA");
	cout << "RECURSIVE MATCHING BASES: ";
	(result == 10) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result << endl;
}

void test5() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	int result = matchingBases("AGAGAGAGAGAGAAGAGAGAGGAGAGAGAGAGAAGUCUCUCUCUCUCUCUCUCUC");
	cout << "MATCHING BASES: ";
	(result == 20) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result <<  endl;

	result = recursiveMatches("AGAGAGAGAGAGAAGAGAGAGGAGAGAGAGAGAAGUCUCUCUCUCUCUCUCUCUC");
	cout << "RECURSIVE MATCHING BASES: ";
	(result == 20) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result << endl;
}

void test6() {
	cout << endl;
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	cout << "========================================================" << "\n";
	int result = matchingBases("CACUCCUUGGGCAGUUGAUCUACUACUACUACUACUACUACUACUUUUGGAGCGAUUCU");
	cout << "MATCHING BASES: ";
	(result == 17) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result <<  endl;

	result = recursiveMatches("CACUCCUUGGGCAGUUGAUCUACUACUACUACUACUACUACUACUUUUGGAGCGAUUCU");
	cout << "RECURSIVE MATCHING BASES: ";
	(result == 17) ? cout << "PASSED" << endl : cout << "FAILED, " <<  "Result: " << result << endl;
}
