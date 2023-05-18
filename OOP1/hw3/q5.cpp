#include <iostream> 
#include "Date.h" // include definitions of class Date
using namespace std;

int main() {
   const unsigned int MAXDAYS{16};
   Date d{12, 24, 2013}; // instantiate object d of class Date

   // output Date object d's value
   for (unsigned int loop{1}; loop <= MAXDAYS; ++loop) {
      cout << d.toString() << endl;
      d.nextDay(); // invokes function next day
   } 

   cout << endl;
} 
