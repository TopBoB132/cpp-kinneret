#include <iostream>

#include "cake.h"
#include "date.h"

using namespace std;

Cake::Cake(
    Date expireDate,
    int diameter,
    double height,
    double price,
    int storage,
    bool glutenFree
) {
    this->expireDate = expireDate;
    this->diameter = diameter;
    this->height = height;
    this->price = price;
    this->storage = storage;
    this->glutenFree = glutenFree;
}

Cake::Cake(const Cake &cake) {
    if (this != &cake) {
        this->expireDate = cake.expireDate;
        this->diameter = cake.diameter;
        this->height = cake.height;
        this->price = cake.price;
        this->storage = cake.storage;
        this->glutenFree = cake.glutenFree;
    }
}

ostream& operator<<(ostream& out, const Cake &cake) {
    out << "Expired Date: " << cake.expireDate << "\n";
    out << "Diameter: " << cake.diameter <<"\n";
    out << "Height: " << cake.height << "\n";
    out << "Price: " << cake.price << "\n";

    if (cake.storage == 1) {
        out << "Storage: Refrigeretor" << "\n";
    }
    else {
        out << "Storage: No Refrigeretor" << "\n";
    }

    if (cake.glutenFree) {
        out << "without Gluten" << "\n";
    }
    else {
        out << "with gluten" << "\n";
    }

    return out;
}

Cake& Cake::operator+=(double price){
    this->price += price;

    return *this;
}

bool Cake::operator==(const Cake &cake){
    if(this == &cake)
        return true;
    if(this->expireDate == cake.expireDate 
        && this->diameter == cake.diameter 
        && this->height == cake.height
        && this->price == cake.price
        && this->storage == cake.storage
        && this->glutenFree == cake.glutenFree
    ){
        return true;
    }
    return false;
}

ostream& operator>>(ostream& os, const Cake &cake) {
    cake.print(os);
    return os;
}