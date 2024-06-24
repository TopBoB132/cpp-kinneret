#include "date.h"
#include <iostream>
using namespace std;

// Validation for month range
bool Date::ValidMonth(int m)
{
    return m > 0 && m <= 12;
}

// Validation for day range, assuming all months have 30 days max
bool Date::ValidDay(int d)
{
    return d > 0 && d <= 30; // Note: This simplistic check isn't accurate for all months!
}

// Default constructor
Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

// Constructor with date validation
Date::Date(int d, int m, int y)
{
    if (ValidDay(d) && ValidMonth(m) && y > 0)
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        day = 0;    // Invalid date representation
        month = 0;
        year = 0;
    }
}

// The below block seems to be a misplaced copy of the above constructor logic.
// It should be removed, as it's already included in the constructor.
/*
{
    if(ValidDay(d) && ValidMonth(m) && y>0)
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        day = 0;
        month = 0;
        year = 0;
    }
}
*/

// Getters
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

// Setters with validation
void Date::setDay(int d)
{
    day = ValidDay(d) ? d : 0;
}

void Date::setMonth(int m)
{
    month = ValidMonth(m) ? m : 0;
}

void Date::setYear(int y)
{
    year = y > 0 ? y : 0;  // Assuming any positive integer is a valid year
}

// The below setters appear to be duplicated and should be removed
/*
{
    if(ValidDay(d))
        day = d;
    else
        day = 0;
}
void Date::setMonth(int m)
{
    if(ValidDay(m))  // This seems like a typo; it should be ValidMonth
        month = m;
    else
        month = 0;
}
void Date::setYear(int y)
{
    if(y>0)
        year = y;
    else
        year = 0;
}
*/

// Overloaded output operator
ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year; // Direct access to members
    return os;
}

// Comparison operators
bool Date::operator<(const Date& other) const{
    return (year < other.year) || 
           (year == other.year && month < other.month) || 
           (year == other.year && month == other.month && day < other.day);
}

bool Date::operator>(const Date& other) const{
    return other < *this; // Reuse of '<' operator for implementing '>'
}

bool Date::operator==(const Date& other) const{
    return (day == other.day && month == other.month && year == other.year);
}
