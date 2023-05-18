#include<iostream>
#include<iomanip>
using namespace std;

bool isParlidrome(int x){
    int res{0}, target{x};
    while (x != 0){
        int remainder{x % 10};
        res = res * 10 + remainder;
        x /= 10;
    }
    if (res == target) {return true;}
    else {return false;}
}

int main(){
    int a{12345}, b{12321}, c{45554}, d{11611};
    cout << boolalpha;
    cout << "12345: Parlindrome?: " << isParlidrome(a) << endl;
    cout << "12321: Parlindrome?: " << isParlidrome(b) << endl;
    cout << "45554: Parlindrome?: " << isParlidrome(c) << endl;
    cout << "11611: Parlindrome?: " << isParlidrome(d) << endl;
    return 0;
}