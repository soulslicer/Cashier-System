#ifndef COMPARATORBASE_H
#define COMPARATORBASE_H

using namespace std;

template <class T>
class ComparatorBase
{
public:
	virtual bool Compare(T item1, T item2) =0;
};
#endif