#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product
{
protected:
	string _name,_category, _barcodeNum,_manufacturer;
	int _numInStock,_numSoldPerMonth;
	double _price;
	bool _perishable;
	
public:
	Product();
	Product(string Barcode);
	virtual ~Product();
	virtual string getName(){return _name;}
	virtual string getCategory(){return _category;}
	virtual string getBarcodeNum(){return _barcodeNum;}
	virtual string getManufacturer(){return _manufacturer;}
	virtual int getNumInStock(){return _numInStock;}
	virtual int getNumSoldPerMonth(){return _numSoldPerMonth;}
	virtual double getPrice(){return _price;}
	virtual bool checkPerishable(){return _perishable;}
	virtual void printProduct();
	virtual bool setName(string);
	virtual bool setCategory(string);
	virtual bool setBarcodeNum(string);
	virtual bool setManufacturer(string);
	virtual bool setNumInStock(int);
	virtual bool setNumSoldPerMonth(int);
	virtual bool setPrice(double);
	virtual bool setPerishable(bool);
	virtual bool checkExpired(){ return false;}
	//using streamstring to construct string
	virtual int* getExpiryDate(){return NULL;}
	virtual double getDiscountPercentage(){return -1.0;}
	//virtual ComparatorProduct<Product*> getComparator(){return COM;}
	virtual bool setExpiryDate(int*){return false;}
	virtual bool setDiscountPercentage(double){return false;}

};

#endif