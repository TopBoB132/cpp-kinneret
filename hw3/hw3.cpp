#include "Trip.h"
#include <iostream>
using namespace std;





int main() {
    int option;
    Trip* arr = new Trip[0];
    int size = 0;

    do {
          cout << "Please Select an option: \n1. Print Trips\n2. Edit Trip\n3. Add Trip\n4. Exit" <<   endl;
          cin >> option;

        switch (option) {
            case 1:
                Print(arr, size);
                break;
            case 2:
                EditTrip(arr, size);
                break;
            case 3:
                arr = AddTrip(arr, size);
                break;
            case 4:
                cout << "Bye bye!" <<   endl;
                delete[] arr;
                return 0;
            default:
                cout << "Invalid option" <<   endl;
                break;
        }
    } while (option != 4);
}









bool IsEmpty(int size) {
    return size == 0;
}
void Print(Trip* arr, int size) {
    if (IsEmpty(size)) {
        cout << "No trips available." <<   endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        arr[i].printTrip();
        cout << "--------------------------" <<   endl;
    }
}
void EditTrip(Trip* arr, int size) {
    if (IsEmpty(size)) {
        cout << "No trips available." << endl;
        return;
    }

    int tripNum;
    cout << "Enter trip number for editing: ";
    cin >> tripNum;

    for (int i = 0; i < size; i++) {
        if (arr[i].getTripNum() == tripNum) {
            char dest[100];
            int day, month, year;

            cout << "Enter new destination: ";
            cin >> dest;
            arr[i].setDest(dest);

            cout << "Enter new day: ";
            cin >> day;
            cout << "Enter new month: ";
            cin >> month;
            cout << "Enter new year: ";
            cin >> year;
            arr[i].setDate(Date(day, month, year));

            return;
        }
    }
    cout << "Trip not found!" << endl;
}


Trip* AddTrip(Trip* arr, int &size) {
    char dest[100];
    int tripNum, day, month, year;

    cout << "Enter trip number: ";
    cin >> tripNum;

    cout << "Enter destination: ";
    cin >> dest;

    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    Trip* newArr = new Trip[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = Trip(tripNum, dest, Date(day, month, year));
    delete[] arr;
    size++;
    return newArr;
}


