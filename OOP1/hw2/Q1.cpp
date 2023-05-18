#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int sign{1}, firstTerm{-1};
    double res{0.0};
    cout << fixed << setprecision(6);
    for (unsigned int i{1}; i < 400000; i += 2){
        res += sign * 4.0 / i;
        sign *= -1;
        cout << (i + 1) / 2 << setw(10) << res << endl;
        if (firstTerm == -1){
            // convert to int to truncate the decimal spaces after 10^-5
            if (static_cast<int>(res * 100000) == 314159){
                firstTerm = (i + 1) / 2;
            }
        }
    }
    cout << "First term of 3.14159 is: " << firstTerm << endl;

    return 0;
}