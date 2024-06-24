#include "bakery.h"
#include <iostream>
using namespace std;
// Constructor
Bakery::Bakery(const char* name, Date openingDate, int maxCakes) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->openingDate = openingDate;
    this->maxCakes = maxCakes;
    this->cakes = new Cake*[maxCakes];
    this->currentCakes = 0;
}

// Destructor
Bakery::~Bakery() {
    delete[] name;
    for (int i = 0; i < currentCakes; i++) {
        delete cakes[i];
    }
    delete[] cakes;
}

// Copy Constructor
Bakery::Bakery(const Bakery& other) {
    // Implement a deep copy
}

// Copy Assignment Operator
Bakery& Bakery::operator=(const Bakery& other) {
    if (this != &other) {
        // Implement a deep copy
    }
    return *this;
}

// Methods
void Bakery::addCake(Cake* cake) {
    if (currentCakes < maxCakes) {
        cakes[currentCakes++] = cake;
    } else {
        cout << "Bakery is full. Cannot add more cakes." << std::endl;
    }
}

void Bakery::deleteCake(int position) {
    if (position < 0 || position >= currentCakes) {
        cout << "Invalid position." << endl;
        return;
    }
    delete cakes[position];
    for (int i = position; i < currentCakes - 1; i++) {
        cakes[i] = cakes[i + 1];
    }
    currentCakes--;
}

void Bakery::deleteExpired(const Date& currentDate) {
    for (int i = 0; i < currentCakes; i++) {
        if (cakes[i]->getExpireDate() > currentDate) {
            deleteCake(i);
            i--; // Adjust index as we've removed an element
        }
    }
}

void Bakery::chooseCake(double maxPrice) const {
    for (int i = 0; i < currentCakes; i++) {
        if (cakes[i]->getPrice() <= maxPrice) {
            cout << *cakes[i] << endl;
        }
    }
}

// Overloaded >> operator
ostream& operator>>(ostream& os, const Bakery& bakery) {
    os << "Bakery Name: " << bakery.name << endl;
    os << "Opening Date: " << bakery.openingDate << endl;
    os << "Cakes Available: " << endl;
    for (int i = 0; i < bakery.currentCakes; i++) {
        os << *bakery.cakes[i] << endl;
    }
    return os;
}
