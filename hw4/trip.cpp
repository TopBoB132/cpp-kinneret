#include "trip.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

int Trip::tripCount = 0;  // Static member initialization

// Validation for destination string
bool Trip::ValiDest(const char *dest)
{
    for(size_t i = 0; i < strlen(dest); i++)
    {
        if(!isalpha(dest[i])) // Checks if all characters are alphabets
            return false;
    }
    return true;
}

// Default constructor
Trip::Trip() : tripNum(++tripCount) // Increment trip count upon creation
{
    dest = new char[8];
    strcpy(dest, "unknown"); // It should be "unknown" not "unkown"
}

// Destructor
Trip::~Trip()
{
    delete[] dest; // Free dynamic memory
}

// Copy assignment operator
Trip& Trip::operator=(const Trip& other)
{
    if (this != &other) 
    {
        delete[] dest; // Avoid memory leak by freeing old memory
        
        tripNum = other.tripNum;
        date = other.date;
        dest = new char[strlen(other.dest) + 1];
        strcpy(dest, other.dest); // Copy the destination
    }
    return *this; // Return the current object
}

// Various getters and setters follow here...

// Overloaded output stream operator
ostream& operator<<(ostream& os, const Trip& trip) {
    os << "Trip Number: " << trip.tripNum << "\n";
    os << "Destination: " << trip.dest << "\n";
    os << "Date: " << trip.date; // Assuming Date class has an overloaded '<<' operator
    return os;
}

// Parameterized constructor
// Constructor implementation
Trip::Trip(const char* dest, const Date& date) : tripNum(++tripCount) // Use the member initializer list for tripNum
{
    // Validation and setting of the trip details
    if(ValiDest(dest))
    {
        this->dest = new char[strlen(dest) + 1]; // Allocate memory
        strcpy(this->dest, dest); // Copy the content
        this->date = date; // Use the date provided
    }
    else
    {
        this->dest = new char[8]; // Allocate memory for "invalid"
        strcpy(this->dest, "invalid"); // Use "invalid" if destination is not valid
        this->date = Date(); // Default date
    }
}
// Copy constructor
Trip::Trip(const Trip& other) : tripNum(++tripCount)  // Increment the trip count for the new trip
{
    // Copy the destination string
    dest = new char[strlen(other.dest) + 1];
    strcpy(dest, other.dest);

    // Copy the date
    date = other.date;

    // Any other fields you have would also need to be copied
}

// Method to get the static trip count
int Trip::getCount()
{
    return tripCount;
}
// Getter for the date
Date Trip::getDate() const {
    return date;
}
// Setter for the date
void Trip::setDate(const Date& newDate) {
    this->date = newDate;
    // You can add more logic here if setting the date involves more operations
}
