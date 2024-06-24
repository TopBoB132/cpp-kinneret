#ifndef CAKE_H
#define CAKE_H

#include <iostream>

#include "date.h"

using namespace std;

class Cake
{
    protected:
        Date expireDate;
        int diameter;
        double height;
        double price;
        int storage;
        bool glutenFree;
    public:
        Cake(
            Date expireDate,
            int diameter,
            double height,
            double price,
            int storage,
            bool glutenFree
        );
        
        Cake(const Cake& cake);
        friend ostream& operator<<(ostream& os, const Cake &cake);

        bool operator==(const Cake &cake);
        
        Cake& operator+=(double price);
};


#endif