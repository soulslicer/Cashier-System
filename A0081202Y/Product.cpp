#include "Product.h"
#include <string>
#include<iostream>
using namespace std;

Product::Product()//default constructor
{
	_name=string("");
	_manufacturer=string("");
	_category=string("");
	_barcodeNum=string("");
	_numInStock=_numSoldPerMonth=0;
	 _price=0;
	 _perishable=false;
}

Product::Product(string Barcode)//set barcode
{
	_name=string("");
	_manufacturer=string("");
	_category=string("");
	_barcodeNum=Barcode;
	_numInStock=_numSoldPerMonth=0;
	 _price=0;
	 _perishable=false;
}

Product::~Product(){}//destructor


bool Product::setNumInStock(int Num)//check if is in stock
{
	if(Num<0)
		return false;
	else
	{
		_numInStock=Num;
		return true;
	}
}


bool Product::setNumSoldPerMonth(int Num)//set
{
	if(Num<0)//input guard
		return false;
	else
	{
		_numSoldPerMonth=Num;
		return true;
	}
}

 bool Product::setPrice(double Price)//set 
 {
	if(Price<0)//input guard
		return false;
	else
	{
		_price=Price;
		return true;
	}
 }

 void Product::printProduct()//output
 {
	cout<<"Type: Non-Perishable Product\n";
	cout<<"Name: "<<_name<<endl;
	cout<<"Barcode Number: "<<_barcodeNum<<endl;
	cout<<"Category: "<<_category<<endl;
	cout<<"Manufacturer: "<<_manufacturer<<endl;
	cout<<"Price: "<<_price<<endl;
	cout<<"Number in Stock: "<<_numInStock<<endl;
	cout<<"Number Sold Per Month: "<<_numSoldPerMonth<<endl;
 }

bool Product::setName(string name)//set
{
	if(name=="")//input guard
		return false;
	else
		_name=name;
	return true;
}

bool Product::setCategory(string cate)//set
{
	if(cate=="")//input guard
		return false;
	else
		_category=cate;
	return true;	
}

bool Product::setBarcodeNum(string barcode)//set
{
	if(barcode=="")//input guard
		return false;
	else
		_barcodeNum=barcode;
	return true;
}

bool Product::setManufacturer(string manu)//set
{
	if(manu=="")//input guard
		return false;
	else
		_manufacturer=manu;
	return true;
}

bool Product::setPerishable(bool p)//signals is a perishable product
{
	_perishable= p;
	return true;
}