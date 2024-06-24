#include <iostream>
#include "ManagmentTrips.h"  
void deleteTrips(ManagementTrips& mts);
void addTrip(ManagementTrips& mts);
using namespace std;


int main() {
    ManagementTrips mts;
    int option;

    do {
        cout << "Please select an option:\n"
                     "1. Print Trips\n"
                     "2. Delete Trips\n"
                     "3. Add Trip\n"
                     "4. Exit" << endl;

        cin >> option;
        switch (option) {
            case 1:
                cout << mts;
                break;
            case 2:
                deleteTrips(mts);
                break;
            case 3:
                addTrip(mts);
                break;
            case 4:
                cout << "Bye bye!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    } while (option != 4);

    return 0;  
}

void deleteTrips(ManagementTrips& mts) {
    int day, month, year;
    cout << "Enter date to delete trips (day month year): ";
    cin >> day >> month >> year;
    Trip tripToDelete;  
    tripToDelete.setDate(Date(day, month, year));  

    mts -= tripToDelete; 
}

void addTrip(ManagementTrips& mts) {
    string destination;
    int day, month, year;
    cout << "Enter destination: ";
    cin >> destination; 
    cout << "Enter date (day month year): ";
    cin >> day >> month >> year;


    Trip* newTrip = new Trip(destination.c_str(), Date(day, month, year)); 

    mts += *newTrip; 
}

