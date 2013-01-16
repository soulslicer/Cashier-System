#ifndef PERISHABLEPRODUCT_H
#define PERISHABLEPRODUCT_H
#include "Product.h"
using namespace std;

class PerishableProduct : public Product
{
protected:
	int expiryDate[3];
	double _discountPercentage;
public:
	PerishableProduct();
	PerishableProduct(string);
	void printProduct();
	bool checkExpired();
	//using streamstring to construct string
	int* getExpiryDate();
	double getDiscountPercentage();
	bool setExpiryDate(int*);
	bool setDiscountPercentage(double);

};

#endif

//perishable class product