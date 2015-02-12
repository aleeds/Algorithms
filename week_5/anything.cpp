#include <vector>

using std::vector;

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


bool canWinHelper(const vector<vector<bool>> &board) {
	if (onePeg(board)) return true;
	else {
		//Recurse on each item that can jump
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (!board[i][j]) {
					auto boards = allBoards(board,i,j);
					for (auto q : boards) {
						if (canWinHelper(q)) {
							return true;
						}
					}
				}	
			}
		}
		return false;
	}
}

bool canWin(const vector<vector<bool>> &board) {
	return canWinHelper(board);
}
