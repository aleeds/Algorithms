#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template<typename T> 
T getPtrFromIndex(T begin, int i) {
	return (begin + (i-1));
}

template<typename T> 
void swapValues(T itrA, T itrB) {
	auto temp = *itrA;
	*itrA = *itrB;
	*itrB = temp;
}

template<typename T, typename K>
struct wrapper {
	public:
		T ptr;	
		int value;
		W(T p, int v) {
			ptr = p;
			value = v;
		}
};

template<typename T, typename K, typename C>
void countingSort(T begin, T end, K keyFunc, int i, C ctsbegin) { 
	//Create a vector with the count of each element in the original vector
	vector<int> counts(256);
	for (T b = begin; b != end; ++b) {	
		if (i == 0) {
			wrapper w(*b, keyFunc(*b));
			ctsbegin
		}
		else  {
			wrapper w = 
		}
		int curVal = w.value >> i; 
		curVal = curVal & 0xff;
		++counts[curVal];
	}
	cout << "=================================================\n";	
	cout << "Counts: [";
	for (T itr = counts.begin() + 1; itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
	//Make it cumulative
	//*(counts.begin()) -= 1;
	for (T itr = counts.begin() + 1; itr != counts.end(); ++itr) {	
		*itr = *(itr-1) + *itr;
	}
	cout << "=================================================\n";	
	cout << "Cummulative?\n";
	cout << "Counts: [";
	for (T itr = counts.begin() + 1; itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
	for (T itr = end - 1; itr != begin - 1; --itr) {
		//Gets cts index from counts
		int ctsIndex = counts[keyFunc(*itr)];	
		//REPLACE THIS!!
		T curPtr = getPtrFromIndex(ctsbegin, ctsIndex);
		*curPtr = *itr;
		--counts[keyFunc(*itr)];
	}
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {
	//vector<typename T::value_type> cts(end-begin);	
	vector<wrapper> cts(end-begin);	
	//Call caounting sort for times from i 1 to 4	
	for (int i = 0; i < 4; ++i)  {
		countingSort(begin, end, keyFunc, i*8, cts.begin()); 
	}
	//Copy over values from passed cts to passed in array
	//for (int i = 0; i < end - begin;
}
