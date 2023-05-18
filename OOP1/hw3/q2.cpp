#include<iostream>
#include<iomanip>
using namespace std;

void abc(char* s1, const char* s2){
    while(*s1 != '\0'){
        ++s1;
    }

    for(; (*s1 = *s2); ++s1, ++s2){
        // cout << *s1 << " " << *s2 << endl;
    }
}

int main(){
    char s1[80];
    char s2[80];
    cin >> s1 >> s2;
    abc(s1, s2);
    cout << s1 << endl;

    return 0;
}