#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    bool ValidMonth(int m);
    bool ValidDay(int d);

public:
    Date();
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const; 
    int getYear() const;  
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    bool operator<(const Date& other) const; 
    bool operator>(const Date& other) const; 
    bool operator==(const Date& other) const;  

    friend ostream& operator<<(ostream& os, const Date& date); 
};
#endif
