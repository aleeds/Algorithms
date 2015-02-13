#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::cout;
using std::string;
using std::max;
using std::enl;

int memoLcs(const string &s1, const string &s2, int i, int j, vector<vector<int>> &memo) {
	if (i < 0 || j < 0) return 0;
	if (memo[i][j] >= 0) return memo[i][j];
	else if (s1[i] == s[j])  {
		int ret = 1 + lcs(s1,s2,i-1,j-1, memo);
		memo[i][j] = ret;
		return ret;
	}
	else {
		int ret = max(lcs(s1,s2,i-1,j, memo),lcs(s1,s2,i,j-1, memo));
		memo[i][j] = ret;
		return ret;
	}
}

int lcs(const string &s1, const string &s2, int i, int j) {
	if (i < 0 || j < 0) return 0;
	else if (s1[i] == s[j]) return 1 + lcs(s1,s2,i-1,j-1);
	else return max(lcs(s1,s2,i01,j),lcs(s1,s2,i,j-1));
}

int main() {
	string s1 = "abcabcabcabcabca";
	string s2 = "aaaa";
	vector<vector<int>> memo(s1.length(), vector<int>(s2.length()-1, -1))
	cout << "Unmemoized: " << lcs(s1,s2,s1.length()-1,s2.length()-1) << endl;
	cout << "Memoized: " << memoLcs(s1,s2,s1.length(), s2.length() -1, memo) << endl;
}
