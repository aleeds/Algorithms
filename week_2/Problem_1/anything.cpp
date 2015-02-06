#include<iostream>
#include<vector>

#define endl "\n"

using std::cout;
using std::cin;
using std::vector;
using std::string;

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

template<typename T>
void minHeapify(T begin, int i, int hpSize) {
   if (i > 0 && i < hpSize) {
      int lIndex = getLeftChildIndex(i, hpSize);
      int rIndex = getRightChildIndex(i, hpSize);
      if (lIndex == -1 && rIndex == -1) //Its a leaf
         return;
      int smallestIndex = i;
      T parentPtr = getPtrFromIndex(begin, i);
      T smallest = parentPtr;
      T leftPtr;
      T rightPtr;
      if (lIndex != -1)
         leftPtr = getPtrFromIndex(begin, lIndex);
      if (rIndex != -1)
         rightPtr = getPtrFromIndex(begin, rIndex);
      if (lIndex != -1 && *leftPtr < *parentPtr) {
         smallest = leftPtr;
         smallestIndex = lIndex;
      }
      if (rIndex != -1 && *rightPtr < *smallest) {
         smallest = rightPtr;
         smallestIndex = rIndex;
      }
      if (smallestIndex != i) {
         swapValues(parentPtr, smallest);
         minHeapify(begin, smallestIndex, hpSize);
      }
   }
}

template<typename T>
void bubbleUp(T begin, int i) {
   if (i > 1) {
      int pIndex = i/2;
      T parentPtr = getPtrFromIndex(begin, pIndex);
		T childPtr = getPtrFromIndex(begin, i);
      if (*childPtr < *parentPtr) {
         swapValues(parentPtr, childPtr);
         bubbleUp(begin, pIndex);
      }
   }
}

template<typename T>
void buildMinHeap(T begin, T end) {
   int size = end - begin;
   if (size <= 0)
      return;
   for (int i = size/2; i >= 1; --i) {
      minHeapify(begin, i, size);
   }
}


template<typename T>
class PQ {
	private:
		vector<T> v;
	public:
		PQ() {}
		PQ(vector<T> v2) {
			v = v2;
			buildMinHeap(v.begin(), v.end());
		}
		void pop() {
			if (!v.empty()) {
				T temp = v[(v.size()-1)];	
				v.erase(v.end()-1);
				v[0] = temp;
				minHeapify(v.begin(),1,v.size());
			}
		}
		T top() {
			return v[0];
		}
		void push(T elem) {
			v.push_back(elem);	
			bubbleUp(v.begin(), v.size());
		}
		bool empty() {
			return (v.size() == 0);
		}
		int size() {
			return v.size();
		}
};

template<typename T>
bool isSorted(PQ<T> p) {
	T cur;
	T nxt;
	if (!p.empty()) {
		cur = p.top();
		p.pop();
	}
	while (!p.empty()) {
		nxt = p.top();
		p.pop();
		if (cur > nxt) {
			return false;
		} else {
			cur = nxt;
		}
	}
	return true;
}

template<typename T>
void printQ(PQ<T> pq) {
	cout << "Queue: [";
	while (!pq.empty()) {
		cout << pq.top() << ", ";
		pq.pop();
	}
	cout << "]\n";
}

void splitCells(int &numCells, PQ<double> &pq, double endTime, double &curTime, double minSplit, double maxSplit) {
	cout << "==============================================\n";
	cout << "Num Cells: " << numCells << "\n";
	cout << "Cur Time: " << curTime << " End Time: " << endTime << "\n";
	printQ(pq);
	HCR();
	cout << "==============================================\n";
	if (!pq.empty()) {
		curTime = pq.top();
		if (curTime > endTime) {
			return;
		}
		pq.pop();
		++numCells;
		double splitTime = minSplit + rand()*(maxSplit-minSplit)/RAND_MAX; 
		if (splitTime + curTime <= endTime) {
			pq.push(splitTime + curTime);
		}  
		//else {
			//numCells += pq.size();
			//return;
		//}
		splitTime = minSplit + rand()*(maxSplit-minSplit)/RAND_MAX; 
		if (splitTime + curTime <= endTime) {
			pq.push(splitTime + curTime);
		}  
		//else {
			//numCells += pq.size();
			//return;
		//}
		splitCells(numCells, pq, endTime, curTime, minSplit, maxSplit);
	}
}

int numCells(double endTime, double minSplit, double maxSplit) {

	double curTime{0.0};
	int numCells{2};
	PQ<double> pq;
	double splitTime;
	splitTime = minSplit + rand()*(maxSplit-minSplit)/RAND_MAX; 
	if (splitTime + curTime <= endTime) {
		pq.push(splitTime);
	}
	splitTime = minSplit + rand()*(maxSplit-minSplit)/RAND_MAX; 
	if (splitTime + curTime <= endTime) {
		pq.push(splitTime);
	}
	//cout << "==============================================\n";
	//cout << "Num Cells: " << numCells << "\n";
	//cout << "Cur Time: " << curTime << " End Time: " << endTime << "\n";
	//printQ(pq);
	//HCR();
	//cout << "==============================================\n";
	splitCells(numCells, pq, endTime, curTime, minSplit, maxSplit);
	
	return numCells;
}

//============================================================================
//=============================== TEST CODE ==================================
//============================================================================

void pqTest1() {
   cout << endl;
   cout << "========================================================" << "\n";
   cout << "==================== SMALL INT TEST ====================" << "\n";
   cout << "========================================================" << "\n";
   vector<int> v{10,5,24,47,3,7,19,20,201,45,63,41};
   cout << "========================================================" << "\n";
   PQ<int> p(v);
   printQ(p);
   cout << "========================================================" << "\n";
   if (isSorted(p)) cout << "The collection is sorted" << "\n";
   else cout << "The collection is NOT sorted" << "\n";
   cout << endl;
}

void pqPushTest() {
   cout << endl;
   cout << "========================================================" << "\n";
   cout << "====================== PUSH  TEST ======================" << "\n";
   cout << "========================================================" << "\n";
   cout << "========================================================" << "\n";
   PQ<int> p;
	p.push(10.0);
	p.push(5.6);
	p.push(24.76);
	p.push(47.12);
	p.push(3.1);
	p.push(7.75);
	p.push(19.546);
	p.push(20.345);
	p.push(201.2);
	p.push(45.456);
	p.push(63.1);
	p.push(41.56);
   printQ(p);
   cout << "========================================================" << "\n";
   if (isSorted(p)) cout << "The collection is sorted" << "\n";
   else cout << "The collection is NOT sorted" << "\n";
   cout << endl;
}

void pqTest2() {
   cout << endl;
   cout << "===========================================================" << "\n";
   cout << "==================== SMALL STRING TEST ====================" << "\n";
   cout << "===========================================================" << "\n";
   vector<string> v{"s","c","f","a","z","b","r","t","u"};
   PQ<string> p(v);
   printQ(p);
   cout << "===========================================================" << "\n";
   if (isSorted(p)) cout << "The collection is sorted" << "\n";
   else cout << "The collection is NOT sorted" << "\n";
   cout << endl;
}

void pqTest3() {
   cout << endl;
   cout << "======================================================" << "\n";
   cout << "==================== BIG INT TEST ====================" << "\n";
   cout << "======================================================" << "\n";
   //srand(1);
   vector<int> v;
   for (int i = 0; i < 1000000; ++i) {
      v.push_back(rand() % 5000);
   }
   cout << "========================================================" << "\n";
   PQ<int> p(v);
   cout << "========================================================" << "\n";
   if (isSorted(p)) cout << "The collection is sorted" << "\n";
   else cout << "The collection is NOT sorted" << "\n";
   cout << endl;
}

void testMinPriorityQueue() {
   pqTest1();
	pqPushTest();
   pqTest2();
   pqTest3();
}
