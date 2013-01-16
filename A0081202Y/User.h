#ifndef USER_H
#define USER_H
#include<string>
#include "Jobs.h"
#include"Queue.h"


class User
{
	string name;
	Queue<JobBase*> jobQ;
public:
	User(string N){name=N; }
	User(){name=string("");}
	string getName(){return name;}
	Queue<JobBase*>& getQ(){return jobQ;}
};
#endif