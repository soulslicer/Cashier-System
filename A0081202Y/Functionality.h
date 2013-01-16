#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H
#include "Sort_Vector.h"
#include "Queue.h"
#include "Product.h"
#include "ProductListSorted.h"
#include "ProductDoubleLinkedList.h"
#include "ProductListArray.h"
#include "ProductVectorList.h"
#include <string>
#include <vector>
#include <ctime>


using namespace std;

class Functionality
{
private:
	struct Top
	{
		double amount;
		Queue<int> indexQ; 
	};
	struct container
	{
		string str;
		double amount;
	};
	vector<int> Indexes;
	string UserName;
	ProductVectorList<Product*> List;
	//ProductDoubleLinkedList<Product*> List;
	//ProductListArray<Product*> List;
	//ProductListSorted<Product*> List;
	//Sort_Vector<Product*> List;
public:
	 //ProductListSorted<Product*>& getList(){return List;}
	 ProductVectorList<Product*>& getList(){return List;}
	 //ProductDoubleLinkedList<Product*>& getList(){return List;}
	 //ProductListArray<Product*>& getList(){return List;}
	 //Sort_Vector<Product*>& getList(){return List;}
	 string getUserName();
	 bool searchByName(string Name) ;
	 bool searchByCategory(string Category) ;
	 bool searchByManufacturer(string Manufacturer) ;
	 bool searchByBarcodeNum(string Barcode) ;
	 bool addNewProduct(Product* NewItem,bool load) ;
	 bool deleteProduct(int index) ;
	 bool resetProductSales() ;
	 bool resetIndividualProductSale(int index) ;
	 bool sellProduct(int index,int& num,string UserFile) ;
	 bool restockProduct(int index,int& num) ;
	 bool saveDataToFile(string FileName) ;
	 bool loadInData(string FileName) ;
	 void getHighest(int X) ;
	 int getHighestInOneCategory(string Name) ;
	 int checkExpired(int index); 
     int checkExpired(string barcode,string curretDate);
	 bool batchProcessing(string inFile,string outFile);
	 void listAllProduct() ;
	 string bestManufacturer() ;
	 void printProduct(int index) ;
	 vector<int> getIndexes();
	 bool checkDate(int day, int month, int year);
	 string getInfo(bool& Perishable,int index);
	 bool editProducts(int choice,int index,string propertys);
	 void printFile(string);
	 void saleHistory(string); 
	 void Adduser(string name, string pass ,char type);
	 void sortByWorth();

	// bool saving(string FileName); creates 1000 dummy products
	 

};

#endif