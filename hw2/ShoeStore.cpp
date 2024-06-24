#include "ShoesStore.h"
ShoeStore::ShoeStore(double _discount)
{
	discount = _discount;


}
void ShoeStore::SetDiscountPrecent(double _discount)
{
	discount = _discount;
}
void ShoeStore::AddShoes(char* shoeName, double price, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		PairOfShoes newShoe(shoeName, price);
		shoeStorage.AddPairOfShoes(newShoe);
	}
}
double ShoeStore::AvgShoePrice()
{
	return shoeStorage.AvgShoePrice();
}
double ShoeStore::GetShoesPrice(char* name)
{
	double price = shoeStorage.GetPrice(name);
	return price * ((100.0 - discount) / 100.0);
}
void ShoeStore::RemoveOnePair(char* name)
{
	shoeStorage.RemovePairOfShoes(name);
}