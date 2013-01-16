#include "login.h"

login::login(string user,string pass)
{
	name = user;
	password = pass;
}

bool login::Vertify()
{
	
			ifstream UserFile;
			UserFile.open ("User.txt", ifstream::in);

			
			bool found = false;
			while(!UserFile.eof())
			{
				//look for username
				string tempt1,tempt2;
				getline(UserFile,tempt1);//username
				getline(UserFile,tempt2);//password

				if(tempt1.compare(name)!=0 || tempt2.compare(password)!=0)//either doesnt match
				{
					//not found
					UserFile.ignore(1000,'\n');

				}

				else//found
				{
					//close file

					UserFile>>type;
					type=toupper(type);
					UserFile.close();
					return true;

				}
			}	
			
			//close file
			UserFile.close();
			return false;//not found
}

char login::Gettype()
{
	return type;
}