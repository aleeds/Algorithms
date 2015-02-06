#include <iostream>

using std::cout;

template<typename T> 
T getPtrFromIndex(T begin, int i) {
	return (begin + (i-1));
}

int getLeftChildIndex(int pIndex, int hpSize) {
	int childIndex = (pIndex*2);		
	if (childIndex <= hpSize)
		return childIndex;
	else 
		return -1;
}

int getRightChildIndex(int pIndex, int hpSize) {
	int childIndex = (pIndex*2)+1;
	if (childIndex <= hpSize)
		return childIndex;
	else 
		return -1;
}

template<typename T> 
void swapValues(T itrA, T itrB) {
	auto temp = *itrA;
	*itrA = *itrB;
	*itrB = temp;
}

//Max-Heapifies a sub array starting at begin and ending
//at end
template<typename T> 
void maxHeapify(T begin, int i, int hpSize) {
	if (i > 0 && i < hpSize) {
		int lIndex = getLeftChildIndex(i, hpSize);
		int rIndex = getRightChildIndex(i, hpSize);
		if (lIndex == -1 && rIndex == -1) //Its a leaf
			return;
		int largestIndex = i;
		T parentPtr = getPtrFromIndex(begin, i);
		T largest = parentPtr;
		T leftPtr;
		T rightPtr;
		if (lIndex != -1)
			leftPtr = getPtrFromIndex(begin, lIndex); 
		if (rIndex != -1)
			rightPtr = getPtrFromIndex(begin, rIndex);	
		if (lIndex != -1 && *leftPtr > *parentPtr) {
			largest = leftPtr;
			largestIndex = lIndex;
		}
		if (rIndex != -1 && *rightPtr > *largest) {
			largest = rightPtr;
			largestIndex = rIndex;
		} 
		if (largestIndex != i) {
			swapValues(parentPtr, largest);
			maxHeapify(begin, largestIndex, hpSize);
		}
	}
}

template<typename T> 
void buildMaxHeap(T begin, T end) {
	int size = end - begin;
	if (size <= 0)
		return;
	for (int i = size/2; i >= 1; --i) {
		maxHeapify(begin, i, size);
	}
}

// begin and end variables are random access iterators
template<typename T> 
void heapsort(T begin, T end) {
	//Build Max-Heap
	buildMaxHeap(begin, end);
	int size = end - begin; 
	//Swap first and last values
	//MaxHeapify Sub list (hpSize moves down)
	for (int i = size; i >= 2; --i) {
		swapValues(getPtrFromIndex(begin, 1), getPtrFromIndex(begin, i));	
		maxHeapify(begin, 1, --size); 
	}
}
