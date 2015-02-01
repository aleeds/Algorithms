#include <iostream>
#include <vector>

using std::cout;
using std::vector;

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

template<typename T, typename K>
bool countingSort(T begin, T end, K keyFunc, int i, vector<wrapper<typename T::value_type>> wrappers) {
	bool changed = false;
	vector<int> counts(256, 0);
	for (T b = begin; b != end; ++b) {	
		int key = keyFunc(*b);
		if (key == 0) {
			++counts[0];
			wrapper<typename T::value_type> w(*b, key);
			wrappers.push_back(w);
		} 
		else {
			changed = true;
			int curVal = key >> i; 
			curVal = curVal & 0xff;
			wrapper<typename T::value_type> w(*b, key);
			wrappers.push_back(w);
			counts[curVal] += 1;
		}
	}
	if (!changed)
		return false;
	//Make Cumulative
	for (auto itr = counts.begin(); itr != counts.end(); ++itr) {	
		if (itr != counts.begin())
			*itr = *(itr-1) + *itr;
	}
	for (auto itr = wrappers.end() - 1; itr != wrappers.begin() - 1; --itr) {
		int key = (*itr).keyValue;
		int curVal = key >> i; 
		curVal = curVal & 0xff;
		int ctsIndex = counts[curVal];	 
		if (ctsIndex != 0) {
			T origPtr = begin + (ctsIndex-1);
			*origPtr = (*itr).origValue;
			--counts[curVal];
		} 
	}
	return changed;
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {

	vector<wrapper<typename T::value_type>> wrappers;

	for (int i = 0; i < 4; ++i)  {
		bool changedValue = countingSort(begin, end, keyFunc, i*8, wrappers); 
		if (!changedValue)
			return;
	}
}
