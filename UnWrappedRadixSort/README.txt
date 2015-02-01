
For this problem you should write a radix sort with the signature shown below. The arguments begin and end will be random access iterators. The value keyFunc is a callable such that keyFunc(*begin) gives you an int.

template<typename T,typename K>
void radixSort(T begin,T end,K keyFunc);

Because this function is templated, it needs to go into a header file. Call it "radix.h".


How to get the last byte of an integer
(Bitmask)
i & 0xff
To Shift Right
i >> 8 
The next digit...
i >> 16

