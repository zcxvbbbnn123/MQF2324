#include<iostream>
#include<iomanip>
using namespace std;

unsigned int abc(const char* s){
    unsigned int x;
    for (x = 0; *s != '\0'; ++s){
        x++;
    }
    return x;
}

int main(){
    char s1[80];
    cin >> s1;
    abc(s1);
    cout << abc(s1) << endl;

    return 0;
}