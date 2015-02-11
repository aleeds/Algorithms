#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;
using std::endl;

void printVV(vector<vector<int>> t) {
      cout << "\n";
   for (int i = 0; i < t[0].size(); ++i)  {
      for (int j = 0; j < t.size(); ++j) {
         cout << t[j][i] << " ";
      }
      cout << "\n";
   }
}

int myMax(const int &a1, const int &a2) {
	return ((a1 >= a2)? a1: a2);
}

int lookup(const vector<vector<int>> &t, const int &i, const int &j) {
	return (i<0 || j<0 || i >= t.size() || j >= t.size())? 0 : t[i][j];
}

bool equalProteins(const char &c1, const char &c2) {
		return (c1 + c2 == 150 || c1 + c2 == 138);
}

int matchingBases(string strand) {
	int len = strand.length();
	vector<vector<int>> t(len, vector<int>(len));
	int max = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = len-1; j >= i; --j) {
			if ((strand[i]+strand[j] == 150) || (strand[i] + strand[j] == 138)) t[i][j] = lookup(t,i-1,j+1)+1;
			else t[i][j] = myMax(lookup(t,i,j+1),lookup(t,i - 1,j));
			if (max < t[i][j]) max = t[i][j]; 
		}
	}
	return max;
}

int rMH(string s, int i, int j) {
	//cout << "i: " << i << " j: " << j << endl;
	if (i >= j) return 0;
	else if (equalProteins(s[i],s[j])) return 1 + rMH(s, i +1, j -1);
	else return std::max(rMH(s, i,j-1), rMH(s, i+1,j));
}

int recursiveMatches(string strand) {
	int l = strand.length();
	int i = 0;
	int j = l-1;
	return rMH(strand, i, j);
}
