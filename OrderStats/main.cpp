#include <algorithm>
#include <vector>
#include <iostream>
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

//Returns element at Nth index
template<typename T,typename C>
T &findNth(std::vector<T> &data,int index,const C &comp) {
  std::sort(data.begin(), data.end(), [&](T a, T b) {
    return (comp(a, b) <= 0);   
  });
  std::cout << data[index];
  return data[index];
}

//Small int test
void test1() {
  cout << endl;
  cout << "========================================================" << "\n";
  cout << "==================== SMALL INT TEST ====================" << "\n";
  cout << "========================================================" << "\n";
  // vector<int> v{3, 5, 4, 0, 1, 2};
   vector<int> v{10,5,24,47,3,7,19,20,201,45,63,41}; 
  printVector(v);
  int index = 4; 
  auto orderAns = randomOrderStat(v.begin(),v.end(),less, index);
  sort(v.begin(), v.end());
  cout << "Sorted Vector: ";
  printVector(v);
  int realAns = v[index];
   if (*orderAns == realAns) cout << "Returned Correct Element" << endl;
   else cout << "Returned INCORRECT Element" << "   Returned: " << *orderAns << "    Should be: " << realAns << endl;
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
  for (int i = 0; i < 100; ++i) {
    v.push_back(rand() % 100);
  }
  int index = 18; 
  auto orderAns = randomOrderStat(v.begin(),v.end(),less, index);
  sort(v.begin(), v.end());
  int realAns = v[index];
   if (*orderAns == realAns) cout << "Returned Correct Element" << endl;
   else cout << "Returned INCORRECT Element" << "   Returned: " << *orderAns << "    Should be: " << realAns << endl;
  cout << endl;
}
//Big Int Test
void test3() {
  cout << endl;
  cout << "======================================================" << "\n";
  cout << "==================== BIG INT TEST ===================" << "\n";
  cout << "======================================================" << "\n";
  //srand(25);
  srand(1);
  vector<int> v;
  for (int i = 0; i < 10000000; ++i) {
    v.push_back(rand() % 500000);
  }
  int index = 100; 
  auto orderAns = randomOrderStat(v.begin(),v.end(),less, index);
  sort(v.begin(), v.end());
  int realAns = v[index];
   if (*orderAns == realAns) cout << "Returned Correct Element" << endl;
   else cout << "Returned INCORRECT Element" << "   Returned: " << *orderAns << "    Should be: " << realAns << endl;
  cout << endl;
}