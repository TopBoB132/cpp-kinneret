#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include<string>
using namespace std;

class Loan{
    public:
        static int nextID;
        int id;
        string name;
        int amount;
        float rate;
        int term;
   
    Loan() {id++;};

    Loan(string name, int amount=10000, float rate= 3.5f, int term = 36);
    Loan(const Loan& other);
    ~Loan();

    void setRate(float rate);
    void setId();
    int getId() const;
    float monthly_payment() const;

    void display();
    Loan& operator+(int extraTime);
    bool operator==(const Loan& Loan) const;
    Loan& operator=(const Loan &other);
};   


#endif