#ifndef ORDER
#define ORDER

#include <iterator>
#include <vector>

template<typename T,typename C,typename S>
T randomOrderStat(T begin, T end,C lt,S index);

template<typename T,typename C,typename S>
T linearOrderStat(T begin, T end,C lt,S index);

template<typename T, typename C> T medianOfMedians(T begin, T end, const C &lt);


template<typename T, typename C> T randomizedPartition(T begin, T end, const C &lt) {
  auto i = -1;
  auto randomInd = rand() % (end-begin);
  //cout << "RAND: " << randomInd << "\n";
  iter_swap(begin+randomInd, end-1);
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
                                                           // std::cout << "Before Partition: ";
                                                           // for(auto i = begin; i != end; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
    auto pivot = randomizedPartition(begin,end,lt);
                                                           // std::cout << "=================================================\n";  
                                                           // std::cout << "Pivot: " << *pivot << '\n'; 
                                                           // std::cout << "After Partition: ";
                                                           // for(auto i = begin; i != end; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
                                                           // std::cout << '\n';
    auto subSize = pivot - begin + 1;
                                                           // std::cout << "Index = " << index << " and subSize = " << subSize << "     ";
    if(index == subSize - 1) {
                                                           // std::cout << "Returned Element " << *pivot << '\n';
      return pivot;
    } else if(index < subSize) {
                                                          // std::cout << "Moved Left\n";
      return randomOrderStat(begin, pivot, lt, index);
    } else {
                                                          // std::cout << "Moved Right\n";

      return randomOrderStat(pivot+1, end, lt, index-(subSize));
    }
  }
}

template<typename T, typename C> T linearPartition(T begin, T end, const C &lt) {
  auto i = -1;
  auto randomInd = medianOfMedians(begin,end,lt);
  //cout << "RAND: " << randomInd << "\n";
  iter_swap(randomInd, end-1);
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

// template< typename T, typename C >  
// void insertion( T begin, T end, C &lt ) {  
//   for (T j = begin + 2; j != end; j++) {
//     T key = j;
//     T i = j-1;
//     while ((i != begin) && !lt(*i,*key)) {
//       std::iter_swap(i + 1, i);
//       i = i - 1;
//     }
//     std::iter_swap(i+1,key);
//   }
// }

template<typename T, typename C> T minimum(T begin, T end, const C &lt) {
  T min = begin;
  for (auto i = begin; i != end; ++i) {
    if (lt(*i, *min)) {
      min = i;
    }
  }
  return min;
}

template<typename T, typename C> void insertion(T begin, T end, const C &lt) {
  for (auto i = begin; i != end; ++i) {
    auto hold = minimum(i, end,lt);
    iter_swap(i, hold);
  }
}

template<typename T, typename C> T medianOfMedians(T begin, T end, const C &lt) {

  // cout << "======================================================\n";
  // cout << "[";
  // for (auto b = begin; b != end; ++b) {
  //    cout << *b << " ";
  // }
  // cout << "]\n";
  // cout << "======================================================\n";
  if ((end - begin) <= 5) {
      insertion(begin,end,lt);
      return (((end - begin) / 2) + begin);
  }
  int numSubs = ((end - begin) / 5);
  int numMeds = 0;
  if((end - begin) % 5 != 0) ++numSubs;
  // std::vector<T*> medians(end-begin + 1);
  // T* newSubMedian;
  // while(numSubs > 1) {
                                                      // std::cout << "numSubs: " << numSubs << "\n";
        for(int i = 0; i < numSubs; ++i) {
                                                           // std::cout << "\n=================================================\n";  
         int startingIndex = (5 * i);
         T curStart = begin + startingIndex;
          T curEnd;
         if (i == numSubs - 1) {
           curEnd = end;
                                                           // std::cout << "\nBefore Insertion: ";
                                                           // for(auto i = curStart; i != curEnd; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
           insertion(curStart, curEnd, lt);
                                                           // std::cout << "\nAfter Insertion: ";
                                                           // for(auto i = curStart; i != curEnd; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
           T temp = (((end - curStart) / 2) + curStart);
           // newSubMedian = &temp;
                                                      // std::cout << "Median Found: " << *temp << "\n";
           ++numMeds;
           iter_swap((begin + i),temp);
         } else {
           curEnd = curStart + 5;
                                                           // std::cout << "\nBefore Insertion: ";
                                                           // for(auto i = curStart; i != curEnd; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
           insertion(curStart, curEnd, lt);
                                                           // std::cout << "\nAfter Insertion: ";
                                                           // for(auto i = curStart; i != curEnd; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
           T temp = curStart+2;
           // newSubMedian = &temp;
                                                      // std::cout << "Median Found: " << *temp << "\n";
           ++numMeds;
           iter_swap((begin + i),temp);
         }
        } 
                                                           // std::cout << "\n=================================================\n";  
    // numSubs = numSubs / 5;
  // }
  // insertion(begin, begin+numMeds, lt);
  // return (numMeds / 2) + begin; 
  return medianOfMedians(begin,begin+numMeds,lt);
}

template<typename T,typename C,typename S>
T linearOrderStat(T begin, T end,C lt,S index) {
    if(begin == end-1) {
                                                           //std::cout << "One Element List: " << *begin << "\n";
    return begin;
  } else {
                                                           // std::cout << "\nBefore Partition: ";
                                                           // for(auto i = begin; i != end; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
    T pivot = linearPartition(begin, end, lt);
                                                           // std::cout << "\n=================================================\n";  
                                                           // std::cout << "Pivot: " << *pivot << '\n'; 
                                                           // std::cout << "After Partition: ";
                                                           // for(auto i = begin; i != end; ++i) {
                                                           //   std::cout << *i << " ";
                                                           // }
                                                           // std::cout << '\n';
    auto subSize = pivot - begin + 1;
                                                           // std::cout << "Index = " << index << " and subSize = " << subSize << "     ";
    if(index == subSize - 1) {
                                                           // std::cout << "Returned Element " << *pivot << '\n';
      return pivot;
    } else if(index < subSize) {
                                                           // std::cout << "Moved Left\n";
      return linearOrderStat(begin, pivot, lt, index);
    } else {
                                                           // std::cout << "Moved Right\n";
                                                           // std::cout << "\n=================================================\n";  

      return linearOrderStat(pivot+1, end, lt, index-(subSize));
    }
  }
}

#endif
