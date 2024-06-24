#include "PairOfShoes.h"

PairOfShoes::PairOfShoes(char* _name, double _price)
{
	name = _name;
	price = _price;
}
void PairOfShoes::SetPrice(double _price)
{
	price = _price;
}