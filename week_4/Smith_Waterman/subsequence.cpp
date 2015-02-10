#include <iostream>
#include <algorithm>
using std::cout;
using std::string;
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




