Operator Overloading 

The following operators cannot be defined by a user
:: scope resolution
. member selection
.* member selection through pointer to member

a + b //shorthand
a.operator+(b) //explicit call

operators operator= operator[] operator() and operator->
must all be non static member functions

If you want to be able to do complex + complex, and complex vs double,
you can overload + as many times as you like

CONVERSION OPERATORS

To convert from type X To T, a member function X::operator T() is defined.
