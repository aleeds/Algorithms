#include <iostream>
#include <vector>
#include <math.h>

using std::cout;
using std::vector;

template<typename T, typename K>
void countingSort(T begin, T end, K keyFunc, int i, vector<typename T::value_type> cts, int mask, int size) {
	vector<int> counts(size, 0);
	for (T b = begin; b != end; ++b) {	
		auto v =  *b;
		cts.push_back(v);
		int key = keyFunc(*b);
		if (key == 0) {
			++counts[0];
		} 
		else {
			int curVal = key >> i; 
			curVal = curVal & mask;
			counts[curVal] += 1;
		}
	}
	auto countsEnd = counts.end();
	for (auto itr = counts.begin(); itr != countsEnd; ++itr) {	
		if (itr != counts.begin())
			*itr = *(itr-1) + *itr;
	}
	auto ctsEnd = cts.end();
	for (auto itr = ctsEnd - 1; itr != cts.begin() - 1; --itr) {
		int key = keyFunc(*itr);
		int curVal = key >> i; 
		curVal = curVal & mask;
		int ctsIndex = counts[curVal];	 
		if (ctsIndex != 0) {
			T origPtr = begin + (ctsIndex-1);
			*origPtr = (*itr);
			--counts[curVal];
		} 
	}
}


template<typename T, typename K>
int findMax(T begin, T end, K keyFunc) {
	auto max = keyFunc(*begin);
	for (auto itr = begin; itr != end; ++itr)	 {
		if (keyFunc(*itr) > max) {
			max = keyFunc(*itr);
		}
	}
	return max;
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {
	int max = findMax(begin, end, keyFunc);
	int msb = 1;
	while (max >>= 1) {
		 msb++;
	}
	if (msb % 2 != 0) {
		msb += 1;
	}
	int mask = 1;
	//cout << "MSB: " << msb << "\n";
	for (int x = (msb/2)-1; x > 0; --x) {
		mask += 1 << x ;
	}
	//cout << "MASK: " << mask << "\n";
	//Find the most significant bit
	vector<typename T::value_type> cts;
	for (int i = 0; i < 2; ++i)  {
		countingSort(begin, end, keyFunc, i*(msb/2), cts, mask, pow(2,(msb/2)));
	}
}
