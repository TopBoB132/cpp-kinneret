#include "birthdayCake.h"
#include <cstring>

BirthdayCake::BirthdayCake(
    Date expireDate,
    int diameter,
    double height,
    double price,
    int storage,
    bool glutenFree,
    const char* text
) : Cake(
    expireDate,
    diameter,
    height,
    price,
    storage,
    glutenFree
) {
    setText(text);
}

BirthdayCake::BirthdayCake(const BirthdayCake& birthdayCake) : Cake(birthdayCake) {
    const char* tmp = birthdayCake.getText();

    if (tmp != nullptr) {
        setText(tmp);
    } else {
        this->text = nullptr;
    }
}

BirthdayCake::~BirthdayCake() {
    delete[] this->text;
}

void BirthdayCake::setExpireDate(const Date& date) {
    this->expireDate = date;
}

const Date& BirthdayCake::getExpireDate() const {
    return this->expireDate;
}

void BirthdayCake::setDiameter(const int diameter) {
    this->diameter = diameter;
}

int BirthdayCake::getDiameter() const {
    return diameter;
}

void BirthdayCake::setHeight(const double height) {
    this->height = height;
}

double BirthdayCake::getHeight() const {
    return height;
}

void BirthdayCake::setPrice(const double price) {
    this->price = price;
}

double BirthdayCake::getPrice() const {
    return price;
}

void BirthdayCake::setStorage(const int storage) {
    if (storage > 2 || storage <= 0) {
        this->storage = 1;
    } else {
        this->storage = storage;
    }
}

int BirthdayCake::getStorage() const {
    return storage;
}

void BirthdayCake::setGlutenFree(const bool glutenFree) {
    this->glutenFree = glutenFree;
}

bool BirthdayCake::getGlutenFree() const {
    return glutenFree;
}

void BirthdayCake::setText(const char* text) {
    delete[] this->text;
    this->text = new char[strlen(text) + 1];
    strcpy(this->text, text);
}

const char* BirthdayCake::getText() const {
    return text;
}

bool BirthdayCake::operator==(const BirthdayCake& birthdayCake) {
    if (this == &birthdayCake) {
        return true;
    } else if (
        this->expireDate == birthdayCake.getExpireDate() &&
        this->diameter == birthdayCake.getDiameter() &&
        this->height == birthdayCake.getHeight() &&
        this->price == birthdayCake.getPrice() &&
        this->storage == birthdayCake.getStorage() &&
        this->glutenFree == birthdayCake.getGlutenFree() &&
        strcmp(this->text, birthdayCake.getText()) == 0
    ) {
        return true;
    }

    return false;
}

ostream& operator<<(std::ostream& out, const BirthdayCake& birthdayCake) {
    out << static_cast<const Cake&>(birthdayCake);
    out << "Text: " << birthdayCake.getText() << "\n";

    return out;
}

void print(std::ostream& os) const override {
            // Implement the details you want to print
            os << "Birthday Cake: " << /* Details */ << std::endl;
}