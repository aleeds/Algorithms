#include <iostream>
#include <vector>

using std::pair;
using std::vector;
using std::cout;
using std::cin;

void printKnapSackValues(vector<vector<pair<double,int>>> ks) {
		cout << "\n"; 
	for (int i = 0; i < ks[0].size(); ++i)  {
		for (int j = 0; j < ks.size(); ++j) {
			cout << ks[j][i].first << " ";
		}
		cout << "\n"; 
	}
}

void printKeepSack(vector<vector<pair<double,int>>> ks) {
		cout << "\n"; 
	for (int i = 0; i < ks[0].size(); ++i)  {
		for (int j = 0; j < ks.size(); ++j) {
			cout << ks[j][i].second << " ";
		}
		cout << "\n"; 
	}
}

double getMaxValue(vector<int> indexes, vector<double> values) {
   double sum = 0;
   for (auto itr = indexes.begin(); itr != indexes.end(); ++itr) {
      sum += values[*itr];
   }
   return sum;
}

pair<double,vector<int>> knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values) {

	int weightSize = weights.size();
	pair<double,int> initialPair(0.0,0);
	vector<pair<double,int>> temp(weightSize + 1, initialPair);
	vector<vector<pair<double,int>>> vArr(weightLimit + 1, temp);
	int vArrSize = vArr.size();
	for (int i = 1; i <= weightSize; ++i)  {
		int weight = weights[i-1];
		double value = values[i-1];
		for (int w = 0; w < vArrSize; ++w) {
			if (weight <= w && value + vArr[w-weight][i-1].first > vArr[w][i-1].first) {
				vArr[w][i].first = value + vArr[w-weight][i-1].first;
				vArr[w][i].second = 1;
			} else {
				vArr[w][i].first = vArr[w][i-1].first;
			}
		}
	}

	//Filling up the knapsack
	vector<int> keepIndexes;	
	int w = weightLimit;
	int i = weightSize;
	while(i > 0) {
		if (vArr[w][i].second == 1) { //Put in knapsack
			keepIndexes.push_back(i-1);
			w -= weights[i-1];
		} 
		--i;
	}


	return pair<double, vector<int>> {vArr[weightLimit][weightSize].first, keepIndexes};
	//return ks; 
}
