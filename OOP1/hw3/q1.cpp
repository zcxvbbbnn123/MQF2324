#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double x;
    double xPtr{&x};
    cout << xPtr;
}