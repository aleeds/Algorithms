#include <iostream>
#include <vector>

using std::pair;
using std::vector;
using std::cout;
using std::cin;

void printKnapSack(vector<vector<double>> ks) {
		cout << "\n"; 
	for (auto i = 0; i < ks[0].size(); ++i)  {
		for (auto j = 0; j < ks.size(); ++j) {
			cout << ks[j][i] << " ";
		}
		cout << "\n"; 
	}
}

pair<double,vector<int>> knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values) {

	vector<double> temp(weights.size() + 1, 0);
	//Current Knapsack Table
	vector<vector<double>> vArr(weightLimit + 1, temp);
	//Keep Value Knapsack Table
	//vector<vector<double>> kArr(weightLimit + 1, temp);
	printKnapSack(vArr); 
	cout << "\n";

	for (int i = 1; i <= weights.size(); ++i)  {
		int weight = weights[i-1];
		int value = values[i-1];
		for (int w = 1; w < vArr.size(); ++w) {
			if (weight <= w) {
				if (value + vArr[w-weight][i-1] > vArr[w][i-1]) {
					vArr[w][i] = value + vArr[w-weight][i-1];
				} else {
					vArr[w][i] = vArr[w][i-1];
				}
			} else {
				vArr[w][i] = vArr[w][i-1];
			}
			printKnapSack(vArr);
		}
		cout << "\n"; 
	}
	

	printKnapSack(vArr);

	//vector<int> v;
	pair<double, vector<int>> p;
	return p; 
}
