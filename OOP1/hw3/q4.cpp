//q4.cpp
#include <iostream> 
#include "Complex.h"
using namespace std;

int main() {
   Complex a{1, 7};
   Complex b{9, 2};

   Complex c = a.add(b); // invoke add function and assign to object c
   cout << a.toString() << " + " << b.toString() << " = " << c.toString() << '\n';

   a.setComplexNumber(10, 1); // reset realPart and 
   b.setComplexNumber(11, 5); // and imaginaryPart  

   c = a.subtract(b); // invoke add function and assign to object c
   cout << a.toString() << " - " << b.toString() << " = " << c.toString() << '\n';
   cout << endl;
} 
