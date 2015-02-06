#include "math.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
 


template<typename T,typename K>
double find_max(T begin, T end, K keyFunc)
{
	double max = keyFunc(*(begin));
	for(int i=0; i < end-begin; i++) 
	{
		double testing = keyFunc(*(begin+i));
		if (keyFunc(*(begin+i)) > max)
		{
			max = testing;
		}
	}
	return max;
}

template<typename T,typename K>
double find_min(T begin, T end, K keyFunc)
{
	double min = keyFunc(*(begin));
	for(int i=0; i < end-begin; i++)
	{
		double testing = keyFunc(*(begin+i));
		if (keyFunc(*(begin+i)) < min)
		{
			min = testing;
		}
	}
	return min;
}

template< typename Iterator, typename K >  
void insertion_sort( Iterator First, Iterator Last, K keyFunc )  
{  
    for (int i = 1; i<Last-First;i++)
	{
		int j = i;
		while ((j > 0) && (keyFunc(*(First+j-1)) > keyFunc(*(First+j))))
		{
			std::iter_swap(First+j,First+j-1);
			j = j-1;
		}
	}
}


template<typename T,typename K>
void bucketSort(T begin,T end,K keyFunc){
	std::vector<std::vector<typename T::value_type>> bucketArr(end-begin+1);
	double max = find_max(begin,end,keyFunc);
	double min = find_min(begin,end,keyFunc);
	int size = end-begin;
	for(int i=0; i < end-begin; i++)
	{
		double curVal = keyFunc(*(begin+i));
		int bucket = static_cast<int>(floor(size*((curVal - min)/(max - min))));
		bucketArr[bucket].push_back(*(begin+i));
	}
	for (int i=0; i<= end-begin;i++)
	{
		if (bucketArr[i].size() > 1)
		{
			insertion_sort(bucketArr[i].begin(),bucketArr[i].end(),keyFunc);
		}
	}
	int index = 0;
	for (int i=0; i<end-begin+1; i++)
	{
		for(int j=0;j<bucketArr[i].size();j++)
		{
			*(begin+index) = bucketArr[i][j];
			index = index+1;
		}
	}
	return; 
}
