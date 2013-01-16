#ifndef JOBS_H
#define JOBS_H
#include <string>
#include"Functionality.h"

using namespace std;

enum Code{ADD,DELETE,RESTOCK,DISPOSE,SALE};
class JobBase
{
protected:
	Code job;
	string barcodeNum; 
public:
	virtual Code getJob()=0;
	virtual void setJob(Code) =0;
	virtual string getBarcodeNum() =0;
	virtual void setBarcodeNum(string) =0;
	//virtual stringstream getValue(string)=0;
	virtual bool execute(Functionality*)=0;
	virtual string jobType()=0;

};

class AddJob: public JobBase
{
private:
	string name,category,manufacturer;
	double price;
	int numInStock;	
public:
	AddJob(){}
	AddJob(string bar){barcodeNum=bar;}
	Code getJob(){return job;}
	string getBarcodeNum(){return barcodeNum;}
	string getName(){return name;}
	string getCategory(){return category;}
	string getManufacturer(){return manufacturer;}
	int getNumInStock(){ return numInStock;}
	double getPrice(){return price;}
	void setPrice(double P){price=P;return;}
	void setJob(Code C){job=C;return;}
	void setBarcodeNum(string bar){barcodeNum=bar;return;}
	void setName(string N){name=N;return;}
	void setCategory(string C){category=C;return;}
	void setManufacturer(string M){manufacturer=M;return;}
	void setNumInStock(int N){numInStock=N;return;}
	bool execute(Functionality* F)
	{
		Product* p = new Product(barcodeNum);
		p->setCategory(category);
		p->setManufacturer(manufacturer);
		p->setName(name);
		p->setPrice(price);
		p->setNumInStock(numInStock);
		p->setPerishable(false);
		p->setNumSoldPerMonth(0);

		if(F->addNewProduct(p,false))
			return true;
		else 
			return false;
	}
	string jobType(){return string("ADD");}
};

class DeleteJob: public JobBase
{
public:
	DeleteJob(){}
	DeleteJob(string bar){barcodeNum=bar;}
	Code getJob(){return job;}
	string getBarcodeNum(){return barcodeNum;}
	void setJob(Code C){job=C;return;}
	void setBarcodeNum(string bar){barcodeNum=bar;return;}
	bool execute(Functionality* F)
	{
		if(!(F->searchByBarcodeNum(barcodeNum))) return false;
		else 
		{
			if (F->deleteProduct(F->getIndexes()[0])) return true;
			else return false;
		}

	}
	string jobType(){return string("DELETE");}
};

class DisposeJob: public JobBase
{
	string currentDate;
public:
	DisposeJob(){}
	DisposeJob(string bar){barcodeNum=bar;}
	Code getJob(){return job;}
	string getBarcodeNum(){return barcodeNum;}
	void setJob(Code C){job=C;return;}
	void setBarcodeNum(string bar){barcodeNum=bar;return;}
	void setCurrentDate(string D){currentDate=D;return;}
	bool execute(Functionality* F)
	{
		if(!(F->searchByBarcodeNum(barcodeNum)))return false;
		if(F->checkExpired(barcodeNum,currentDate) ==1)
		{
			if(F->deleteProduct(F->getIndexes()[0]))
			return true;
			else return false;
		}
		else return false;

	}
	string jobType(){return string("DISPOSE");}
};

class RestockJob: public JobBase
{
private:
	int numToStock;
	
public:
	RestockJob(){}
	RestockJob(string bar){barcodeNum=bar;}
	Code getJob(){return job;}
	string getBarcodeNum(){return barcodeNum;}
	int getNumToStock(){return numToStock;}
	void setJob(Code C){job=C;return;}
	void setBarcodeNum(string bar){barcodeNum=bar;return;}
	void setNumToStock(int N){numToStock=N;return;}
	bool execute(Functionality* F)
	{
		if(!(F->searchByBarcodeNum(barcodeNum))) return false;
		else
		{
			if(F->restockProduct(F->getIndexes()[0],numToStock))
				return true;
			else return false;
		}
	}
	string jobType(){return string("RESTOCK");}

};

class SaleJob: public JobBase
{
private:
	int numSold;

public:
	SaleJob(){}
	SaleJob(string bar){barcodeNum=bar;}
	Code getJob(){return job;}
	string getBarcodeNum(){return barcodeNum;}
	int getNumSold(){return numSold;}
	void setJob(Code C){job=C;return;}
	void setBarcodeNum(string bar){barcodeNum=bar;return;}
	void setNumSold(int N){numSold=N;return;}
	bool execute(Functionality* F)
	{
		if(!(F->searchByBarcodeNum(barcodeNum)))return false;
		else
		{
			if(F->sellProduct(F->getIndexes()[0],numSold,F->getUserName()))
				return true;
			else return false;
		}
	}
	string jobType(){return string("SALE");}
};

#endif