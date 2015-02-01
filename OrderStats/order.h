#ifndef ORDER
#define ORDER

#include <vector>

template<typename T,typename C,typename S>
T randomOrderStat(T begin, T end,C lt,S index);

template<typename T,typename C,typename S>
T linearOrderStat(T begin, T end,C lt,S index);

template<typename T, typename C> T randomizedPartition(T begin, T end, const C &lt) {
  auto i = -1;
  auto randomInd = rand() % (end-begin);
  iter_swap(begin+randomInd, end);
  auto x = *(end - 1);
  //may want to make const ref to end - 1
  for (auto j = begin; j != (end - 1); ++j) {

    if (lt(*j, x)) {
      i += 1;
      iter_swap(begin + i, j);
    }
  }
  iter_swap(begin + i + 1, end - 1);
  return (begin + i + 1);
}

template<typename T,typename C,typename S>
T randomOrderStat(T begin, T end,C lt,S index) {
  if(begin == end-1) {
                                                          // std::cout << "One Element List: " << *begin << "\n";
    return begin;
  } else {
    auto pivot = randomizedPartition(begin,end,lt);
                                                          // std::cout << "=================================================\n";  
                                                          // std::cout << "Pivot: " << *pivot << '\n'; 
                                                          // std::cout << "Vector: ";
                                                          // for(auto i = begin; i != end; ++i) {
                                                          //   std::cout << *i << " ";
                                                          // }
                                                          // std::cout << '\n';
    auto subSize = pivot - begin;
                                                          // std::cout << "Index = " << index << " and subSize = " << subSize << "     ";
    if(index == subSize) {
                                                          // std::cout << "Returned Element " << *pivot << '\n';
      return pivot;
    } else if(index < subSize) {
                                                          // std::cout << "Moved Left\n";
      return randomOrderStat(begin, pivot-1, lt, index);
    } else {
                                                          // std::cout << "Moved Right\n";

      return randomOrderStat(pivot+1, end, lt, index-(subSize+1));
    }
  }
}

template<typename T, typename C> T linearPartition(T begin, T end, const C &lt, T pivot) {
  auto place = -1;
  //may want to make const ref to end - 1
  for (auto iter = begin; iter != (end - 1); ++iter) {

    if (lt(*iter, pivot)) {
      place += 1;
      iter_swap(begin + place, j);
    }
  }
  iter_swap(begin + i + 1, end - 1);
  return (begin + i + 1);
}

template<typename T, typename C> void insertion(T begin, T end, const C &lt) {
  for (auto i = begin; i != end; ++i) {
    auto hold = minimum(i, end,lt);
    iter_swap(i, hold);
  }
}

template<typename T, typename C> T medianOfMedians(T begin, T end, const C &lt) {
  int numSubs = (end - begin) / 5;
  if((end - begin) % 5 != 0) ++numSubs;
  std::vector medians(numSubs,0);
  for(int i = 0; i < numSubs; ++i) {
    std::vector
  } 
}

template<typename T,typename C,typename S>
T linearOrderStat(T begin, T end,C lt,S index) {

}

#endif