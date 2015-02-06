#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; 
using std::vector;
using std::sort;
using std::swap;

template<typename T>
T getPtrFromIndex(T begin, int i) {
	return (begin + i);	
}

template<typename T>
void swapValues(T itrA, T itrB) {
	auto temp = *itrA;
	*itrA = *itrB;
	*itrB = temp;
}

template<typename T, typename C>
int partition(T begin, int p,int q, const C &lt)
{
    T pivotPointer = getPtrFromIndex(begin, p);
    auto x = *pivotPointer;
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
		  T curPtr = getPtrFromIndex(begin, j);
	 	  auto tmp = *curPtr;
        if(lt(tmp,x))
        {
            i=i+1;
				T iPtr = getPtrFromIndex(begin, i);
            swapValues(iPtr,curPtr);
        }
    }

	 T iPtr = getPtrFromIndex(begin, i);

    swapValues(iPtr,pivotPointer);
    return i;
}

template<typename T, typename C>
void quickSortHelper(T begin, int p,int q, const C &lt)
{
    int r;
    if(p<q)
    {
        r=partition(begin, p,q, lt);
        quickSortHelper(begin,p,r, lt); 
        quickSortHelper(begin,r+1,q, lt);
    }
}

template<typename T, typename C>
void quicksort(T begin, T end, const C &lt)
{
	int size = end - begin;
	//Call To recursive method quicksortHelper
	quickSortHelper(begin, 0, size, lt);
}
