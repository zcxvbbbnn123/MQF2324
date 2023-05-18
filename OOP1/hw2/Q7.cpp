#include<iostream>
#include<iomanip>
#include<array>
using namespace std;

const size_t arraySize{10};

template<typename T>
T recursiveMinimum(const array<T, arraySize> &arr, size_t left, size_t right){
    if (left == right){return arr[left];}
    else{
        if (arr[left] <= arr[right]){return recursiveMinimum(arr, left, right - 1);}
        else {return recursiveMinimum(arr, left + 1, right);}
    }
}
int main(){
    array<int, arraySize> myArr = {4, 10, 5, -8888, 9, 111, -95, 5, 0, 9999};
    cout << setw(6) << "Index" << setw(8) << "Element" << endl;
    for (unsigned int i{0}; i < arraySize; ++i){
        cout << setw(6) << i << setw(8) << myArr[i] << endl;
    }
    cout << "The minimum element of the array is: " << recursiveMinimum(myArr, 0, myArr.size() - 1) << endl;
    return 0;
}