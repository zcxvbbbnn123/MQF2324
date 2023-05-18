#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

void stringReverse(const string s, int start){
    if (start < 0 || start >= s.length()){ return;}
    cout << s[start];
    return stringReverse(s, start - 1);
}

int main(){
    string str{"abcdefg"};
    for (int i = str.length() - 1; i >= 0; --i){
        stringReverse(str, i);
        cout << endl;
    }
    return 0;
}