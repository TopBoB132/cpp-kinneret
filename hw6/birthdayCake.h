#ifndef BIRTHDAYCAKE_H
#define BIRTHDAYCAKE_H

#include <iostream>
#include "cake.h"
#include "date.h"

class BirthdayCake : public Cake {
private:
    char* text;

public:
    BirthdayCake(
        Date expireDate,
        int diameter,
        double height,
        double price,
        int storage,
        bool glutenFree,
        const char* text
    );
    string showRecipe() const override {
        return "https://www.example.com/birthday-cake-recipe";
    }

    BirthdayCake(const BirthdayCake& birthdayCake);

    ~BirthdayCake();

    void setExpireDate(const Date& date);
    const Date& getExpireDate() const;

    void setDiameter(const int diameter);
    int getDiameter() const;

    void setHeight(const double height);
    double getHeight() const;

    void setPrice(const double price);
    double getPrice() const;

    void setStorage(const int storage);
    int getStorage() const;

    void setGlutenFree(const bool glutenFree);
    bool getGlutenFree() const;

    void setText(const char* text);
    const char* getText() const;

    bool operator==(const BirthdayCake& birthdayCake);

    friend std::ostream& operator<<(std::ostream& out, const BirthdayCake& birthdayCake);
};

#endif
