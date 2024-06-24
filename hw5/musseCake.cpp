#include <iostream>

#include <stdbool.h>
#include <string.h>

#include "cake.h"
#include "musseCake.h"
#include "date.h"

using namespace std;

MusseCake::MusseCake(
    Date expireDate,
    int diameter,
    double height,
    double price,
    int storage,
    bool glutenFree,
    const char* taste
) : Cake(
    expireDate,
    diameter,
    height,
    price,
    storage,
    glutenFree
) {
    setTaste(taste);
}

MusseCake::MusseCake(const MusseCake &musseCake) : Cake(musseCake) {
    const char* tmp = musseCake.getTaste();

    if (tmp != nullptr) {
        setTaste(tmp);
    }
    else {
        this->taste = nullptr;
    }
}

MusseCake::~MusseCake() {
    delete[] this->taste;
}

void MusseCake::setExpireDate(const Date &date) {
    this->expireDate = date;
}

const Date& MusseCake::getExpireDate() const {
    return expireDate;
}

void MusseCake::setDiameter(const int diameter) {
    this->diameter = diameter;
}

int MusseCake::getDiameter() const {
    return diameter;
}

void MusseCake::setHeight(const double height) {
    this->height = height;
}

double MusseCake::getHeight() const {
    return height;
}

void MusseCake::setPrice(const double price) {
    this->price = price;
}

double MusseCake::getPrice() const {
    return price;
}

void MusseCake::setStorage(const int storage) {
    if(storage > 2 || storage <= 0) {
        this->storage = 1;
    }
    else {
        this->storage = storage;
    }
}

int MusseCake::getStorage() const {
    return storage;
}

void MusseCake::setGlutenFree(const bool glutenFree) {
    this->glutenFree = glutenFree;
}

bool MusseCake::getGlutenFree() const {
    return glutenFree;
}

void MusseCake::setTaste(const char* taste) {
    this->taste = new char[strlen(taste) + 1];

    strcpy(this->taste, taste);
}

const char* MusseCake::getTaste() const {
    return taste;
}

bool MusseCake::operator==(const MusseCake &ms) {
    if (this == &ms) {
        return true;
    }
    else if (
        this->expireDate == ms.getExpireDate()  &&
        this->diameter == ms.getDiameter()      &&
        this->height == ms.getHeight()          &&
        this->price == ms.getPrice()            &&
        this->storage == ms.getStorage()        &&
        this->glutenFree == ms.getGlutenFree()  &&
        strcmp(this->taste, ms.getTaste()) == 0
    ) {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& out, const MusseCake &ms) {
    // Call the base class operator<< by explicitly qualifying it with Cake::
    out << (const Cake&)ms;
    out << "Taste: " << ms.getTaste() << "\n";
    return out;
}
