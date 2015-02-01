
template<typename T,typename C,typename S>
T randomOrderStat(T begin, T end,C lt,S index);

template<typename T,typename C,typename S>
T linearOrderStat(T begin, T end,C lt,S index);

template<typename T, typename C> T partitionUs(T begin, T end, const C &lt) {
  auto i = -1;
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