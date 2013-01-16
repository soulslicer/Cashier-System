#include "UserInterface.h"
#include "Product.h"
#include "PerishableProduct.h"
#include "ListBase.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

UserInterface::UserInterface():FileName(""),UserName("")//file name
{
}


UserInterface::UserInterface(string FN,string UN):FileName(FN),UserName(UN)//file name
{
}


void UserInterface::Manager_Menu()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		//output on screen
		cout<<setfill('-')<<setw(80)<<""<<endl;//fillers
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<"|0. Add New Product\n";
		cout<<"|1. Delete Product\n";
		cout<<"|2. Edit Product\n";
		cout<<"|3. Reset Product Sales\n";
		cout<<"|4. Sell Product\n";
		cout<<"|5. Restock Product\n";
		cout<<"|6. Generate Statistics\n";
		cout<<"|7. List All Products\n";
		cout<<"|8. Load Data\n";
		cout<<"|9. Check Expiry\n";
		cout<<"|A. Batch Processing\n";
		cout<<"|B. Sale History\n";
		cout<<"|C. Add New User\n";
		cout<<"|D. Sort By Worth\n";
		cout<<"|Q. Quit\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;//fillers
		cout<<"\n";
		cout<<"Please input your choice(0-B): ";

		char choice;

		choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		

		switch(choice)
		{
		case '0':
			//option 1. add product 
			addNewProduct_Menu();
			break;
		
		case '1':
			//option 2. delete product
			deleteProduct_Menu();
			break;
		case '2':
			editProducts_Menu();
			break;
		
		case '3':
			//option 3. reset sales
			resetProductSales_Menu();
			break;
			
		case '4':
			//option 4. sell product
			sellProduct_Menu();
			break;

		case '5':
			//option 5. restock
			restockProduct_Menu();
			break;

		case '6':
			//option 6. output
			generateStatistics_Menu();
			break;
		case '7':
			//print all to screen
			listAllProducts_Menu();
			break;

		case '8':
			//load from file
			loadInData();
			break;

		case '9':
			//search for product and check if expired
			checkExpired();
			break;
		case 'A':case 'a':
			batchProcessing();
			break;

		case 'B':case 'b':
			saleHistory_Menu('M');
			break;
		case 'C': case 'c':
			adduser_Menu();
			break;
		case 'D': case 'd':
			functions.sortByWorth();
			break;
			
		case 'Q':case 'q':
			//save all data
			cout<<"Do you want to saves changes? (Y/N): ";
			cin>>choice;
			if(choice=='y' || choice=='Y')
			{
				if(functions.saveDataToFile(FileName))
				cout<<"Data save successfully, press enter to leave.";
				getchar();
			}
			 x=0; //to exit the loop
			break;
		default: //failsafe

			cout<<"there is no such command\n";
			getchar();
		}
		//cin.ignore(1000,'\n');
	}
	return;
}

void UserInterface::Cashier_Menu()
{
	int x=1; 

	//load from file
	loadInData();
	cout<<endl<<endl<<endl<<endl;

	while(x==1)//infinite loop. step out if quit
	{
		//output on screen
		cout<<setfill('-')<<setw(80)<<""<<endl;//fillers
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<"|1. Sell Product\n";
		cout<<"|2. Restock Product\n";
		cout<<"|3. List All Products\n";
		cout<<"|4. Check Expiry\n";
		cout<<"|Q. Quit\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;//fillers
		cout<<"\n";
		cout<<"Please input your choice(1-4): ";

		char choice;

		choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		

		switch(choice)
		{
		case '1':
			//option 4. sell product
			sellProduct_Menu();
			break;
		
		case '2':
			//option 5. restock
			restockProduct_Menu();
			break;

		case '3':
			//print all to screen
			listAllProducts_Menu();
			break;
		
		case '4':
			//search for product and check if expired
			checkExpired();
			break;
		case '5':
			saleHistory_Menu('C');
			break;
			
		case 'Q':case 'q':
			//save all data
			cout<<"Do you want to saves changes? (Y/N): ";
			cin>>choice;
			if(choice=='y' || choice=='Y')
			{
				if(functions.saveDataToFile(FileName))
				cout<<"Data save successfully, press enter to leave.";
				getchar();
			}
			 x=0; //to exit the loop
			break;
		
		default: //failsafe

			cout<<"there is no such command\n";
			getchar();
		}
	}
	return;
}


void UserInterface::addNewProduct_Menu()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		cout<<"\n\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Add New Product\n\n";
		
		cout<<"|1. Add New Non-perishable Product\n";
		cout<<"|2. Add New Perishable Product\n";
		cout<<"|3. Return to main menu\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"\n";
		cout<<"Please input your choice(1-3): ";
		

		char choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		
		switch (choice)
		{

		case '1':
			//menu option 1. add product
			addNewNon_PerishableProduct_Menu();
			break;

		case '2':
			//menu option 2. add perishable product
			addNewPerishableProduct_Menu();
			break;

		case '3':
			x=0; //to exit the loop
			break;

		default: //failsafe
			cout<<"there is no such command\n";
			getchar();
			getchar();
		}

	return;
	}
}


void UserInterface::addNewNon_PerishableProduct_Menu()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		cout<<"\n\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Add New Non-perishable Product\n\n";

		//run create new product
		//just for presentation
		string name,cate,barNo,manu;
		double price;
		int stock,NSPM=0;
        cout << "Please Enter Name: ";
		getline(cin,name);
		cout<<"Please Enter Category: ";
		getline(cin,cate);
		cout<<"Please Enter Barcode Number: ";
		getline(cin,barNo);
		cout<<"Please Enter Manufacturer: ";
		getline(cin,manu);
		cout<<"Please Enter Price: ";
		cin>>price;
		cout<<"Please Enter Number in Sctock of This Product: ";
		cin>>stock;
		Product* newPtr= new Product(barNo);
		newPtr->setName(name);
		newPtr->setPerishable(false);
		newPtr->setCategory(cate);
		newPtr->setPrice(price);
		newPtr->setManufacturer(manu);
		newPtr->setNumInStock(stock);
		newPtr->setNumSoldPerMonth(NSPM);
		clock_t startTime = clock(); //Do this right before invoking the function
		bool check=functions.addNewProduct(newPtr,false);
		clock_t endTime = clock();  //Do this right after the function returns
		cout<<"Elapsed time:";
		cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
		if(check)
			cout<<"Product "<<name<<" with Barcode Number "<<barNo<<" Added Successfully"<<endl;
		else 
			cout <<"Product Add Unsuccessfully\n";
        //end here
        cin.ignore(1000,'\n');
		cout<<"Do you wish to add more Non-perishable Product? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps
		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		
	}
}


void UserInterface::addNewPerishableProduct_Menu()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		bool y=false;
		cout<<"\n\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Add New perishable Product\n\n";

		//run create new non-perishable product
		//just for presentation
		string name,cate,barNo,manu;
		double price,discount;
		int stock,d[3],NSPM=0;
        cout << "Please Enter Name: ";
		getline(cin,name);
		cout<<"Please Enter Category: ";
		getline(cin,cate);
		cout<<"Please Enter Barcode Number: ";
		getline(cin,barNo);
		cout<<"Please Enter Manufacturer: ";
		getline(cin,manu);
		cout<<"Please Enter Price: ";
		cin>>price;
		cout<<"Please Enter Number in Sctock of This Product: ";
		cin>>stock;
		do
		{
			cout<<"Please Enter Expiry Date(DD MM YYYY): ";
			cin>>d[0]>>d[1]>>d[2];
			if(!functions.checkDate(d[0],d[1],d[2]))
			{
				cout<<"Invalid Date!Please check and enter again.\n";
				y=true;
			}
		}while(y);
		cout<<"Please Enter Discount Percentage(eg.50% input 50): ";
		cin>>discount;
		PerishableProduct* newPtr= new PerishableProduct(barNo);
		newPtr->setName(name);
		newPtr->setPerishable(true);
		newPtr->setCategory(cate);
		newPtr->setPrice(price);
		newPtr->setManufacturer(manu);
		newPtr->setNumInStock(stock);
		newPtr->setNumSoldPerMonth(NSPM);
		newPtr->setExpiryDate(d);
		newPtr->setDiscountPercentage(discount);
		clock_t startTime = clock(); //Do this right before invoking the function
		bool check=functions.addNewProduct(newPtr,false);
		clock_t endTime = clock();  //Do this right after the function returns
		cout<<"Elapsed time:";
		cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
		
		if(check)
			cout<<"Perishable Product "<<name<<" with Barcode Number "<<barNo<<" Added Successfully"<<endl;
		else
			cout <<"Product Add Unsuccessfully\n";

        cin.ignore(1000,'\n');
		cout<<"Do you wish to add more perishable Product? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps

		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		
	}
}


void UserInterface::deleteProduct_Menu()
{
	int x=1; 
	
	while(x==1)//infinite loop. step out if quit
	{
		//genericSearch_Menu();
		int index=genericSearch_Menu("Delete Product");
		 if (index==-3)
		{
				cout<<"No Product was found\n";
				cout<<"Do you wish to DELETE other Products? (Y/N) "<<endl;
				char choice = toupper( getchar() ); //read choice and convert to caps
				cin.ignore(1000,'\n');//clear the buffer

				if(choice!='Y')
					x=0; //to exit the loop
		}
		else if (index!=-2)
		{
			clock_t startTime = clock(); //Do this right before invoking the function
			bool check=functions.deleteProduct(index);
			clock_t endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;

			if(check)
			{
				functions.printProduct(functions.getIndexes()[0]);
				cout<<"Delete successful\n";
				cout<<"Do you wish to DELETE more Products? (Y/N) "<<endl;

				char choice = toupper( getchar() ); //read choice and convert to caps
			
				cin.ignore(1000,'\n');//clear the buffer

				if(choice!='Y')
					x=0; //to exit the loop
		
			}
			else cout<<"Delete Unsuccessful\n";
		 }
			else if(index==-2)
				x=0;
	}

	return;
}


void UserInterface::editProducts_Menu()
{
    int error=0;//error 1: Prod not found
    int loop=1;
    int* junk=NULL;
    //string junk="A";
    bool check=true;
    
    while(loop==1)
    {
        //genericSearch_Menu();
		int index=genericSearch_Menu("Edit Product");//Calls the search Menu either way
        if (index==-3)
		{
            cout<<"No Product was found\n";
            cout<<"Do you wish to edit other Products? (Y/N) "<<endl;
            char choice = toupper( getchar() ); //read choice and convert to caps
            cin.ignore(1000,'\n');//clear the buffer
            
            if(choice!='Y')
                loop=0; //to exit the loop
		}
        else if (index!=-2)
		{
			bool Perishable; string Name;
			Name=functions.getInfo(Perishable,index);
            
            int loop2=0;
            while(loop2==0){
				cout<<endl;
				cout<<"You are now editing Product: "<<Name<<endl;
                
                //Code to edit if Product is NP
                cout<<"|1. Edit Name:"<<endl;
                cout<<"|2. Edit Barcode:"<<endl;
                cout<<"|3. Edit Category:"<<endl;
                cout<<"|4. Edit Manufacturer:"<<endl;
                cout<<"|5. Edit Price:"<<endl;
                
                if(Perishable)
                {
                    cout<<"|6. Edit ExpiryDate:"<<endl;
                    cout<<"|7. Edit Discount:"<<endl;
                }
                
                cout<<"|8. Return to Previous Menu"<<endl;
                
                cout<<"Please Enter Choice: ";
                int choice; cin>>choice;
				cin.ignore(1000,'\n');
                choice= toupper(choice);
                
                switch(choice)//CREATE LOOPS TO REENTER INFORMATION
                {
                    case 1:{
                        string propertys;
						cout<<" Enter Name:"; cin>>propertys;
						check=functions.editProducts(choice,index,propertys);
						if(check==false)
							cout<<"Error with Name"<<endl;
                        break;}
                    case 2:{
                        string propertys;
						cout<<" Enter Barcode:"; cin>>propertys;
						check=functions.editProducts(choice,index,propertys);
						if(check==false)
							cout<<"Error with Barcode"<<endl;
                        break;}
                    case 3:{
                        string propertys;
						cout<<" Enter Category:"; cin>>propertys;
						check=functions.editProducts(choice,index,propertys);
						if(check==false)
							cout<<"Error with Category"<<endl;
                        break;}
                    case 4:{
                        string propertys;
						cout<<" Enter Manufacturer:"; cin>>propertys;
						check=functions.editProducts(choice,index,propertys);
						if(check==false)
							cout<<"Error with Manufacturer"<<endl;
                        break;}
                    case 5:{
                        string propertys;
						cout<<" Enter Price:"; cin>>propertys;
						check=functions.editProducts(choice,index,propertys);
						if(check==false)
							cout<<"Error with Price"<<endl;
                        break;}
                    case 6:{
                        string propertys;
						cout<<" Enter Date DD MM YYYY:"; cin>>propertys;
						check=functions.editProducts(choice,index,propertys);
						if(check==false)
							cout<<"Error with Date"<<endl;
                        break;}
                    case 7:{
                        string propertys;
						cout<<" Enter Discount:"; cin>>propertys;
						check=functions.editProducts(choice,index,propertys);
						if(check==false)
							cout<<"Error with Discount"<<endl;
                        break;}
					case 8:
						loop2=1;
						break;
                    default:
                        break;
                    
                }//switchend
                
                if(check)
					cout<<"EDIT SUCCESSFUL"<<endl;
                
            }//whileloopend
    
        }//ifend
		else if(index==-2)
            break;
        
        
    }//whileloop end

}


void UserInterface::resetProductSales_Menu()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		cout<<"\n\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Reset Product Sales\n\n";

		cout<<"|1. Reset all\n";
		cout<<"|2. Reset individual\n";
		cout<<"|3. Return to main menu\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<"\n";
        cout<<"please input your choice(1-3): ";
		char choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		
		switch (choice)
		{

		case '1':
			//reset all
			//x=0;
			if(functions.resetProductSales())
				cout<<"Reset successfully\n";
			break;

		case '2':
			//option 2. reset individual
			resetIndividualProductSale_Menu();
			break;

		case '3':
			x=0; //to exit the loop
			break;

		default: //failsafe
			cout<<"there is no such command\n";
			getchar();
			getchar();
		}
		
	return;
	}
}


void UserInterface::resetIndividualProductSale_Menu()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		int index=genericSearch_Menu(" Reset individual Product Sales");
		if (index==-3)
		{
				cout<<"No Product was found\n";
				cout<<"Do you wish to Reset other Products? (Y/N) "<<endl;
				char choice = toupper( getchar() ); //read choice and convert to caps
				cin.ignore(1000,'\n');//clear the buffer

				if(choice!='Y')
					x=0; //to exit the loop
		}
		else if (index!=-2)
		{
			bool check= functions.resetIndividualProductSale(index);
			
			if(check)
			{
				cout<<"Reset successful\n";
				cout<<"Do you wish to Reset more Products? (Y/N) "<<endl;

				char choice = toupper( getchar() ); //read choice and convert to caps
			
				cin.ignore(1000,'\n');//clear the buffer

				if(choice!='Y')
					x=0; //to exit the loop
		
			}
			else cout<<"Reset Unsuccessful\n";
		 }
			else 
				x=0;
		}
       
	return;
	
}


void UserInterface::sellProduct_Menu()
{
	int x=1,num,index;

	while(x==1)//infinite loop. step out if quit
	{
		index=genericSearch_Menu("sell Product");
		if (index==-3)
		{
				cout<<"No Product was found\n";
				cout<<"Do you wish to Sell other Products? (Y/N) "<<endl;
				char choice = toupper( getchar() ); //read choice and convert to caps
				cin.ignore(1000,'\n');//clear the buffer

				if(choice!='Y')
					x=0; //to exit the loop
		}
		else if (index!=-2)
		{
			cout<<"Number to sell: ";
			cin>>num;
			cin.ignore(1000,'\n');//clear the buffer
			clock_t startTime = clock(); //Do this right before invoking the function
			bool check = functions.sellProduct(index,num,UserName);
			clock_t endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			
			if(check)
			{
			cout<<"Do you need to sell another Product ? (Y/N) "<<endl;

			char choice = toupper( getchar() ); //read choice and convert to caps

		
			cin.ignore(1000,'\n');//clear the buffer

			if(choice!='Y')
				x=0; //to exit the loop
		}
		}
		else 
			x=0;
	}	
	return;
	
}


void UserInterface::restockProduct_Menu()
{
	int x=1,index, num=0;

	while(x==1)//infinite loop. step out if quit
	{
		index=genericSearch_Menu(" Restock Product");
		if (index==-3)
		{
				cout<<"No Product was found\n";
				cout<<"Do you wish to Restock other Products? (Y/N) "<<endl;
				char choice = toupper( getchar() ); //read choice and convert to caps
				cin.ignore(1000,'\n');//clear the buffer

				if(choice!='Y')
					x=0; //to exit the loop
		}
		else if (index!=-2)
		{
			cout<<"Number to restock: ";
			cin>>num;
			cin.ignore(1000,'\n');
			clock_t startTime = clock(); //Do this right before invoking the function
			bool check = functions.restockProduct(index,num);
			clock_t endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			
			//cin.ignore(1000,'\n');//clear the buffer
			if(check)
			{
			cout<<"Do you wish to Restock other Products? (Y/N) "<<endl;

			char choice = toupper( getchar() ); //read choice and convert to caps

		
			cin.ignore(1000,'\n');//clear the buffer

			if(choice!='Y')
				x=0; //to exit the loop
			}
		}
		else
			x=0;
	}

	return;
	
}


void UserInterface::generateStatistics_Menu()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		cout<<"\n\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Generate statistics\n\n";

		
		cout<<"|1. Top X selling product\n";
		cout<<"|2. Best selling product in 1 given category\n";
		cout<<"|3. Best selling manufacturer\n";
		cout<<"|4. Return to main menu\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<"\n";
		cout<<"Please input your choice(1-4): ";

		char choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer

		string str;
		switch (choice)
		{
			clock_t startTime;
			clock_t endTime;
		case '1':
			int y;
			cout<<"X= ";
			cin>>y;
			startTime = clock(); //Do this right before invoking the function
			functions.getHighest(y);
			endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			
			break;

		case '2':
			cout<<"Please enter category you want: ";
			getline(cin,str);
			startTime = clock(); //Do this right before invoking the function
			functions.printProduct(functions.getHighestInOneCategory(str));
			endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			functions.printProduct(functions.getHighestInOneCategory(str));
			//menu option 2. best selling in category
			break;

		case '3':
			startTime = clock(); //Do this right before invoking the function
			str=functions.bestManufacturer();
			endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			cout<<str<<endl;
			//menu option 3. best selling in manufacturer
			break;

		case '4':
			x=0; //to exit the loop
			break;

		default: //failsafe
			cout<<"there is no such command\n";
			getchar();
			getchar();
		}
		//cin.ignore(1000,'\n');
		if(x!=0)
		{
		cout<<"Do you wish to see other Product Sales? (Y/N) "<<endl;

		cin.ignore(1000,'\n');
		char choice = toupper( getchar() ); //read choice and convert to caps

		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		}
	}
	
	return;
	
}


void UserInterface::listAllProducts_Menu() //list all products
{
    //For now lists only Products of non-peri
    cout << "Output Products" << endl;
	
	clock_t startTime = clock(); //Do this right before invoking the function
	functions.listAllProduct();
	clock_t endTime = clock();  //Do this right after the function returns
	cout<<"Elapsed time:";
	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
	

}


void UserInterface::checkExpired()
{
	int x=1,index;
	while(x==1)
	{
		int check;
		index=genericSearch_Menu("Check if product has been expired");
		 if (index==-3)
		{
				cout<<"No Product was found\n";
				cout<<"Do you wish to check other Products? (Y/N) "<<endl;
				char choice = toupper( getchar() ); //read choice and convert to caps
				cin.ignore(1000,'\n');//clear the buffer

				if(choice!='Y')
					x=0; //to exit the loop
		}
		else if(index!=-2)
		{
			clock_t startTime = clock(); //Do this right before invoking the function
			check = functions.checkExpired(index);
			clock_t endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
					
		    //cin.ignore(1000,'\n');//clear the buffer
			if(check==1)
			{
				cout<<"The Product is Expired.\n";
			
			}
			else if(check==0)
			{
				cout<<"The Product is NOT¡¡Expired.\n";
			
			  }
			else if(check==-1)
			{
				cout<<"The product is Non-Perishable, there is no expiry date.\n";
			 }
			cout<<"Do you wish to check more Products? (Y/N): ";
				cin.ignore(1000,'\n');
				char choice = toupper( getchar() ); //read choice and convert to caps
				if(choice!='Y')
					x=0; //to exit the loop
		}
		
		else x=0;
	}

	return;
	
	
}


int UserInterface::genericSearch_Menu(string T)//inputs a string and returns a pointer to the list node
{
	//menu
	cout<<setfill('-')<<setw(80)<<""<<endl;
	cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
	cout<<setfill('-')<<setw(80)<<""<<endl;

	cout<<T<<"\n\n";

	cout<<"|1. Search by categeory\n";
	cout<<"|2. Search by name\n";
	cout<<"|3. Search by barcode number\n";
	cout<<"|4. Search by manufacturer\n";
	cout<<"|5. Quit to Main menu\n";
	cout<<setfill('-')<<setw(80)<<""<<endl;

	//NEED A SCREEN REFRESH
	cout<<"\n";
	cout<<"Please input your choice(1-5): ";

	//x is placeholder incase of default input
	int x;
	char choice;
	do
	{
		x=0;//always assume correct
		choice=getchar();
		cin.ignore(1000,'\n');//clear the buffer
		string str;

		switch (choice)
		{
			clock_t startTime;
			clock_t endTime;
			bool check;
		case '1':
			cout<<"Please enter the Category: ";
			getline(cin,str);
			startTime = clock(); //Do this right before invoking the function
			check=functions.searchByCategory(str);
			endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			
			if(check)
			{
				cout<<"Please input the index of the product you want to operate on: ";
				cin>>choice;
				cin.ignore(1000,'\n');
				return functions.getIndexes()[static_cast<unsigned>(choice-'0'-1)];
			}
			else return -3;

		case '2':
			cout<<"Please enter the Name: ";
			getline(cin,str);
			startTime = clock(); //Do this right before invoking the function
			check=functions.searchByName(str);
			endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			if(check)
			{
				cout<<"Please input the index of the product you want to operate on: ";
				cin>>choice;
				cin.ignore(1000,'\n');
				return (functions.getIndexes())[static_cast<unsigned>(choice-'0'-1)];
			}
			else
			return -3;
		case '3':
			cout<<"Please enter the Barcode Number: ";
			getline(cin,str);
			startTime = clock(); //Do this right before invoking the function
			check=functions.searchByBarcodeNum(str);
			endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			if(check)
			{return (functions.getIndexes())[static_cast<unsigned>(0)];}
			else return -3;
		case '4':
			cout<<"Please enter the Manufacturer: ";
			getline(cin,str);
			startTime = clock(); //Do this right before invoking the function
			check=functions.searchByManufacturer(str);
			endTime = clock();  //Do this right after the function returns
			cout<<"Elapsed time:";
			cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
			if(check)
			{
				cout<<"Please input the index of the product you want to operate on: ";
				cin>>choice;
				cin.ignore(1000,'\n');
				return (functions.getIndexes())[static_cast<unsigned>(choice-'0'-1)];
			}
			else return -3;
		case '5':
			return -2;//quit so taht all funtion does nothing

		default:
			x=1;
			cout<<"there is no such command\n";
			getchar();
			getchar();
			return -3;
			
		}
	}
	while(x==1);
}


void UserInterface::loadInData()
{
	clock_t startTime = clock(); //Do this right before invoking the function
	bool check=functions.loadInData(FileName);
	clock_t endTime = clock();  //Do this right after the function returns
	cout<<"Elapsed time:";
	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
	if(check)
		cout<<"Load Data Successfully!\n";
	else cout<<"Load Data Unsuccessfully!\n";
return;
}


void UserInterface::batchProcessing()
{
	char c;
	clock_t startTime = clock(); //Do this right before invoking the function
	bool check=functions.batchProcessing("batchjobs.txt","log.txt");
	clock_t endTime = clock();  //Do this right after the function returns
	cout<<"Elapsed time:";
	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*100.0<<"ms"<<endl;
	if(check)
		cout<<"Excute Successfully!\n No Error Occured";
	else
	{ 
		cout<<"\nExcute Unsuccessfully!	Some Errors Ocurred.\n\n";
		cout<<"You can check error in "<<"log.txt"<<" OR type it out.\n";
		cout<<"TYPE or NOT TYPE (T/N): ";
		c=getchar();
		cin.ignore(1000,'\n');
		if(c=='t' || c=='T') 
			functions.printFile("log.txt");

	}
return;
}

void UserInterface::saleHistory_Menu(char ch)
{
	if (ch=='C')
	{
		cout<<"Sale History of You: \n";
		functions.saleHistory(UserName);
		return;
	}
	else 
	{
		string name;
		char choice;
		int x=1; 
	
		while(x==1)//infinite loop. step out if quit
		{
			cout<<"\n\n";
			cout<<setfill('-')<<setw(80)<<""<<endl;
			cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
			cout<<setfill('-')<<setw(80)<<""<<endl;

			cout<<" Sale History\n\n";
		
			cout<<"|1. Your own sale history \n";
			cout<<"|2. Others sale history\n";
			cout<<"|3. Return to main menu\n";
			cout<<setfill('-')<<setw(80)<<""<<endl;
			cout<<"\n";
			cout<<"Please input your choice(1-3): ";

			choice=getchar();
			cin.ignore(1000,'\n');//clear the buffer
		
			switch (choice)
			{
				case '1':
					cout<<"Sale History of You: \n";
					functions.saleHistory(UserName);
					break;

				case '2':
					cout<<"Please enter the name: ";
					getline(cin,name);
					cout<<"\nSale History of "<<name<<" :\n";
					functions.saleHistory(name);
					break;

				case '3':
					x=0; //to exit the loop
					break;

				default: //failsafe
					cout<<"there is no such command\n";
					getchar();
					getchar();
			}
			cin.ignore(1000,'\n');
			cout<<"Do you wish to Show more sale history? (Y/N) "<<endl;

			choice = toupper( getchar() ); //read choice and convert to caps
		
			cin.ignore(1000,'\n');//clear the buffer

			if(choice!='Y')
				x=0; //to exit the loop
			
	    }
	return;
	}
}
		
void UserInterface::adduser_Menu()
{
	string name;
	char choice;
	int x=1; 
	
	while(x==1)//infinite loop. step out if quit
	{
		cout<<"\n\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Add User\n\n";
		
		cout<<"|1. Add Manager \n";
		cout<<"|2. Add Cashier\n";
		cout<<"|3. Return to main menu\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"\n";
		cout<<"Please input your choice(1-3): ";

		choice=getchar();
		cin.ignore(1000,'\n');//clear the buffer
		
		
		string name, pass;
		switch (choice)
		{
			case '1':
				cout<<endl<<"Name:";
				cin>>name;
				cout<<"Password:";
				cin>>pass;
				functions.Adduser(name,pass,'M');
				break;
			case '2':
				
				cout<<endl<<"Name:";
				cin>>name;
				cout<<"Password:";
				cin>>pass;
				functions.Adduser(name,pass,'C');

				break;
			case '3':
				x=0; //to exit the loop
				break;

			default: //failsafe
				cout<<"there is no such command\n";
				getchar();
				getchar();
		}
			
		cin.ignore(1000,'\n');
		cout<<"Do you wish to Add more User? (Y/N) "<<endl;

		choice = toupper( getchar() ); //read choice and convert to caps
		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
			
	    }
	return;
}




