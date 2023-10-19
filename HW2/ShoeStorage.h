#ifndef SHOESTORAGE_H
#define SHOESTORAGE_H

#include "PairOfShoes.h"

class ShoeStorage 
{
private:
    PairOfShoes** shoes;
    int size;

public:
    ShoeStorage(int size = 4);
    ShoeStorage(ShoeStorage& other);
    ShoeStorage& operator = (ShoeStorage& other);
    ~ShoeStorage();

    void AddPairOfShoes(PairOfShoes& shoesToAdd);
    void RemovePairOfShoes(char* nameToRemove);
    double GetPrice(char* nameToFind);
    double AverageShoePrice();
};

#endif