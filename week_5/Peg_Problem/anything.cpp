#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

#define D 1
#define L 2
#define U 3
#define R 4


bool lookup(const vector<vector<bool>> &board, int i, int j) {
	return ((i >= 0 && j >= 0) &&  (i < board.size() && j < board[i].size()) && board[i][j]);
}

//Use Move Constructor
vector<vector<bool>> makeBoard(vector<vector<bool>> board, int i, int j, int dir) {
	switch(dir)	 {
		case D:
			board[i+1][j] = false;
			board[i+2][j] = false;
			board[i][j] = true;
			return board;
			break;
		case L:
			board[i][j-2] = false;
			board[i][j-2] = false;
			board[i][j] = true;
			return board;
			break;
		case U:
			board[i-1][j] = false;
			board[i-2][j] = false;
			board[i][j] = true;
			return board;
			break;
		case R:
			board[i][j+1] = false;
			board[i][j+2] = false;
			board[i][j] = true;
			return board;
			break;
		default:
			break;
	}
}

vector<vector<vector<bool>>> allBoards(const vector<vector<bool>> &board, int i, int j) {
	vector<vector<vector<bool>>> myBoards;
	if (lookup(board,i-1,j) && lookup(board, i-2,j)) myBoards.push_back(makeBoard(board, i, j, U));
	if (lookup(board,i,j+1) && lookup(board, i,j+2)) myBoards.push_back(makeBoard(board, i, j, R));
	if (lookup(board,i+1, j) && lookup(board, i+2,j)) myBoards.push_back(makeBoard(board, i, j, D));
	if (lookup(board,i,j-1) && lookup(board, i,j-2)) myBoards.push_back(makeBoard(board, i, j, L));
	return myBoards;
}

bool onePeg(const vector<vector<bool>> &board) {
	int count = 0;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j]) {
				++count;	
				if (count > 1) return false;
			}	
		}
	}
	return true;
}

int computeHash(const vector<vector<bool>> &board) {
	unsigned int n = 0;
	unsigned int key = 0;
	for (int i = 0; i < board.size(); ++i)	 {
		for (int j = 0; j < board[i].size(); ++j)	 {
			if (board[i][j]) {
				key |= 1 << n;
			}
			++n;
		}
	}
	return key;
}

bool canWinHelper(const vector<vector<bool>> &board, unordered_map<int,bool> &bMap) {
	//Lookup in the table and see if it the board is winnable
	if (onePeg(board)) return true;
	else {
		//Recurse on each item that can jump
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (!board[i][j]) {
					auto boards = allBoards(board,i,j);
					for (auto q : boards) {
						//If the board has already been solved, return the solution
						int key = computeHash(q);
						if (bMap.count(key) > 0) {
							return bMap[key];
						} else {
							bool res = canWinHelper(q, bMap);
							bMap[key] = res;
							if(res) {
								return true;
							}
						}
					}
				}	
			}
		}
		return false;
	}
}

bool canWin(const vector<vector<bool>> &board) {
	unordered_map<int,bool> bMap;
	return canWinHelper(board, bMap);
}
