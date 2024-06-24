#ifndef SHOESTORE_H
#define SHOESTORE_H

#include "ShoeStorage.h"
class ShoeStore {
	ShoeStorage shoeStorage;
	double discount;
public:
	ShoeStore(double discount = 0.0);
	void SetDiscountPrecent(double discount);
	double GetDiscountPrecent()
	{
		return discount;
	}
	void AddShoes(char* shoeName, double price, int amount=1);
	double AvgShoePrice();
	double GetShoesPrice(char* name);
	void RemoveOnePair(char* name);
};




#endif 
