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
void countingSort(T begin, T end, K keyFunc, int i, T ctsbegin, T ctsend) {

	vector<int> counts(256, 0);

/*
	cout << "=================================================\n";	
	cout << "Original Collection:\n";
	for (auto itr = begin; itr != end; ++itr)  {
		cout << *(itr) << " ";
	}
	cout << "=================================================\n";	
	cout << "=================================================\n";	
	cout << "CTS\n";
	for (auto itr = ctsbegin; itr != ctsend; ++itr)  {
		cout << *(itr) << " ";
	}
	cout << "=================================================\n";	
	//Create a vector with the count of each element in the original vector
	cout << "=================================================\n";	
	cout << "Counts: [";
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "]\n";
	cout << "=================================================\n";	
 */
	for (T b = begin; b != end; ++b) {	
		int key = keyFunc(*b);
		if (key == 0) {
			++counts[0];
		} 
		else {
			int curVal = key >> i; 
			curVal = curVal & 0xff;
			//wrapper<typename T::value_type> w(*b, keyFunc(*b));
			//wrappers.push_back(w);
			//if (curVal != 0) {
				counts[curVal] += 1;
			//} else cout << "THERE IS A VALUE EQUAL TO ZERO: " << *b << "\n";
		}
	}
/*
	cout << "=================================================\n";	
	cout << "Counts: [";
	for (T itr = counts.begin(); itr != counts.end(); ++itr) {	
		cout << *itr << " ";
	}
	cout << "\n";
	cout << "=================================================\n";	

 */
	//Make Cumulative
	for (auto itr = counts.begin(); itr != counts.end(); ++itr) {	
		if (itr != counts.begin())
			*itr = *(itr-1) + *itr;
	}
/*
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
	for (auto itr = ctsbegin; itr != ctsend; ++itr)  {
		cout << *(itr) << " ";
	}
	cout << "=================================================\n";	
	HCR();
*/
	for (auto itr = end - 1; itr != begin - 1; --itr) {
		//Gets cts index from counts
		int key = keyFunc(*itr);
		int curVal = key >> i; 
		curVal = curVal & 0xff;
		//int ctsIndex = counts[key] - 1;	 
		int ctsIndex = counts[curVal];	 
		//REPLACE THIS!!
		if (ctsIndex != 0) {
			T curPtr = ctsbegin + (ctsIndex-1);
			*curPtr = *itr;
			--counts[curVal];
		} 
		//--counts[keyFunc(*itr)];
	}
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {

	vector<typename T::value_type> cts(end-begin);	
	//vector<wrapper<typename T::value_type>> wrappers;
	//vector<wrapper<typename T::value_type>> wrappers;
	for (int i = 0; i < 4; ++i)  {
		//countingSort(begin, end, keyFunc, i*8, cts.begin(), wrappers); 
		countingSort(begin, end, keyFunc, i*8, cts.begin(), cts.end()); 
		//countingSort(begin, end, keyFunc, 0, cts.begin(), cts.end()); 
		auto cItr = cts.begin();
		T itr = begin;
		while (itr != end) {
			*itr = *cItr;
			++itr;
			++cItr;
		}
	}
}
