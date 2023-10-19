#ifndef PAIROfSHOES_H
#define PAIROfSHOES_H

class PairOfShoes
{
private:
	char* name;
    int price;

public:
	/* Constructors declaration */
	PairOfShoes(char* name, int price);

	/* Methods declaration */
	void setPrice(int price);
	char* getName() {  return name; }
	int getPrice() {  return price; }
};

#endif