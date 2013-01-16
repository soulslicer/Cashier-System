#include "ListBase.h"
#include "Product.h"
#include <queue>

#ifndef PRODUCTLISTARRAY_H
#define PRODUCTLISTARRAY_H
using namespace std;

const int SIZE=100;

//list array template class

template <class T>
class ProductListArray: public ListBase<T>
{
private:
	T* item;
	int ArraySize;

	int** Indexes;
	ComparatorProduct<T> COM;
	int searchstate;


public:
	ProductListArray()
	{
		item = new T[SIZE];
		ArraySize=SIZE;
		_size=0;
		for(int i=0; i<ArraySize; i++)
		{
			item[i]=NULL;
		}
		Indexes=new int*[26];
		for(int i=0;i<26;i++)
			Indexes[i]=NULL;

		searchstate=3;
		//1 for Category by default
		//2 for Name
		//3 for Manufacturer

	}
	~ProductListArray()
	{
		delete [] item;
	}

	void sortByWorth(){}
	void setState(int x){searchstate=x;}
	int getState(){return searchstate;}

	int LetterCheck(char letter,bool checking)
	{
		switch(letter)
		{
			case 'A':
				if((Indexes[0]==NULL && checking==false) || (Indexes[0]!=NULL && checking==true))
					return 0;
				break;
			case 'B':
				if((Indexes[1]==NULL && checking==false) || (Indexes[1]!=NULL && checking==true))
					return 1;
				break;
			case 'C':
				if((Indexes[2]==NULL && checking==false) || (Indexes[2]!=NULL && checking==true))
					return 2;
				break;
			case 'D':
				if((Indexes[3]==NULL && checking==false) || (Indexes[3]!=NULL && checking==true))
					return 3;
				break;
			case 'E':
				if((Indexes[4]==NULL && checking==false) || (Indexes[4]!=NULL && checking==true))
					return 4;
				break;
			case 'F':
				if((Indexes[5]==NULL && checking==false) || (Indexes[5]!=NULL && checking==true))
					return 5;
				break;
			case 'G':
				if((Indexes[6]==NULL && checking==false) || (Indexes[6]!=NULL && checking==true))
					return 6;
				break;
			case 'H':
				if((Indexes[7]==NULL && checking==false) || (Indexes[7]!=NULL && checking==true))
					return 7;
				break;
			case 'I':
				if((Indexes[8]==NULL && checking==false) || (Indexes[8]!=NULL && checking==true))
					return 8;
				break;
			case 'J':
				if((Indexes[9]==NULL && checking==false) || (Indexes[9]!=NULL && checking==true))
					return 9;
				break;
			case 'K':
				if((Indexes[10]==NULL && checking==false) || (Indexes[10]!=NULL && checking==true))
					return 10;
				break;
			case 'L':
				if((Indexes[11]==NULL && checking==false) || (Indexes[11]!=NULL && checking==true))
					return 11;
				break;
			case 'M':
				if((Indexes[12]==NULL && checking==false) || (Indexes[12]!=NULL && checking==true))
					return 12;
				break;
			case 'N':
				if((Indexes[13]==NULL && checking==false) || (Indexes[13]!=NULL && checking==true))
					return 13;
				break;
			case 'O':
				if((Indexes[14]==NULL && checking==false) || (Indexes[14]!=NULL && checking==true))
					return 14;
				break;
			case 'P':
				if((Indexes[15]==NULL && checking==false) || (Indexes[15]!=NULL && checking==true))
					return 15;
				break;
			case 'Q':
				if((Indexes[16]==NULL && checking==false) || (Indexes[16]!=NULL && checking==true))
					return 16;
				break;
			case 'R':
				if((Indexes[17]==NULL && checking==false) || (Indexes[17]!=NULL && checking==true))
					return 17;
				break;
			case 'S':
				if((Indexes[18]==NULL && checking==false) || (Indexes[18]!=NULL && checking==true))
					return 18;
				break;
			case 'T':
				if((Indexes[19]==NULL && checking==false) || (Indexes[19]!=NULL && checking==true))
					return 19;
				break;
			case 'U':
				if((Indexes[20]==NULL && checking==false) || (Indexes[20]!=NULL && checking==true))
					return 20;
				break;
			case 'V':
				if((Indexes[21]==NULL && checking==false) || (Indexes[21]!=NULL && checking==true))
					return 21;
				break;
			case 'W':
				if((Indexes[22]==NULL && checking==false) || (Indexes[22]!=NULL && checking==true))
					return 22;
				break;
			case 'X':
				if((Indexes[23]==NULL && checking==false) || (Indexes[23]!=NULL && checking==true))
					return 23;
				break;
			case 'Y':
				if((Indexes[24]==NULL && checking==false) || (Indexes[24]!=NULL && checking==true))
					return 24;
				break;
			case 'Z':
				if((Indexes[25]==NULL && checking==false) || (Indexes[25]!=NULL && checking==true))
					return 25;
				break;
			default:
				break;
		}

		return -1;//false value
	}
	
	bool insert(int index, T& newItem)//insert at index
	{
		if(full())//if full ++
		{
			increaseSize();
		}

		if(index  <= _size)//0 -> n-1
		{
			for(int i=_size;i>=index;i--)
			{
				item[i]=item[i-1];
			}
			item[index]= newItem; 

			

			_size++;

			return true;
		}
		else
			return false;//out of array scope
	}

	bool remove(int index)//remove at position x. check if item being removed is an indexer
	{
		if(index < _size)
		{

			delete item[index];//delete what the pointer points to

			for(int i=index;i<_size-1;i++)//move the rest forward by 1. 
				item[i]=item[i+1];

			item[_size]=NULL;//to prevent replication of data
			_size--;

			return true;
		}
		else 
			return false;//out of array scope
	}

	bool retrieve(int index,T& dataItem)
	{
		if(index < _size)
		{
			dataItem = item[index];//assign dataitem to current
			return true;
		}
		else
			return false;//out of array scope
			//not found
	}

	bool increaseSize()//increase size of array by 1
	{
		int newSize=ArraySize+SIZE;//increase int size

		T* temp=item;//new container
		item=new T[newSize];

		for(int i=0;i<ArraySize;i++)//for whole array
			item[i]=temp[i];

		for(int i=ArraySize;i<newSize;i++)//for whole loop
			item[i]=NULL;

		ArraySize=newSize;//size = new size
		return true;
	}

	bool full()//check if it is full
	{
		return (_size==ArraySize);
	}

	T operator[](int index)//overload
	{
		return item[index];
	}

	int AccessIndex(char test)
	{
		int xx= LetterCheck(test,true);
		int xxx=*Indexes[xx];
		return xxx;
	}

	void mergeIndexer()
	{
		mergeSort(0,_size-1);

		for(int i=0;i<_size;i++)
		{

			int ind=LetterCheck(COM.FirstLetter(item[i],searchstate),false);
			if(ind!=-1)
			{
				Indexes[ind]=new int(i);//Set index of first item
				cout<<"Index of "<<COM.FirstLetter(item[i],searchstate)<<" set to "<<*Indexes[ind]<<endl;
			}

		}
	}

	void mergeSort(int low,int high)
	{
	   if (low < high) {
		  int mid = (low+high)/2;	

		  mergeSort(low, mid);	
		  mergeSort(mid+1, high);

		  merge(item, low, mid, high);	
	   }
	}
	
	void merge( T a[], int low, int mid, int high ) 
	{
	   int n = high-low+1;
	   T* b = new T[n];
	   int left = low, right = mid+1, bIdx = 0;

	   while ( left <= mid && right <= high) {

		   switch(searchstate)
		   {
		   case 1:{
			   //cout<<"called"<<endl;
			 if(COM.Compare2(a[left],a[right]))
				 b[bIdx++] = a[left++];
			  else
				  b[bIdx++] = a[right++]; break;}
		   case 2:{
			   if(COM.CompareName(a[left],a[right]))
				 b[bIdx++] = a[left++];
			  else
				  b[bIdx++] = a[right++]; break;}
		   case 3:{
			   if(COM.CompareManufac(a[left],a[right]))
				 b[bIdx++] = a[left++];
			  else
				  b[bIdx++] = a[right++]; break;}
		   default:
			   break;
			   //cout<<"fail"<<endl;
		   }
				 // cout<<"a"<<endl;

		  
	   } 

	   // continue from previous slide
	   while ( left <= mid ) 
		  b[bIdx++] = a[left++];

	   while ( right <= high ) 
		  b[bIdx++] = a[right++];

	   for ( int k = 0; k < n; ++k ) 
		  a[low+k] = b[k];

	   delete[] b;
	}

};

#endif