// #include <iostream>
#include <vector>

// using std::cout;
// using std::cin;
// using std::vector;

// void HCR() {
//   char JunkString[255];

// // cin.flush();
//   cout << " <Hit Carriage Return To Continue>\n";
//   cin.getline(JunkString,255);
// }

template<typename T, typename K>
void countingSort(T begin, T end, K keyFunc, int i, T ctsbegin, T ctsend) {

	std::vector<int> counts(256, 0);

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
		auto prev =  *(itr - 1);
		if (itr != counts.begin() && prev != 0)
			*itr = prev + *itr;
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
  
	std::vector<typename T::value_type> cts(end-begin);	
	for (int i = 0; i < 4; ++i)  {
		countingSort(begin, end, keyFunc, i*8, cts.begin(), cts.end()); 
		auto cItr = cts.begin();
		T itr = begin;
		while (itr != end) {
			*itr = *cItr;
			++itr;
			++cItr;
		}
	}
}
