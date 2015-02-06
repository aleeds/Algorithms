
Write both of the order stats functions from the book. The first uses a random partitioning. This is average case O(n), but it has a worst case of O(n^2). The second uses the method they describe to make sure that the worst case is still O(n).

template<typename T,typename C,typename S>
T randomOrderStat(T begin, T end,C lt,S index);  //Found in Ch 9.2
template<typename T,typename C,typename S>
T linearOrderStat(T begin, T end,C lt,S index);  //Found in Ch 9.3

The begin and end are random access iterators. The lt value is a callable that gives a less-than like that for the quicksort. The type S is the size type for this collection and index is the index of the iterator to the value you should return.

Because this function is templated, it needs to go into a header file. Call it "order.h".