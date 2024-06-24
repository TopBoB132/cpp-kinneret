#ifndef PAIROFSHOES_H
#define PAIROFSHOES_H

class PairOfShoes
{
    char* name;
    double price;

public:
    PairOfShoes(char* name, double price);
    char* GetName()
    {
        return name;
    }
    double GetPrice()
    {
        return price;
    }
    void SetPrice(double price);

};
#endif