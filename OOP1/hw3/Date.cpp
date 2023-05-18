//Date.cpp
#include<sstream>
#include<string>
#include"Date.h"
using namespace std;

Date::Date(unsigned int m, unsigned int d, unsigned int y){
    if(m > 0 && m <= 13){month = m;} //month
    
    //day
    switch (m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: //long months
            if(d > 0 && d <= 31){day = d;}
            break;
        
        case 4: case 6: case 9: case 11: //short months
            if(d > 0 && d <= 30){day = d;}
            break;

        case 2: //Feb
            if(y % 4 == 0){
                if(d > 0 && d <= 29){day = d;}
            }
            else{
                if(d > 0 && d <= 28){day = d;}
            }
            break;

        default: break;
        }

    //year
    if(y > 0){year = y;}
}

string Date::toString() const{
    ostringstream out;
    out << month << "/" << day << "/" << year;
    return out.str();
}

void Date::nextDay(){
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: //long months other than Dec
            if(day == 31){day = 1; month++;}
            else{day++;}
            break;
        
        case 4: case 6: case 9: case 11: //short months
            if(day == 30){day = 1; month++;}
            else{day++;}
            break;

        case 2: //Feb
            if(year % 4 == 0){
                if(day == 29){day = 1; month++;}
                else{day++;}
            }
            else{
                if(day == 28){day = 1; month++;}
                else{day++;}
            }
            break;
        
        case 12: //Dec
            if(day == 31){day = 1; month = 1; year++;}
            else{day++;}
            break;

        default: break;
        }
}