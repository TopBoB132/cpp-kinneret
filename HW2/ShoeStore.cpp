#include "ShoeStore.h"

ShoeStore::ShoeStore(double _discountPercent) 
{
    discountPercent = _discountPercent;
}

double ShoeStore::GetDiscountPercent()
{
    return discountPercent;
}

void ShoeStore::SetDiscountPercent(double percent)
{
    discountPercent = percent;
}

void ShoeStore::AddShoes(char* name, int price, int numPairs)
{
    for (int i = 0; i < numPairs; i++)
    {
        PairOfShoes newPairOfShoes = PairOfShoes(name, price);
        shoeStorage.AddPairOfShoes(newPairOfShoes);
    }
}

double ShoeStore::AverageShoePrice()
{
    return shoeStorage.AverageShoePrice();
}

double ShoeStore::GetShoePrice(char* name)
{
    double originalPrice = shoeStorage.GetPrice(name);
    return originalPrice - (originalPrice * discountPercent / 100.0);
}

void ShoeStore::RemoveOnePair(char* name)
{
    shoeStorage.RemovePairOfShoes(name);
}