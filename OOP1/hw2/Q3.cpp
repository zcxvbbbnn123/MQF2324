#include<iostream>
#include<iomanip>
using namespace std;

double recurPow(double base, int expo){
    if (expo == 1){return base;}
    else {return base * recurPow(base, expo - 1);}
}

int main(){
    cout << "The 7th power of 3 is: " << recurPow(3, 7) << endl;
    return 0;
}