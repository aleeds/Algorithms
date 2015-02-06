#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; 
using std::vector;
using std::sort;

template<typename T, typename C>
T &findMin(vector<T> &v, int lowerBound, const C &comp) {
	int minIndex = lowerBound;
	T minValue = v[lowerBound];

	for (int i = lowerBound; i < v.size(); ++i) {
		T cmpVal = v[i];
		if (comp(cmpVal, minValue) < 0) {
			minValue = cmpVal;	
			minIndex = i;
		}
	}
	T &min = v[minIndex];
	return min;
}

template<typename T, typename C>
T &findNth(vector<T> &data, int index, const C &comp) {

	//if (data.empty() || index -1  >= data.size()) {
		//throw std::invalid_argument("Index out of bounds!");
	//}

	//int indexToUse = index - 1;	
	int indexToUse = index;	

	for (int i = 0; i < data.size(); ++i) {
		if (i > indexToUse) {
			return data[indexToUse];
		}
		//Find the minimum and make the swap
		T &min = findMin<T,C>(data, i, comp);
		T swapValue = data[i];	
		data[i] = min;
		min = swapValue;

		//cout << "Just made one pass: ";
		//for (int z = 0; z < data.size(); z++) {
			//cout << data[z] << " ";
		//}
		//cout << "\n";
	}

	return data[indexToUse];
}

