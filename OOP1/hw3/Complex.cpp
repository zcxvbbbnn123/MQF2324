//Complex.cpp
#include<sstream>
#include<string>
#include<cmath>
#include"Complex.h"
using namespace std;

Complex::Complex(double r, double i)
    : real{r}, imagine{i}
    {}

void Complex::setComplexNumber(double r, double i){
    real = r;
    imagine = i;
}

double Complex::getReal(){return real;}

double Complex::getImagine(){return imagine;}

Complex Complex::add(const Complex right){
    double r{real + right.real};
    double i{imagine + right.imagine};
    return Complex(r, i);
}

Complex Complex::subtract(const Complex right){
    double r{real - right.real};
    double i{imagine - right.imagine};
    return Complex(r, i);
}

string Complex::toString() const{
    ostringstream out;
    out << real << (imagine >= 0? "+": "-") << abs(imagine) << "i";
    return out.str();
}