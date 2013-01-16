#ifndef COMPARATORPRODUCT_H
#define COMPARATORPRODUCT_H
#include"Product.h"
#include "ComparatorBase.h"

template <class T>
class ComparatorProduct: public ComparatorBase<T>
{
public:
	bool Compare(T item1,T item2)
	{
		if(item1->getCategory()<item2->getCategory())
		{
			return true;
		}
		
	else return false;
	}

	bool cheap(T item1,T item2)
	{
		if(item1->getPrice() <= item2->getPrice())
			return true;
		else return false;
	}

	bool lessStock(T item1, T item2)
	{
		if((item1->getPrice() * item1->getNumInStock()) <= (item2->getPrice()* item2->getNumInStock()))
			return true;
		else return false;
	}
	
	bool Compare2(T item1,T item2)
	{
		//cout<<item1->getCategory()<<" and "<<item2->getCategory()<<endl;
		if(item1->getCategory()<=item2->getCategory())
		{
			//cout<<item1->getCategory()<<" <= "<<item2->getCategory()<<endl;
			return true;
		}
		
	else return false;
	}

	char FirstLetter(T item)
	{
		string x= item->getCategory();
		return x[0];
	}

	char FirstLetter(T item,int searchstate)
	{
		string x;
		switch(searchstate)
		{
		case 1:
			x= item->getCategory();
			break;
		case 2:
			x= item->getName();
			break;
		case 3:
			x= item->getManufacturer();
			break;
		}

		return x[0];
	}

	bool CompareName(T item1,T item2)
	{
		//cout<<item1->getCategory()<<" and "<<item2->getCategory()<<endl;
		if(item1->getName()<=item2->getName())
		{
			//cout<<item1->getCategory()<<" <= "<<item2->getCategory()<<endl;
			return true;
		}
		
	else return false;
	}

	bool CompareManufac(T item1,T item2)
	{
		//cout<<item1->getCategory()<<" and "<<item2->getCategory()<<endl;
		if(item1->getManufacturer()<=item2->getManufacturer())
		{
			//cout<<item1->getCategory()<<" <= "<<item2->getCategory()<<endl;
			return true;
		}
		
	else return false;
	}
};
#endif