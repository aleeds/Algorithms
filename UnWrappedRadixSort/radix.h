#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

template<typename T, typename K>
void countingSort(T begin, T end, K keyFunc, int i, vector<typename T::value_type> lunchbox) {

	vector<int> counts(256,0);

	for (T b = begin; b != end; ++b) {	
		int key = keyFunc(*b);
		if (key == 0) {
			++counts[0];
			lunchbox.push_back(*b);
		} 
		else {
			int curVal = key >> i; 
			curVal = curVal & 0xff;
			lunchbox.push_back(*b);
			counts[curVal] += 1;
		}
	}
	//Make Cumulative
	for (auto itr = counts.begin(); itr != counts.end(); ++itr) {	
		if (itr != counts.begin())
			*itr = *(itr-1) + *itr;
	}
	for (auto itr = lunchbox.end() - 1; itr != lunchbox.begin() - 1; --itr) {
		int key = keyFunc(*itr);
		int curVal = key >> i; 
		curVal = curVal & 0xff;
		int ctsIndex = counts[curVal];	 
		if (ctsIndex != 0) {
			T origPtr = begin + (ctsIndex-1);
			*origPtr = (*itr);
			--counts[curVal];
		} 
	}
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {

	vector<typename T::value_type> lunchbox;	

	for (int i = 0; i < 4; ++i)  {
		countingSort(begin, end, keyFunc, i*8, lunchbox); 
	}
}
