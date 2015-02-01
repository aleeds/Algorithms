#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void HCR() {
  char JunkString[255];

// cin.flush();
  cout << " <Hit Carriage Return To Continue>\n";
  cin.getline(JunkString,255);
}

template<typename T> 
T getPtrFromIndex(T begin, int i) {
	return (begin + (i-1));
}

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
void countingSort(T begin, T end, K keyFunc, int i, T ctsbegin) {
	//Create a vector with the count of each element in the original vector
	vector<int> counts(256);
	cout << "=================================================\n";	
	cout << "Counts: [";
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
	for (T b = begin; b != end; ++b) {	
		int key = keyFunc(*b);
		if (key == 0) {
			++counts[0];
		} else {
			//wrapper<typename T::value_type> w(*b, keyFunc(*b));
			//wrappers.push_back(w);
			int curVal = key >> i; 
			curVal = curVal & 0xff;
			++counts[curVal];
		}
	}

	cout << "=================================================\n";	
	cout << "Counts: [";
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		*itr = *(itr-1) + *itr;
	}
	cout << "=================================================\n";	
	cout << "Cummulative?\n";
	cout << "Counts: [";
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
	cout << "=================================================\n";	
	cout << "CTS\n";
	for (int i = 0; i < (end - begin); ++i)  {
		cout << *(ctsbegin+(i-1)) << " ";
	}
	cout << "=================================================\n";	
	HCR();
	for (auto itr = end - 1; itr != begin - 1; --itr) {
		//Gets cts index from counts
		int key = keyFunc(*itr);
		int ctsIndex = counts[key] - 1;	 
		//REPLACE THIS!!
		T curPtr = getPtrFromIndex(ctsbegin, ctsIndex);
		*curPtr = *itr;
		//--counts[keyFunc(*itr)];
		--counts[key];
	}
	cout << "=================================================\n";	
	cout << "CTS\n";
	for (int i = 0; i < (end - begin); ++i)  {
		cout << *(ctsbegin+(i-1)) << " ";
	}
	cout << "=================================================\n";	
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {

	vector<typename T::value_type> cts(end-begin);	
	//vector<wrapper<typename T::value_type>> wrappers;
	//vector<wrapper<typename T::value_type>> wrappers;
	//for (int i = 0; i < 1; ++i)  {
		//countingSort(begin, end, keyFunc, i*8, cts.begin(), wrappers); 
		countingSort(begin, end, keyFunc, 0, cts.begin()); 
/*
		auto cItr = cts.begin();
		T itr = begin;
		while (itr != end) {
			*itr = *cItr;
			++itr;
			++cItr;
		}
	}*/
}
