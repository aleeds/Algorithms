#include <iostream>
#include <algorithm>
using std::cout;
using std::string;
using std::vector;
//using std::reverse;
using std::endl;



string reverse (string s) { 
	string result=""; //create a new string and set it to the empty string 

	for (int i=0; i<s.length( ) ; i++) { //s.length( ) returns the length of a string 
	result = s[ i ] + result ; //take the newest character and add it before what we have already
} 
return result; 
}

int match_count(string left, string right) {

	int count = 0;
	for (int i = 0; i < std::min(left.length(), right.length()); ++i) {
		if (left[i] == 'A' && right[i] == 'U' ||
			left[i] == 'U' && right[i] == 'A' ||
			left[i] == 'C' && right[i] == 'G' ||
			left[i] == 'G' && right[i] == 'C') 
			++count; 
	}
	return count;
}

int matchingBases(string strand) {
	int length = strand.length();


	return length;
}

int recursiveMatches(string strand) {
	int length = strand.length();
	int max = 0;


	for (int i = 0; i < length - 1; ++i) {
		string left  = reverse(strand.substr(0,i)); // reversal of the first part of the string

		string right = strand.substr(i, left.length());
		string right2 = strand.substr(i+1, left.length());

		cout << left << " " << right << endl;
		int count = match_count(left, right);
		cout << count << endl;


		if (max < count)
			max = count;

		cout << left << " " << right2 << endl;
		count = match_count(left, right2);

		cout << count << endl;

		if (max < count)
			max = count;
	}

	return max;
}

int lcs(const string &s1, const string &s2, int m, int n) {
	if (m<0 || n<0) return 0;
	if (s1[m]==s2[n]) return 1+lcs(s1,s2,m-1,n-1);
	else return std::max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
}

int lookup(const vector<vector<int>> &t, int i, int j) {
	if (i<0 || j<0) return 0;
	else return t[i][j];
}

int lcsDP(const string &s1, const string &s2, int m, int n) {
	vector<vector<int>> t(s1.length(), vector<int>(s2.length()));
	for (int i = 0; i < s1.length(); ++i) {
		for (int j = 0; j < s2.length(); ++j) {
			if (s1[i]==s2[j]) t[i][j] = lookup(t,i-1,j-1)+1;
			else t[i][j] = std::max(lookup(t,i-1,j),lookup(t,i,j-1));
		}
	}
	return t[s1.length()-1][s2.length()-1];
}

