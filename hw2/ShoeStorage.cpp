#include "ShoeStorage.h"
#include "cstring"
ShoeStorage::ShoeStorage(int _size) // :size(_size)
{
	size = _size;
	shoes = new PairOfShoes * [size];
	for (int i = 0; i < size; i++)
	{
		shoes[i] = nullptr;
	}
}

void ShoeStorage::AddPairOfShoes(PairOfShoes& ShoesToAdd)
{
	int indexFirstNull = 0;
	while (shoes[indexFirstNull] != nullptr && indexFirstNull < size)
	{
		indexFirstNull++;
	}
	if (indexFirstNull == size)
	{
		int newSize = size * 2;
		PairOfShoes** newShoes = new PairOfShoes*[newSize];
		for (int i = 0; i < newSize; i++)
		{
			newShoes[i] = nullptr;
		}
		for (int i = 0; i < size; i++)
		{
			newShoes[i] = shoes[i];
		}
		delete[] shoes;
		shoes = newShoes;
		size = newSize;
	}
	shoes[indexFirstNull] = new PairOfShoes(ShoesToAdd);

}

void ShoeStorage::RemovePairOfShoes(char* nameToRemove)
{
	for (int i = 0; i < size; i++)
	{
		if (shoes[i] != nullptr && strcmp(nameToRemove, shoes[i]->GetName()) == 0)
		{
			delete shoes[i];  
			for (int j = i; j < size - 1; j++)
			{
				shoes[j] = shoes[j + 1];
			}
			shoes[size - 1] = nullptr;
			break; 
		}
	}
}

double ShoeStorage::GetPrice(char* nameShoe)
{
	for (int i = 0; i < size; i++)
	{
		if (shoes[i] != nullptr && strcmp(nameShoe, shoes[i]->GetName()) == 0)
			return shoes[i]->GetPrice();
	}
	return 0.0;
}
double ShoeStorage::AvgShoePrice()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += shoes[i]->GetPrice();
	}
	if (sum != 0)
		return sum / size;
	return 0.0;
}

ShoeStorage::~ShoeStorage()
{
	for (int i = 0; i < size; i++)
	{
		delete shoes[i];
	}
	delete[] shoes;
}

ShoeStorage::ShoeStorage(ShoeStorage& other) {
	size = other.size;
	shoes = new PairOfShoes * [size];

	for (int i = 0; i < size; i++)
	{
		if (other.shoes[i] != nullptr)
		{
			shoes[i] = new PairOfShoes(*(other.shoes[i]));
		}
		else
		{
			shoes[i] = nullptr;
		}
	}
}

ShoeStorage& ShoeStorage::operator = (ShoeStorage& other)
{
	if (this != &other)
	{
		for (int i = 0; i < size; i++)
		{
			delete shoes[i];
		}
		delete[] shoes;

		size = other.size;
		shoes = new PairOfShoes * [size];
		for (int i = 0; i < size; i++)
		{
			if (other.shoes[i] != nullptr)
			{
				shoes[i] = new PairOfShoes(*(other.shoes[i]));
			}
			else
			{
				shoes[i] = nullptr;
			}
		}
	}
	return *this;
}