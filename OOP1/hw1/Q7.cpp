#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cout << "BMI VALUES" << endl
         << "Underweight: less than 18.5" << endl
         << "Normal:      between 18.5 and 24.9" << endl
         << "Overwright:  between 25 and 29.9" << endl
         << "Obese:       30 or greater" << endl;

    //use -1 to check validity of input and avoid division by 0
    double weight{-1.0}, height{-1.0};
    while (weight <= 0 || height <= 0){
        cout << "\nPlease enter your weight (in kilogram) and height (in meter):" << endl;
        cin >> weight >> height;
        if (weight <= 0 || height <= 0){
            cout << "invalid input, please try again" << endl;
        }
    }
    double BMI = weight / (height*height);
    cout << "\nYour BMI is: " << fixed << setprecision(2) << BMI << endl;

    return 0;
}