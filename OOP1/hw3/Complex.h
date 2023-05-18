//Complex.h
#include<string>
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    public:
        explicit Complex(double r = 0.0, double i = 0.0);
        void setComplexNumber(double r, double i);
        double getReal();
        double getImagine();
        Complex add(const Complex right);
        Complex subtract(const Complex right);
        std::string toString () const;

    private:
        double real;
        double imagine;
};

#endif