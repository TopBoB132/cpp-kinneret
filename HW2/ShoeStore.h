#ifndef SHOESTORE_H
#define SHOESTORE_H

#include "ShoeStorage.h"

class ShoeStore
{
private:
    ShoeStorage shoeStorage;
    double discountPercent;

public:
    ShoeStore(double discountPercent = 0.0);

    double GetDiscountPercent();
    void SetDiscountPercent(double percent);
    void AddShoes(char* name, int price, int numPairs = 1);
    double AverageShoePrice();
    double GetShoePrice(char* name) ;
    void RemoveOnePair(char* name);
};

#endif
