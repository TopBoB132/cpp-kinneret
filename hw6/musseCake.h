#ifndef MOUSSECAKE_H
#define MOUSSECAKE_H

#include <iostream>
#include <stdbool.h>

#include "date.h"
#include "cake.h"

using namespace std;

class MusseCake : public Cake {
    private:
        char* taste;

    public:
        MusseCake(
            Date expireDate,
            int diameter,
            double height,
            double price,
            int storage,
            bool glutenFree,
            const char* taste
        );

        MusseCake(const MusseCake &moussecake);

        ~MusseCake();

        void setExpireDate(const Date &date);
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

        void setTaste(const char* taste);
        const char* getTaste() const;

        bool operator==(const MusseCake &ms);

        friend ostream& operator<<(ostream& out, const MusseCake &ms);
};

#endif