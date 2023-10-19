#include "PairOfShoes.h"

PairOfShoes::PairOfShoes(char* _name, int _price)
{
    name = _name;
    price = _price;
}

// Sets price to new price 
void PairOfShoes::setPrice(int _price)
{
    price = _price;
}