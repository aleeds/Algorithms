#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void HCR() {
  char JunkString[255];

// cin.flush();
  cout << " <Hit Carriage Return To Continue>\n";
  cin.getline(JunkString,255);
}

template<typename T> 
T getPtrFromIndex(T begin, int i) {
	return (begin + (i-1));
}

template<typename T>
struct wrapper {
	T origValue;	
	int keyValue;
	wrapper() {}
	wrapper(T p, int v) {
		origValue = p;
		keyValue = v;
	}
};

template<typename T, typename K, typename C>
void countingSort(T begin, T end, K keyFunc, int i, C ctsbegin, vector<wrapper<typename T::value_type>> &wrappers) { 
	//Create a vector with the count of each element in the original vector
	vector<int> counts(256);
	if (i == 0) {
		for (T b = begin; b != end; ++b) {	
			wrapper<typename T::value_type> w(*b, keyFunc(*b));
			wrappers.push_back(w);
			int curVal = w.keyValue >> i; 
			curVal = curVal & 0xff;
			//cout << "Val: " << *b << "\n";
			//cout << "Cur Val: " << curVal << "\n";
			//HCR();
			++counts[curVal];
		}
	}
	else {
		for (auto w = wrappers.begin(); w != wrappers.end(); ++w) {	
			int curVal = w->keyValue >> i; 
			curVal = curVal & 0xff;
			++counts[curVal];
		}
	}

	cout << "=================================================\n";	
	cout << "Counts: [";
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
	//Make it cumulative
	//*(counts.begin()) -= 1;
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		*itr = *(itr-1) + *itr;
	}
	cout << "=================================================\n";	
	cout << "Cummulative?\n";
	cout << "Counts: [";
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
	cout << "=================================================\n";	
	cout << "CTS\n";
	for (int i = 0; i < (end - begin); ++i)  {
		cout << *(ctsbegin+(i-1)) << " ";
	}
	cout << "=================================================\n";	
	HCR();
	//for (T itr = end - 1; itr != begin - 1; --itr) {
	for (auto itr = wrappers.end() - 1; itr != wrappers.begin() - 1; --itr) {
		//Gets cts index from counts
		int ctsIndex = counts[(*itr).keyValue] - 1;	 
		//REPLACE THIS!!
		T curPtr = getPtrFromIndex(ctsbegin, ctsIndex);
		*curPtr = itr->origValue;
		//--counts[keyFunc(*itr)];
		--counts[(*itr).keyValue];
	}
	cout << "=================================================\n";	
	cout << "CTS\n";
	for (int i = 0; i < (end - begin); ++i)  {
		cout << *(ctsbegin+(i-1)) << " ";
	}
	cout << "=================================================\n";	
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {

	vector<typename T::value_type> cts(end-begin);	
	vector<wrapper<typename T::value_type>> wrappers;
	for (int i = 0; i < 4; ++i)  {
		countingSort(begin, end, keyFunc, i*8, cts.begin(), wrappers); 
		auto cItr = cts.begin();
		T itr = begin;
		while (itr != end) {
			*itr = *cItr;
			++itr;
			++cItr;
		}
	}
}
