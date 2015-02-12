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

bool canWin(const vector<vector<bool>> &baord);

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
	cout << "====================== PEG PROBLEM =====================" << "\n";
	cout << "==================== STARTING TESTS ====================" << "\n";
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
/*
void printBoard(vector<vector<bool>> board) {
	for (int i = 0; 
}
*/

void test1() {
	vector<vector<bool>> board(3, vector<bool>(3, false));
	board[2][1] = true;
	board[2][2] = true;
	(canWin(board))? cout << "CAN WIN" << endl : cout << "CANNOT WIN" << endl;
}

void test2() {
	vector<vector<bool>> board(3, vector<bool>(3, false));
	board[2][1] = true;
	board[2][2] = true;
	board[1][1] = true;
	board[1][2] = true;
	(canWin(board))? cout << "CAN WIN" << endl : cout << "CANNOT WIN" << endl;
}

void test3() {
	vector<vector<bool>> board(3, vector<bool>(3, false));
	board[2][1] = true;
	board[2][2] = true;
	board[1][1] = true;
	board[1][2] = true;
	board[0][0] = true;
	(canWin(board))? cout << "CAN WIN" << endl : cout << "CANNOT WIN" << endl;
}

void test4() {
	vector<vector<bool>> board;
	vector<bool> row3(9, false);
	row3[3] = true;
	row3[4] = true;
	vector<bool> row4(9, false);
	row4[4] = true;
	row4[6] = true;
	vector<bool> row5(9, false);
	row5[2] = true;
	row5[3] = true;
	row5[5] = true;
	row5[6] = true;
	vector<bool> row6(9, false);
	row6[2] = true;
	row6[4] = true;
	vector<bool> row7(9, false);
	row7[4] = true;
	row7[5] = true;
	vector<bool> emptyRow(9, false);
	board.push_back(emptyRow);
	board.push_back(emptyRow);
	board.push_back(row3);
	board.push_back(row4);
	board.push_back(row5);
	board.push_back(row6);
	board.push_back(row7);
	board.push_back(emptyRow);
	board.push_back(emptyRow);
	(canWin(board))? cout << "CAN WIN" << endl : cout << "CANNOT WIN" << endl;
	cout << endl;
}

void test5() {
	cout << endl;
}

void test6() {
	cout << endl;
}
