#include "trip.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;
bool Trip::ValiDest(const char* dest) const
{
    for(size_t i = 0; i < strlen(dest); i++)
    {
        if(!isalpha(dest[i]))
            return false;
    }

    return true;
}
Trip::Trip()
{
    dest = new char[8];
    strcpy(dest, "unkown");
}
Trip::Trip(int tripNum, const char* dest, const Date& date)
{
    if(tripNum> 0 && ValiDest(dest))
    {
        this->tripNum = tripNum;
        this->dest = new char[strlen(dest) +1];
        strcpy(this->dest, dest);
        this->date = date;
    }
    else
    {
        this->tripNum = 0;
        this->dest = new char[8];
        strcpy(this->dest, "not good");
        this->date = Date(); // default 
    }
}

Trip::Trip(const Trip& other) : tripNum(other.tripNum), date(other.date)
{
    dest = new char[strlen(other.dest) + 1];
    strcpy(dest, other.dest);
}

Trip::~Trip()
{
    delete[] dest;
}

Trip& Trip::operator=(const Trip& other)
{
    if (this != &other) 
    {
        delete[] dest;
        
        tripNum = other.tripNum;
        date = other.date;
        dest = new char[strlen(other.dest) + 1];
        strcpy(dest, other.dest);
    }
    return *this;
}

int Trip::getTripNum() const
{
    return tripNum;
}

const char* Trip::getDest() const
{
    return dest;
}

Date Trip::getDate() const
{
    return date;
}


void Trip::setDate(const Date& date)
{
    this->date = date;
}

void Trip::setTripNum(int tripNum)
{
    if (tripNum > 0)
    {
        this->tripNum = tripNum;
    }
    else
    {
        this->tripNum = 0;
    }
}

void Trip::setDest(const char* dest)
{
    if (ValiDest(dest))
    {
        delete[] this->dest;
        this->dest = new char[strlen(dest) + 1];
        strcpy(this->dest, dest);
    }
    else
    {
        delete[] this->dest;
        this->dest = new char[8];
        strcpy(this->dest, "invalid");
    }
}

void Trip::printTrip() const
{
    cout << "Trip Number: " << tripNum << endl;
    cout << "Destination: " << dest << endl;
    cout << "Date: ";
    date.printDate();
}