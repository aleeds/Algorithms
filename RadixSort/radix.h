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
class wrapper {
	private:
			
	public:
		T ptr;	
		int value;
		
};

template<typename T, typename K>
void countingSort(T begin, T end, K keyFunc) { 
	//Create a vector with the count of each element in the original vector
	vector<int> counts;
	for (T b = begin; b != end; ++b) {	
		int curVal = keyFunc(*b);
		++counts[curVal];
	}
	//Make it cumulative
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		*itr = *(itr-1) + *itr;
		int curVal = ;
		++counts[curVal];
	}
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {

}

