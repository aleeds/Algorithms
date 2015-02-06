Write a quicksort that takes an argument for the sort order. Your function should have the following signature.

template<typename T,typename C> void quicksort(T begin, T end,const C &lt);

The begin and end variables are random access iterators. The object lt should be callable with two arguments and return a bool. So in your code, you can write things like the following.

if(lt(v1,v2)) ...

For this problem you need to submit your function in a file named quicksort.h for the autotester to work.
