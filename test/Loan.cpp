#include <iostream>
#include "Loan.h"
#include <cmath>
using namespace std;


int Loan::nextID=100;
Loan::Loan(string name, int amount, float rate, int term)
{
    this->amount = amount;
    this->rate = rate;
    this->name = name;
    this->term = term;
    this->id = nextID++;
}
Loan::Loan(const Loan& other) 
{

    this->id = other.id;
    this->name = other.name;
    this->amount = other.amount;
    this->term = other.term;
    this->rate = other.rate;

}
Loan::~Loan(){}

void Loan::setRate(float rate)
{
    this->rate = rate;
}
void Loan::setId()
{
    this->id = nextID++;
}
int Loan::getId() const
{
    return id;
}
float Loan::monthly_payment() const
{
    return ((amount*rate)*pow((1+rate),term)) / (pow((1+rate),term) -1);
}

Loan& Loan::operator=(const Loan &other)
{
    if(this != &other)
    {
        id = other.id;
        name = other.name;
        amount = other.amount;
        term = other.term;
        rate = other.rate;
    }
    return *this;
}

bool Loan::operator==(const Loan &other) const{
    return (
        id == other.id &&
        name == other.name &&
        amount == other.amount &&
        term == other.term &&
        rate == other.rate
        );
}

Loan& Loan::operator+(int extraTime) // Loan a, b; b + 5;
{
    this->term = term + extraTime;
    return *this;
}

void Loan::display()
{
cout << "Loan ID: " << id << "\n"
    << "Name: " << name << "\n"
    << "Amount: " << amount << "\n"
    << "Annual Rate (%): " << rate << "\n"
    << "Term (months): " << term << "\n"
    << "Monthly Payment: "<<monthly_payment()<<endl;

}


