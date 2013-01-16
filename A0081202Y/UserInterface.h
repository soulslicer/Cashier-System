#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <string>
#include "Functionality.h"
#include "ProductDoubleLinkedList.h"
using namespace std;

class UserInterface
{
	private:
		Functionality functions;
		string FileName,UserName;
	public:
		UserInterface();
		UserInterface(string,string);
		string getUserFile();
		void Manager_Menu();
		void Cashier_Menu();
		void addNewProduct_Menu();
		void addNewNon_PerishableProduct_Menu();
		void addNewPerishableProduct_Menu();
		void deleteProduct_Menu();
		void resetProductSales_Menu();
		void resetIndividualProductSale_Menu();
		void sellProduct_Menu();
		void restockProduct_Menu();
		void generateStatistics_Menu();
		void listAllProducts_Menu();
		void checkExpired();
		void loadInData();
		int genericSearch_Menu(string);//return -1 if something wrong
		void editProducts_Menu();
		void batchProcessing();
		void saleHistory_Menu(char);
		void adduser_Menu();
};

#endif