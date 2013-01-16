#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#ifndef LOGIN_H
#define LOGIN_H


class login
{

	string name;
	string password;
	char type;

public:
	login(string user,string pass);

	char Gettype();
	bool Vertify();

};

#endif