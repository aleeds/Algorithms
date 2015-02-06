#include <iostream>
#include <vector>
#include <math.h>

using std::cout;
using std::cin;
using std::vector;

template<typename T, typename K>
void countingSort(T begin, T end, K keyFunc, int i, int mask, int size) {
	vector<int> counts(size, 0);
	for (T b = begin; b != end; ++b) {	
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
/*
	cout << "\n=================COUNTS=================\n";
	for (auto itr = counts.begin(); itr != counts.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "\n========================================\n";
*/

	int curIndex = end - begin - 1;
	//cout << "\nCUR INDEX: " << curIndex << "\n";
	auto curPtr = end - 1;
	while (curPtr > begin - 1) {
/*
	cout << "\n================= BARR ====================\n";
	for (auto itr = begin; itr != end; ++itr) {
		cout << *itr << " ";
	}
	cout << "\nCUR INDEX: " << curIndex << "\n";
	cout << "\nCUR PTR: " << *curPtr << "\n";
	cout << "\n========================================\n";
*/
		int key = keyFunc(*curPtr);
		int curVal = key >> i; 
		curVal = curVal & mask;
		int ctsIndex = counts[curVal];	 
		//if (curIndex == ctsIndex - 1) {
		if (*(curPtr - 1) == *curPtr) {
			while (*(curPtr - 1) != *curPtr) { 
				--curPtr;
				--curIndex;
			}
			--curPtr;
			--curIndex;
		} else  if (curIndex == ctsIndex) {
/*
			cout << "\n MOVING CUTPTR LEFT \n";
			cout << "\n========================================\n";
			cout << "\nCUR INDEX: " << curIndex << "\n";
			cout << "\nCUR PTR: " << *curPtr << "\n";
			cout << "\n========================================\n";
*/
			--curPtr;
			--curIndex;
			//--counts[curVal];
		} else {
			if (ctsIndex != 0) {
				T origPtr = begin + (ctsIndex-1);
				auto temp = *curPtr;
				*curPtr = *origPtr;
				*origPtr = temp;
				--counts[curVal];
				//--counts[curVal];
			}
		} 
/*
	cout << "\n================= AARR ====================\n";
	for (auto itr = begin; itr != end; ++itr) {
		cout << *itr << " ";
	}
	cout << "\nCUR INDEX: " << curIndex << "\n";
	cout << "\nCUR PTR: " << *curPtr << "\n";
	int a;
	cin >> a;
	cout << "\n========================================\n";
*/
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
	//for (int i = 0; i < 2; ++i)  {
		//countingSort(begin, end, keyFunc, i*(msb/2), mask, pow(2,msb/2)); 
		countingSort(begin, end, keyFunc, 0, 0xff, 256); 
	//}
}
