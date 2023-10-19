#include "ShoeStorage.h"
#include "PairOfShoes.h"
#include "cstring"

ShoeStorage::ShoeStorage(int _size)
{
    size = _size;
    shoes = new PairOfShoes*[size];
    for (int i = 0; i < size; i++) 
    {
        shoes[i] = nullptr;
    }
}


ShoeStorage::ShoeStorage(ShoeStorage& other) {
    size = other.size;
    shoes = new PairOfShoes*[size];

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
        shoes = new PairOfShoes*[size];
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

ShoeStorage::~ShoeStorage() 
{
    for (int i = 0; i < size; i++) 
    {
        delete shoes[i];
    }
    delete[] shoes;
}

void ShoeStorage::AddPairOfShoes(PairOfShoes& shoesToAdd) 
{
    int checkSizeLeft = 0;
    while (checkSizeLeft < size && shoes[checkSizeLeft] != nullptr) 
    {
        checkSizeLeft++;
    }

    if (checkSizeLeft == size) 
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

    shoes[checkSizeLeft] = new PairOfShoes(shoesToAdd);
}

//helper function
bool areStringsEqual(const char* str1, const char* str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return false;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

void ShoeStorage::RemovePairOfShoes(char* nameToRemove)
{
    for (int i = 0; i < size; i++)
    {
        if ((shoes[i] != nullptr) && // strcmp(nameToRemove, (*shoes[i]).getName()) == 0)
            (areStringsEqual(nameToRemove, (*shoes[i]).getName()))) 
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

double ShoeStorage::GetPrice(char* nameToFind)  
{
    for (int i = 0; i < size; i++) 
    {
        if ((shoes[i] != nullptr) && // (strcmp((*shoes[i]).getName(), nameToFind) == 0)
            (areStringsEqual(nameToFind, (*shoes[i]).getName())))
        {
            return (*shoes[i]).getPrice();
        }
    }
    return 0.0; // Shoe not found
}

double ShoeStorage::AverageShoePrice() 
{
    int validCount = 0;
    double total = 0.0;

    for (int i = 0; i < size; i++) 
    {
        if (shoes[i] != nullptr) 
        {
            total += (*shoes[i]).getPrice();
            validCount++;
        }
    }

    if (validCount == 0) 
    {
        return 0.0;
    }

    return total / validCount;
}