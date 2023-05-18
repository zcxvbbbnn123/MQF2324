//Date.h
#include <string>
#ifndef TIME_H
#define TIME_H

class Date{
    public:
        explicit Date(unsigned int m, unsigned int d, unsigned int y);
        std::string toString() const;
        void nextDay();

    private:
        unsigned int month;
        unsigned int day;
        unsigned int year;  
};

#endif