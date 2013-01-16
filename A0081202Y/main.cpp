#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "UserInterface.h"
#include "login.h"


using namespace std;

static int ATTEMPT =5;
void Login (string& user,string& password);

void main()
{
	int x=0;
	while(x==0)//many users
	{
		//menu
		//output on screen
		cout<<setfill('-')<<setw(80)<<""<<endl;//fillers
		cout<<"|           CEG Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Login Screen\n\n";

		string user, password;
		bool found;
		int i;
		char type;
		for(i=0;i<ATTEMPT;i++)
		{
			Login(user,password);//pass in variables to read from screen
			login log(user,password);

			found = log.Vertify();
			cout<<endl;

			if(found)
			{
				type=log.Gettype();
				break;
			}
			else
				cout<<endl<<endl<<"Please check your user or password"<<endl<<endl;	
		}

		if(found)
		{
			cin.ignore(1000,'\n');

			UserInterface UI("data10.txt",user);
				
			if(type=='M')//manager
			{
				UI.Manager_Menu();
			}
			else
				if(type=='C')//cashier
				{
					UI.Cashier_Menu();
				}

			
			//output if u wan to add new 
			cin.ignore(1000,'\n');
			cout<<"Do you wish to login as another user? (Y/N):";
		
			char choice = getchar();
			choice=toupper(choice);

			if(choice!='Y')//quit if input is not s
				x=1;
		}
		else //output failed
		{
			cout<<"Login "<<ATTEMPT<<" times failed"<<endl;
			cin.ignore(1000,'\n');
			cin.ignore(1000,'\n');

			return;
		}

	}
	return ;
}


void Login(string& user,string& password)
{
	//ask for username
	cout<<"Username:";
	cin>>user;

	//ask for password
	cout<<"Password:";
		
	unsigned char ch=0;			
	while((ch=getch())!=13)//while not '\n'
	{
		if(ch==8)//if not backspace
		{
			if(password.length()!=0)//if not return at 0
			{
				cout <<"\b \b";//backspace
				password.resize(password.length()-1);//string size -1
			}
		}
		else 
		{
			if(ch==0 || ch==224) // handle escape sequences
			{
				getch(); // ignore non printable chars
				continue;
			}
			else
			{
				password+=ch;//append to the end
				cout <<'*';//output * for each append
			}
		}	
	}
}