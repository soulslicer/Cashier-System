#include "PerishableProduct.h"
#include <iostream>
#include <time.h>

void PerishableProduct::printProduct()//print perisable product
 {
	cout<<"Type: Perishable Product\n";
	cout<<"Name: "<<_name<<endl;
	cout<<"Barcode Number: "<<_barcodeNum<<endl;
	cout<<"Category: "<<_category<<endl;
	cout<<"Manufacturer: "<<_manufacturer<<endl;
	cout<<"Price: "<<_price<<endl;
	cout<<"Number in Stock: "<<_numInStock<<endl;
	cout<<"Number Sold Per Month: "<<_numSoldPerMonth<<endl;
	cout<<"Expiry Date: ";
	if(expiryDate[0]>10)
	cout<<expiryDate[0]<<"/ ";
	else
		cout<<0<<expiryDate[0]<<"/ ";
	if(expiryDate[1]>10)
		cout<<expiryDate[1]<<"/ ";
	else
		cout<<0<<expiryDate[1]<<"/ ";
	cout<<expiryDate[2]<<endl;
	cout<<"Discount Percentage: "<<_discountPercentage<<"%"<<endl;
 }
PerishableProduct::PerishableProduct()//constructor
{
	expiryDate[0]=0;
	expiryDate[1]=0;
	expiryDate[2]=0;
	_discountPercentage=0;
}

PerishableProduct::PerishableProduct(string Barcode):Product(Barcode)//set barcode 
{
	expiryDate[0]=0;
	expiryDate[1]=0;
	expiryDate[2]=0;
	_discountPercentage=0;
}

int* PerishableProduct::getExpiryDate()//return expiry date value
{
	return &expiryDate[0];
}

double PerishableProduct::getDiscountPercentage()
{
	return _discountPercentage;
}

bool PerishableProduct::setExpiryDate(int* date)
{
	//check if date is valid
	if(date[0]<32 && date[0]>0 && date[1]>0 && date[1]<13 &&date[2]>0)
	{
		bool leap;
		if(date[2]%4==0)
		{
			if(date[2]%400==0)
				leap=true;
			else if(date[2]%100==0)
				leap=false;
			else leap=true;
		}
		else leap=false;
		switch(date[1])
		{
		case 2: 
			if(leap && date[0]>29)
				return false;
			else 
				if(!leap && date[0]>28)
					return false;
			else
				{
				expiryDate[0]=date[0];
				expiryDate[1]=date[1];
				expiryDate[2]=date[2];
				return true;
				}
			
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(date[0]>30)
				return false;
			else
			{
				
				expiryDate[0]=date[0];
				expiryDate[1]=date[1];
				expiryDate[2]=date[2];
				return true;
			}

			break;
		default:
			expiryDate[0]=date[0];
			expiryDate[1]=date[1];
			expiryDate[2]=date[2];
			return true;
		}
	}
	else return false;
}
bool PerishableProduct::setDiscountPercentage(double Percentage)
{
	if(Percentage>100 || Percentage<0)//input guaard
		return false;
	else
	{
		_discountPercentage=Percentage;
		return true;
	}
}
bool PerishableProduct::checkExpired()
{
	time_t curtime=time(0); 
	tm tim =*localtime(&curtime); 
	int day,mon,year; 
	day=tim.tm_mday;
	mon=tim.tm_mon;
	year=tim.tm_year;//get current time
	
	//comparision
	if(expiryDate[2]> year)
		return true;
	if(expiryDate[2]== year && expiryDate[1]> mon)
		return true;
	if(expiryDate[2]== year && expiryDate[1]==mon && expiryDate[0]>day )
		return true;

	return false;
}

