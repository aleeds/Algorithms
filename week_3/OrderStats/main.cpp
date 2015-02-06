#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "order.h"

using std::cout;
using std::vector;
using std::string;

#define endl "\n"

template<typename T>
void printVector(vector<T> v);

bool less(int a, int b) { return a < b; } 

void startTests();
void testCountingSort();
void test1();
void test2();
void test3();
void test4();

int main(int argc, char* argv[]) {

  startTests();

  return 0;
}

void startTests() {
  cout << "==================================================" << "\n";
  cout << "=================== ORDER STATS ===================" << "\n";
  cout << "==================================================" << "\n";
    clock_t begin = clock();
  test1();
    clock_t end = clock();
    cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
  cout << "==================================================" << "\n";
    begin = clock();
  test2();
    end = clock();
    cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
  cout << "==================================================" << "\n";
  cout << "==================================================" << "\n";
    begin = clock();
  test3();
    end = clock();
    cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
  cout << "==================================================" << "\n";
  cout << "==================================================" << "\n";
    begin = clock();
  test4();
    end = clock();
    cout << "Execution Time: " <<  double(end - begin) / CLOCKS_PER_SEC << " seconds" <<endl;
  cout << "==================================================" << "\n";
}

//Print Vector prints out the vector in a readable format
template<typename T>
void printVector(vector<T> v) {
  cout << "Vector: "; 
  for (auto itr = v.begin(); itr != v.end(); ++itr) {
    cout << *itr << " ";
  }
  cout << endl;
}

//Returns whether or not the collection specified by the iterators
//is sorted or not
template<typename T>
bool isSorted(T begin, T end) {
  for (T i = begin; i != end-1; ++i) {
     if (*i > *(i+1))
         return false;
  }
  return true;
}


//Small int test
void test1() {

  cout << endl;
  cout << "========================================================" << "\n";
  cout << "======================= MEDIAN TEST ====================" << "\n";
  cout << "========================================================" << "\n";
  //vector<int> v1{1,5,4,7,3,9,2,6,8}; 
  //cout << "Median of Medians: " << medianOfMedians(v1.begin(), v1.end(), less) << "\n";


  cout << endl;
  cout << "========================================================" << "\n";
  cout << "==================== SMALL INT TEST ====================" << "\n";
  cout << "========================================================" << "\n";
  int index = 4; 
  vector<int> v{10,5,24,47,3,7,19,20,201,45,63,41}; 
  printVector(v);
  auto orderAns = randomOrderStat(v.begin(),v.end(),less, index);
  vector<int> v1{10,5,24,47,3,7,19,20,201,45,63,41}; 
  printVector(v1);
  auto selectAns = linearOrderStat(v1.begin(),v1.end(),less, index);
  cout << "Vectors After Stat\n";
  printVector(v);
  printVector(v1);
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  cout << "Sorted Vectors: ";
  printVector(v);
  printVector(v1);
  int realAns = v[index];
  int realAns1 = v1[index];
  if (*orderAns == realAns) cout << "Returned Correct Element For Ordered Stat" << endl;
  else cout << "Returned INCORRECT Element For Ordered Stat" << "   Returned: " << *orderAns << "    Should be: " << realAns << endl;
  if (*selectAns == realAns1) cout << "Returned Correct Element For Linear Stat" << endl;
  else cout << "Returned INCORRECT Element For Linear Stat" << "   Returned: " << *selectAns << "    Should be: " << realAns1 << endl;
  cout << "========================================================" << "\n";
  cout << endl;
}

//Big Int Test
void test2() {
  cout << endl;
  cout << "======================================================" << "\n";
  cout << "================== MEDIUM INT TEST ===================" << "\n";
  cout << "======================================================" << "\n";
  //srand(25);
  srand(1);
  vector<int> v;
  vector<int> v1;
  for (int i = 0; i < 100; ++i) {
    v.push_back(rand() % 100);
    v1.push_back(rand() % 100);
  }
  int index = 8; 
  auto orderAns = randomOrderStat(v.begin(),v.end(),less, index);
  auto selectAns = linearOrderStat(v1.begin(),v1.end(),less, index);
  printVector(v);
  cout << "\n";
  printVector(v1);
  cout << "\n";
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  printVector(v);
  printVector(v1);
  int realAns = v[index];
  int realAns1 = v1[index];
  if (*orderAns == realAns) cout << "Returned Correct Element For Ordered Stat: " << *orderAns << endl;
  else cout << "Returned INCORRECT Element For Ordered Stat" << "   Returned: " << *orderAns << "    Should be: " << realAns << endl;
  if (*selectAns == realAns1) cout << "Returned Correct Element For Linear Stat: " << *selectAns << endl;
  else cout << "Returned INCORRECT Element For Linear Stat" << "   Returned: " << *selectAns << "    Should be: " << realAns1 << endl;
  cout << endl;
}
//Big Int Test
void test3() {
  cout << endl;
  cout << "======================================================" << "\n";
  cout << "================== SMALL STRING TEST =================" << "\n";
  cout << "======================================================" << "\n";
  srand(1);
  vector<string> v{"c","b","a","d","z","t","w"};
  vector<string> v1{"c","b","a","d","z","t","w"};
  int index = 5; 
  auto orderAns = randomOrderStat(v.begin(),v.end(), [](string x, string y) { return (x<y);}, index);
  auto selectAns = linearOrderStat(v.begin(),v.end(), [](string x, string y) { return (x<y);}, index);
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  string realAns = v[index];
  string realAns1 = v1[index];
  if (*orderAns == realAns) cout << "Returned Correct Element For Ordered Stat" << endl;
  else cout << "Returned INCORRECT Element For Ordered Stat" << "   Returned: " << *orderAns << "    Should be: " << realAns << endl;
  if (*selectAns == realAns1) cout << "Returned Correct Element For Linear Stat" << endl;
  else cout << "Returned INCORRECT Element For Linear Stat" << "   Returned: " << *selectAns << "    Should be: " << realAns1 << endl;
  cout << endl;
}
//Big Int Test
void test4() {
  cout << endl;
  cout << "======================================================" << "\n";
  cout << "==================== BIG INT TEST ===================" << "\n";
  cout << "======================================================" << "\n";
  srand(25);
  //srand(1);
  vector<int> v;
  vector<int> v2;
  for (int i = 0; i < 10000000; ++i) {
    v.push_back(rand() % 5000000);
    v2.push_back(rand() % 5000000);
  }
  int index = 100; 
  auto orderAns = randomOrderStat(v.begin(),v.end(),less, index);
  auto selectAns = linearOrderStat(v2.begin(),v2.end(),less, index);
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());
  int realAns = v[index];
  int realAns2 = v2[index];
  if (*orderAns == realAns) cout << "Returned Correct Element For Ordered Stat" << endl;
  else cout << "Returned INCORRECT Element For Ordered Stat" << "   Returned: " << *orderAns << "    Should be: " << realAns << endl;
  if (*selectAns == realAns2) cout << "Returned Correct Element For Linear Stat" << endl;
  else cout << "Returned INCORRECT Element For Linear Stat" << "   Returned: " << *selectAns << "    Should be: " << realAns2 << endl;
  cout << endl;
}
