#ifndef LISTBASE_H
#define LISTBASE_H
#include <string>

using namespace std;

template <class T>
class ListBase
{
protected:
	int _size;
public:
	ListBase(){ _size=0; }
	virtual ~ListBase(){}
	bool empty() {return (_size==0);}
	int size() {return _size;}

	virtual bool insert(int index, T& newItem) =0;
	virtual bool remove(int index) =0;
	virtual bool retrieve(int index,T& dataItem) =0;
	

};

#endif

//list base class. only has the basic functions