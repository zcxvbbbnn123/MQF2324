#include<iostream>
#include<iomanip>
#include<array>
using namespace std;

int main(){
    array<int, 1000> arr;
    // initialize the array
    for (auto &ele: arr){ele = 1;}

    for (unsigned int i{2}; i < arr.size(); ++i){
        if (arr[i] == 1){
            for (unsigned int j{i + 1}; j < arr.size(); ++j){
                if (j % i == 0){
                    arr[j] = 0;
                }
            }
        }
    }
    int count = 0;
    for (unsigned int i{2}; i < arr.size(); ++i){
        if (arr[i] == 1){
            cout << setw(5) << i;
            count++;
        }
        if (count == 20){count = 0; cout << endl;}
    }
    cout << endl;

    return 0;
}