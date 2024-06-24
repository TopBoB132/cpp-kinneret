#ifndef SHOESTORAGE_H
#define SHOESTORAGE_H
#include "PairOfShoes.h"

class ShoeStorage
{
	PairOfShoes** shoes;
	int size;

public:
	ShoeStorage(int size = 4);
	void AddPairOfShoes(PairOfShoes& ShoeToAdd);
	void RemovePairOfShoes(char* nameToRemove);
	double GetPrice(char* nameShoe);
	double AvgShoePrice();
	ShoeStorage(ShoeStorage& other);
	ShoeStorage& operator = (ShoeStorage& other);
	~ShoeStorage(); //מחסה
};

#endif
