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

pair<double,vector<int>> knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values) {

	pair<double,int> initialPair(0,0);
	vector<pair<double,int>> temp(weights.size() + 1, initialPair);
	//Current Knapsack Table
	vector<vector<pair<double,int>>> vArr(weightLimit + 1, temp);
	//Keep Value Knapsack Table
	//vector<vector<double>> kArr(weightLimit + 1, temp);
	//printKnapSackValues(vArr); 
	//cout << "\n";

	for (int i = 1; i <= weights.size(); ++i)  {
		int weight = weights[i-1];
		int value = values[i-1];
		for (int w = 1; w < vArr.size(); ++w) {
			if (weight <= w) {
				if (value + vArr[w-weight][i-1].first > vArr[w][i-1].first) {
					vArr[w][i].first = value + vArr[w-weight][i-1].first;
					vArr[w][i].second = 1;
				} else {
					vArr[w][i].first = vArr[w][i-1].first;
				}
			} else {
				vArr[w][i].first = vArr[w][i-1].first;
			}
	//		printKnapSackValues(vArr);
		}
		//cout << "\n"; 
	}

	//Filling up the knapsack
	vector<int> keepIndexes;	
	int w = weightLimit;
	int i = weights.size();
	while(w > 0 && i > 0) {
		if (vArr[w][i].second == 1) { //Put in knapsack
			keepIndexes.push_back(i-1);
			w -= weights[i-1];
		} 
		i -= 1;
	}

	//printKnapSackValues(vArr);
	//printKeepSack(vArr);

	pair<double, vector<int>> ks;
	ks.first = vArr[weightLimit][weights.size()].first;
	ks.second = keepIndexes;

	return ks; 
}
