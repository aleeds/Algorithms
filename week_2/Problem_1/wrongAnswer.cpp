#include<iostream>
#include<queue>

using std::cout;
using std::cin;

void HCR(void) {
  char JunkString[255];

// cin.flush();
  cout << " <Hit Carriage Return To Continue>\n";
  cin.getline(JunkString,255);

			cout << "CurTime: " << curTime << " End Time: " << endTime << "\n";
			cout << "...CELL DONE SPLITTING...\n";
			cout << "CurTime: " << curTime << " End Time: " << endTime << "\n";
			HCR();
			cout << numCells << "\n";
}

void popCellQueue(

void numCellsHelper(int &numCells, double endTime, double curTime, double minSplit, double maxSplit) {
	while (curTime < endTime) {
		double splitTime = minSplit + rand()*(maxSplit-minSplit)/RAND_MAX; 
		curTime += splitTime;
		if (curTime < endTime) {
			++numCells;
			numCellsHelper(numCells, endTime, curTime, minSplit, maxSplit);
		} else {
			return;
		}
	}

	for (int i = 0; i < numCells; ++i) {
		double splitTime = minSplit + rand()*(maxSplit-minSplit)/RAND_MAX; 
		pq.push(splitTime);
	}
	//Pop the queue
	//See if time + curTime < endTime

	//If it is 
	//numCells++
}


int numCells(double endTime, double minSplit, double maxSplit) {

	double curTime{0.0};
	int numCells{2};

	//std::priority_queue<int> q;
	//std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	std::priority_queue<int, std::greater<int>> pq;
	
	return numCells;
}
