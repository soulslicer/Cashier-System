#include "Functionality.h"
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Product.h"
#include "PerishableProduct.h"
#include "ListBase.h"
#include "Functionality.h"
#include "Stack.h"
#include "User.h"
#include "Jobs.h"
#include "Queue.h"
using namespace std;

string Functionality::getUserName()
{
	return UserName;
}

bool Functionality::searchByName(string Name)
{
	if(List.getState()!=2){
		List.setState(2);
		List.mergeIndexer();
	}

	Indexes.clear();//clear return list
	bool check=false;//set check to false
	char temp=Name[0];//get first char to jump index

	int i=List.AccessIndex(temp);//Need to set i to the char index
	//int i=0;
	int j=0;
	for(i; i<List.size();i++)//for whole list
	{
		if(List[i]->getName()==Name)//if the name is similar
			{
				j++;//number of found ++
				Indexes.push_back(i);//add to list

				cout<<"\nIndex: "<<j<<"\n";//output from list
				List[i]->printProduct();

				check=true;//got find a name
		   }
	}

	return check;//return false if not found
}
	
bool Functionality::searchByCategory(string Category)
{
	if(List.getState()!=1){
		List.setState(1);
		List.mergeIndexer();
	}
	Indexes.clear();//clear return list

	int j=0;
	bool check=false;//assume not found
	char temp=Category[0];//get first char to jump index

	int i=List.AccessIndex(temp);//Need to set i to the char index
	//int i=0;

	for(i; i<List.size();i++)//for whole list
	{
		if(List[i]->getCategory()==Category)//if category is similar
		{
			j++;//number found ++
			Indexes.push_back(i);//add to the list

			cout<<"\nIndex: "<<j<<endl;//output
			List[i]->printProduct();

			check=true;//was found
		}
	}
	return check;
	
}
	
bool Functionality::searchByManufacturer(string Manufacturer)
{

	if(List.getState()!=3){
		List.setState(3);
		List.mergeIndexer();
	}

	Indexes.clear();//clear list

	int j=0;
	bool check=false;//assume not found
	char temp=Manufacturer[0];//get first char to jump index

	int i=List.AccessIndex(temp);//Need to set i to the char index

	for(i; i<List.size();i++)//for whole list
	{
		if(List[i]->getManufacturer()==Manufacturer)//if manufacturer
		{
			j++;//number of found ++
			Indexes.push_back(i);//add to index

			cout<<"\nIndex: "<<j<<endl;//output
			List[i]->printProduct();

			check=true;//was found
		}
	}

	return check;
}

bool Functionality::searchByBarcodeNum(string Barcode)
{
	Indexes.clear();//list clear

	for(int i=0; i<List.size();i++)//for whole list
	{
		if(List[i]->getBarcodeNum()==Barcode)//if barcode is similar
		{
			Indexes.push_back(i);//add to index
			//List[i]->printProduct();//putput to screen
			return true;//barcode is unique
		}
	}
	return false;//not found
}
	
bool Functionality::addNewProduct(Product* NewItem,bool load)//add new product to list
{
	for( int i=0;i<List.size();i++)//for whole list
	{
		if(NewItem->getBarcodeNum()==List[i]->getBarcodeNum())//if similar barcode is found
		{
			//cout<<"similar barcode found"<<endl;
			return false;//cannot add
		}
	}

	if(!load)
		{//If load is not true
		bool z=List.insert(List.size(),NewItem);//else try to add
		if(z){
			List.mergeIndexer();
			return true;}
		else{
			return false;
		}
	}
	else
	{
		return List.insert(List.size(),NewItem);//else try to add
	}

}

bool Functionality::deleteProduct(int index)//try to remove from list
{
	bool x=List.remove(index);
	if(x){
		List.mergeIndexer();
		return true;
	}
	return false;
}

bool Functionality::resetProductSales()//reset all
{
	bool check=true;//assume true

	for(int i=0;i<List.size();i++)//for whole list
	{
		check=List[i]->setNumSoldPerMonth(0);//reset all to 0

		if(check=false)//anomaly immediately quit
			return check;
	}

	return check;//else reuturn true
}

bool Functionality::resetIndividualProductSale(int index)
{
	int i=0;
	return List[index]->setNumSoldPerMonth(i);//reset product sale at index i
}

bool Functionality::sellProduct(int index,int& num,string UserName)//selling product
{
	int N=0,M=0;
	bool check;
	string UserFile = UserName + string(".txt");
	cout<<UserFile<<endl;
	ofstream writeFile(UserFile.c_str(),ios::app);
	if(writeFile.is_open())
		cout<<"open sucssess\n";


	//procedure to sell
	N=List[index]->getNumInStock();
	M=List[index]->getNumSoldPerMonth();
	N=N-num;
	M=M+num;
	if(N<0) return false;
	check= ((List[index]->setNumInStock(N)) && (List[index]->setNumSoldPerMonth(M)));//return true
	if(check)
		writeFile<<List[index]->getName()<<"  "<<List[index]->getBarcodeNum()<<"  "<<num<<endl;

	writeFile.close();
	return check;

}

bool Functionality::restockProduct(int index,int& num)//restocking 
{
	int i=(List[index]->getNumInStock())+num;//add to stock

	return List[index]->setNumInStock(i);
}

bool Functionality::saveDataToFile(string FileName)//save all to product to file
{
	ofstream writeFile(FileName.c_str());

	if(writeFile.fail())//if not able to find file
	{
		return false;
	}

	writeFile<<List.size()<<endl;//output size

	for(int i=0;i<List.size();i++)//for all products
	{
		if(List[i]->checkPerishable()) 
			writeFile<<'y'<<endl;//if perishable

		else
			writeFile<<'n'<<endl;//if non perishable(product)

		//write all to file
		writeFile<<List[i]->getName()<<endl;
		writeFile<<List[i]->getCategory()<<endl;
		writeFile<<List[i]->getBarcodeNum()<<endl;
		writeFile<<List[i]->getPrice()<<endl;
		writeFile<<List[i]->getManufacturer()<<endl;
		writeFile<< List[i]->getNumInStock()<<endl;
		writeFile<< List[i]->getNumSoldPerMonth()<<endl;

		if(List[i]->checkPerishable())//extra stuff for perishable
		{
			if(List[i]->getExpiryDate()[0]<10)
				writeFile<<0<< List[i]->getExpiryDate()[0];

			else
				writeFile<<List[i]->getExpiryDate()[0];
		
			if(List[i]->getExpiryDate()[1]<10)
				writeFile<<0<< List[i]->getExpiryDate()[1];
						
			else
				writeFile<<List[i]->getExpiryDate()[1];
			
			if(List[i]->getExpiryDate()[2]<2000)
				writeFile<<20<< List[i]->getExpiryDate()[2]<<endl;
				
			else
				writeFile<< List[i]->getExpiryDate()[2]<<endl;
				
			writeFile<<List[i]->getDiscountPercentage()<<endl;
		}
	}
	writeFile.close();//close file 
	return true;
}

bool Functionality::loadInData(string FileName)//read from file
{
	//initialise
	int num,NIS,NSPM;
	string name,cate,manu,barcode,date,skip;
	double price,disc;
	char peri;

	ifstream readFile(FileName.c_str());

	if(readFile.fail())//if file open fails
	{
		return false;
	}
	
	cout<<endl<<"loading..."<<endl;

	readFile>>num;//read in total number of products

	for(int i=0; i<num;i++)//for n number of times
	{
		bool checkB=true;//assume true

		readFile>>peri;//'y' or 'n'
		getline(readFile,skip);

		getline(readFile,name);//string types
		getline(readFile,cate);
		getline(readFile,barcode);

		readFile>>price;//float type
		getline(readFile,skip);
		 
		getline(readFile,manu);//string type

		readFile>>NIS;//in stock
		getline(readFile,skip);

		readFile>>NSPM;
		getline(readFile,skip);
		
		for(int j=0;j<List.size();j++)//check if similar barcode exits
		{
			if(barcode==List[j]->getBarcodeNum())//if similar
			{
				checkB=false;//cannot add
				break;
			}				
		}

		if((peri=='y'|| peri=='Y') && checkB)//if still true and perishable
		{
			getline(readFile,date);//read date

			readFile>>disc;//discount
			getline(readFile,skip);

			PerishableProduct* newPtr=new PerishableProduct(barcode);//create new cointainer
			int d[3];
			const char* da=date.c_str();

			//set date
			d[0]=(da[0]-'0')*10+(da[1]-'0');
			d[1]=(da[2]-'0')*10+(da[3]-'0');
			d[2]=(da[4]-'0')*1000+(da[5]-'0')*100+(da[6]-'0')*10+(da[7]-'0');

			//set perishable date and discount
			newPtr->setExpiryDate(d);
			newPtr->setDiscountPercentage(disc);

			bool b;

			if(peri=='y' || peri=='Y')
				b=true;

			else
				b=false;

			//input to product
			newPtr->setPerishable(b);
			newPtr->setName(name);
			newPtr->setCategory(cate);
			newPtr->setPrice(price);
			newPtr->setManufacturer(manu);
			newPtr->setNumInStock(NIS);
			newPtr->setNumSoldPerMonth(NSPM);

			if(checkDate(d[0],d[1],d[2]))
				addNewProduct(newPtr,true);//add new product
			else
			{
				//something is wrong with expiry date
				cout<<i+1<<"th product in file added unsuccessfully, Please check whether Expiry Date\n";
				delete newPtr;//return memory
			}		
		}
			
		else
		{
			if(checkB)//else if its a product
			{
				Product* newPtr=new Product(barcode);//make new space
				newPtr->setName(name);
				bool b;

				if(peri=='y' || peri=='Y')
					b=true;

				else
					b=false;

				//input all the fields
				newPtr->setPerishable(b);
				newPtr->setCategory(cate);
				newPtr->setPrice(price);
				newPtr->setManufacturer(manu);
				newPtr->setNumInStock(NIS);
				newPtr->setNumSoldPerMonth(NSPM);
				
				addNewProduct(newPtr,true);//add new product
			}
			else

				//if similar barcode found
				cout<<i+1<<"th product in file added unsuccessfully, Please check whether Barcode Number valid\n";
		}
	}

	readFile.close();//good habit

	List.mergeIndexer();

	return true;//successful
}

void Functionality::getHighest(const int X)
{
	//Create queue of queues
	if(X>List.size())
	{
		cout<<"There is less than "<<X<<" number of Products.\n";
		return;
		//should just return all that is there.

		//should only output a message when there is no product to print
	}

	double* d= new double[X];
	unsigned int j=0;
	int index;
	vector<Top> Results;

	for(int i=0; i<List.size(); i++)//for the whole list
	{   index=i;//start from i onwards
		double temp = (List[i]->getPrice()) * (List[i]->getNumSoldPerMonth());//the judging factor
		
		//if no other 
		if(Results.empty())
		{
			//adding to queue
			Top* e =new Top;
			e->amount=temp;
			e->indexQ.enqueue(index);
			Results.push_back(*e);
		}
		else
		{
			for(j=0; j<Results.size(); j++)//compare with the results
			{
				if(fabs(temp - Results[j].amount)<0.01)//make a list by preventing duplicates
					{
						Results[j].indexQ.enqueue(index);
						break;
					}
		
			}
			if( j== Results.size())//if left over = whats needed
			{
				//add to the top
				Top* p = new Top;
				p->amount = temp;
				p->indexQ.enqueue(index);
				Results.push_back(*p);
			}
		}
	}

	//initialise array to 0
	for(int i=0;i<X;i++)
	{
		d[i]=0;
	}
	
	for(j=0; j<Results.size(); j++)//for all results
	{
		for(int i=0;i<X;i++)//for the length of return list
		{
			if(Results[j].amount-d[i]>=0.01)//if found amount that is greater
			{
				int k=X;
				while(k>i)//push the rest out
				{
					d[k-1] = d[k-2];
					k--;
				
				}
				d[i]=Results[j].amount;//put at i
				break;
			}
		}
	}
	//output
	for(int i=0;i<X;i++)//top X
	{
		cout<<"\nTop "<<i+1<<" Sale Amount: "<<d[i]<<endl;//title

		for(j=0;j<Results.size();j++)//traverse the whole list
		{
			if(fabs(Results[j].amount - d[i])<0.01)//if very similar
			{
				for(int k=1;!Results[j].indexQ.empty();k++)//output all under that price
				{
					cout<<"\n Product "<<k<<" : \n";//format
					int in = 0;
					in = Results[j].indexQ.dequeue();
					List[in]->printProduct(); //output to screen	 
				};
			}
		}
	}
return;
}

int Functionality::getHighestInOneCategory(string Name)
{
	double Max=0;//value of highest
	int index=-1;//-1 denotes no product exists
	for(int i=0;i<List.size();i++)//for whole list
	{
		if(List[i]->getCategory()==Name)//if similar name
		{
			if((List[i]->getPrice())*(List[i]->getNumSoldPerMonth())>=Max)//if higher sold found
			{
				Max=(List[i]->getPrice())*(List[i]->getNumSoldPerMonth());//set max value =value of i
				index=i;//set i as highest
			}
		}
	}
		
	return index;//position of highest
}

int Functionality::checkExpired(int index)//expired return 1, not expired return 0, non-perishable return -1
{
	if(List[index]->checkPerishable())
	{
		if(List[index]->checkExpired())
			return 1;
		else
			return 0;
	}

	else
		return -1;
}

int Functionality::checkExpired(string barcode,string currentDate)
{
  if(searchByBarcodeNum(barcode))
	  return -2;
  else
  {
      if(!List[Indexes[0]]->checkPerishable())
		  return -1;
	  else
	  {
		int da[3];
		da[0]=currentDate[0]-'0'+(currentDate[1]-'0')*10;
		da[1]=currentDate[2]-'0'+(currentDate[3]-'0')*10;
		da[2]=currentDate[4]-'0'+(currentDate[5]-'0')*10+(currentDate[6]-'0')*100+(currentDate[7]-'0')*1000;
		if(List[Indexes[0]]->getExpiryDate()[2]<da[2])return 0;
		if(List[Indexes[0]]->getExpiryDate()[2]==da[2] && List[Indexes[0]]->getExpiryDate()[1]<da[1])return 0; 
		if(List[Indexes[0]]->getExpiryDate()[2]==da[2] && List[Indexes[0]]->getExpiryDate()[1]==da[1]  && List[Indexes[0]]->getExpiryDate()[0]<da[0])return 0;

		return 1;

	  }
  
  }

}

bool Functionality::batchProcessing(string inFile,string outFile)
{
	bool check =true;
	int k=0;
	int userNum;
	Stack<User> US;
	string userName,barcodeN,cate,manu,productName,date,jobName,skip;
	double price;
	int num,jobNum;
	Code type;
	ifstream readFile(inFile.c_str());

	 readFile>>userNum;
	 getline(readFile,skip);
	 for(int i=0; i<userNum; i++)
	 {
		getline(readFile,userName);
		User* newPtr= new User(userName);
		readFile>>jobNum;
		getline(readFile,skip);

		for(int j=0 ;j<jobNum ;j++)
		{
			
			getline(readFile,jobName);
			if(jobName==string("DELETE")) type=DELETE;
			else if(jobName==string("ADD")) type=ADD;
			else if(jobName==string("RESTOCK")) type=RESTOCK;
			else if(jobName==string("DISPOSE")) type=DISPOSE;
			else if(jobName==string("SALE")) type=SALE;
			else { cout<<"Wrong Code.\n"; break;}
			
			JobBase* s;
			if(type==ADD)
			{
				getline(readFile,productName);
				getline(readFile,cate);
				getline(readFile,barcodeN);
				readFile>>price;
				getline(readFile,skip);
				getline(readFile,manu);
				readFile>>num;
				getline(readFile,skip);
				AddJob* p=new AddJob(barcodeN);
				s = p;
				p->setJob(ADD);
				p->setCategory(cate);
				p->setManufacturer(manu);
				p->setName(productName);
				p->setPrice(price);
				p->setNumInStock(num);
				(newPtr->getQ()).enqueue(s);
			}
			else if(type== DELETE)
			{
				getline(readFile,barcodeN);
				DeleteJob* q=new DeleteJob(barcodeN);
				q->setJob(type);
				s = q;
				(newPtr->getQ()).enqueue(s);
			}	
			else if(type== RESTOCK)
			{
				getline(readFile,barcodeN);
				readFile>>num;
				getline(readFile,skip);
				RestockJob* r=new RestockJob(barcodeN);
				r->setNumToStock(num);
				r->setJob(RESTOCK);
				s = r;
				(newPtr->getQ()).enqueue(s);
			}
			else if(type== DISPOSE)
			{
				getline(readFile,barcodeN);
				getline(readFile,date);
				DisposeJob* m=new DisposeJob(barcodeN);
				m->setCurrentDate(date);
				m->setJob(DISPOSE);
				s = m;
				(newPtr->getQ()).enqueue(s);
			}
			else if(type== SALE)
			{
				getline(readFile,barcodeN);
				readFile>>num;
				getline(readFile,skip);
				SaleJob* n=new SaleJob(barcodeN);
				n->setNumSold(num);
				n->setJob(SALE);
				s = n;
				(newPtr->getQ()).enqueue(s);
			}
			else cout<<"\nThere is no such Job\n";
			}
		 US.push(*newPtr);
		 }
	 readFile.close();
	 ofstream writeFile(outFile.c_str());

	 while(!US.empty())
	 {   
		 
		 User U;
		if( US.pop(U))
		{
			
		 UserName = U.getName();
		}
		 while(!((U.getQ()).empty()))
		 {
			
			 JobBase* J;

			 J=(U.getQ()).dequeue();
			 if(!(J->execute(this))) 
			 {
				 check=false;
				 writeFile<<J->getBarcodeNum()<<" "<<J->jobType()<<" "<<U.getName()<<endl;

			 }
		 }
	 }
	 writeFile.close();
return check;
}

void Functionality::listAllProduct()//output all product in list to screen 
	{
		for(int i=0;i<List.size();i++)
		{
			if(i%10==0 && i!=0)
			{
				char c;
				cout<<"Do you want to continue printing?(y/n): ";
				cin>>c;
				if(!(c=='y'|| c=='Y'))
				   return;
				else 
					cout<<"------------------------------------------------------------------------------\n";
			}
			
			cout<<"\nIndex:"<<i+1<<"\n";
			List[i]->printProduct();
			
		}
	}

vector<int> Functionality::getIndexes()//return positions 
{
	return Indexes;
}
	
string Functionality::bestManufacturer()//sum of price * number sold for all products under manufacturer name
{
	vector<container> cv;//vector
	int i;
	unsigned j;
	
	for( i=0; i<List.size();i++)//for whole list
	{
		if(cv.empty())//if 1st product
		{
			//add it
			container c1;
			c1.str=List[i]->getManufacturer();
			c1.amount=(List[i]->getPrice())*(List[i]->getNumSoldPerMonth());//price * number sold
			cv.push_back(c1);//add to vector
		}

		else//if not first
		{
			for( j=0;j<cv.size();j++)//for whole vector
			{
				if(List[i]->getManufacturer()==cv[j].str)//if same manufacturer found
				{
					cv[j].amount+=(List[i]->getPrice())*(List[i]->getNumSoldPerMonth());// add to that manufacturer
					break;
				}
			}
			if(j==cv.size()) //at the limit of the list
			{
				container c1;//add new manufacturer to compare with
				c1.str=List[i]->getManufacturer();
				c1.amount=(List[i]->getPrice())*(List[i]->getNumSoldPerMonth());

				cv.push_back(c1);
			}
		}
	}

	double Max=0;
	string manu;
	for( j=0;j<cv.size();j++)//for the whole list
	{
		if(cv[j].amount>Max)//compare and find the highest value
		{
			Max=cv[j].amount;
			manu=cv[j].str;
		}
	}

	return manu;//return manufacturer
}

void Functionality::printProduct(int index)
{
	List[index]->printProduct();//output 1
}

bool Functionality:: checkDate(int day, int month, int year)//date functionality
{
	if(day<32 && day>0 && month>0 && month<13 &&year>0 &&year<=9999)//only valid numbers are takne into consideration
	{
		bool leap;
		if(year%4==0)
		{
			if(year%400==0)
				leap=true;
			else if(year%100==0)
				leap=false;
			else leap=true;
		}
		else leap=false;
		switch(month)
		{
		case 2: 
			if(leap && day>29)//leap year
				return false;
			else
				if(!leap && day>28)//non leap year
					return false;
				else 
					return true;
			
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day>30)//30 day months
				return false;
			else
				return true;

			break;
		default:
			return true;//all other months are true
		}
	}
	else
		return false;//if error input

}

string Functionality::getInfo(bool& Perishable,int index)
{
	Product* Item;
    Item=List[index];//change product
	
	if(Item->getDiscountPercentage()!=-1.0)
        Perishable=true;
	else
		Perishable=false;

	return Item->getName();
    
    
}

bool Functionality::editProducts(int choice,int index, string propertys)
{
	istringstream instr(propertys);

	Product* Item;
	Item=List[index];

	string prop;double props;
    switch (choice) 
    {
        case 1:{
			instr>>prop;
            bool check=Item->setName(prop);
            if(check==false){return false;}
            break;}
        case 2:{
			instr>>prop;
            bool check=Item->setBarcodeNum(prop);
            if(check==false){return false;}
            break;}
        case 3:{
			instr>>prop;
            bool check=Item->setCategory(prop);
            if(check==false){return false;}
            break;}
        case 4:{
			instr>>prop;
            bool check=Item->setManufacturer(prop);
            if(check==false){return false;}
            break;}
        case 5:{
			instr>>props;
            bool check=Item->setPrice(props);
            if(check==false){return false;}
            break;}
        case 6:{
			int* date=new int[3];
			instr>>date[0]; instr>>date[1]; instr>>date[2];
            bool check=Item->setExpiryDate(date);
            if(check==false){return false;}
            break;}
        case 7:{
			instr>>props;
            bool check=Item->setDiscountPercentage(props);
            if(check==false){return false;}
            break;}
        default:{
            return false;
            break;}
    }
    return true;
    
    

}

void Functionality::printFile(string F)
{
	string s;
	ifstream readFile(F.c_str());
	
	if(!readFile.is_open())
	{
		cout<<"Error in openning file.\n";
		return;
	}

	while(!readFile.eof())
	{
		getline(readFile,s);
		cout<<s<<endl;
	}
	readFile.close();
	return;
}

void Functionality::saleHistory(string N)
{
	printFile(N+string(".txt"));
return;
}

void Functionality::Adduser(string name, string pass,char type)
{
	ofstream outfile;

	outfile.open ("User.txt", ios_base::app);//go to the end of file

	outfile<<name<<endl<<pass<<endl<<type<<endl;

	outfile.close();


}

void Functionality::sortByWorth()
{
	List.sortByWorth();
	return;
}