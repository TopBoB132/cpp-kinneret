#ifndef TRIP_H
#define TRIP_H
#include "date.h"
class Trip
{
    private:
        int tripNum;
        char* dest;
        Date date;
        bool ValiDest(const char* dest) const;
    public:
        Trip();
        Trip(int tripNum, const char* dest, const Date& d);
        Trip(const Trip& other); // copy constructor
        ~Trip(); // destructor
        Trip& operator=(const Trip& other); // copy assignment operator


        int getTripNum() const;
        const char* getDest() const;
        Date getDate() const;

        void setTripNum(int tripNum);
        void setDest(const char* dest);
        void setDate(const Date& date);

        void printTrip() const; 

};
#endif