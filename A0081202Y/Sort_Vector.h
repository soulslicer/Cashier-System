#include <vector>
#include "Product.h"
#include "PerishableProduct.h"
#include "ComparatorProduct.h"
#include "ListBase.h"
#include "Queue.h"

using namespace std;

template <class T>
class Sort_Vector:public ListBase<T>
{
private:
	struct VNode
	{
		T item;
		int priceRank, stockRank;
	};
	vector<VNode> items;
	ComparatorProduct<Product*> COM;
public:
	Sort_Vector(){_size=items.size();}
	~Sort_Vector(){items.clear();}
	bool insert(int index, T& newItem)
	{
		if(index>=0 && index  <= _size)//0 -> n-1
		{
			VNode* newPtr = new VNode;
			newPtr->item = newItem;
			newPtr->priceRank=0;
			newPtr->stockRank=0;
			items.insert(items.begin()+index,*newPtr);
			_size=items.size();
			return true;
		}
		else
			return false;//out of array scope
		
	}
	bool remove(int index)
	{
		if(index>=0 && index  <= _size)//check index
		{
			items.erase(items.begin()+index);
			_size=items.size();
			return true;
		}
		else return false;
		
	}
	bool retrieve(int index,T& dataItem)//return product at index i
	{
		if(index >= 0 && index  <= _size)
		{
			dataItem=items[index].item;//assign to dataitem
			return true;
		}
		else return false;
	}

	T operator[](int index)//operator overload
	{
		return items[index].item;
	}

	void sortByWorth()
	{
		int i,j,temp,N;
		bool is_sorted;
		//bubblesort Stock
		for(i = 0; i< _size; i++)
		{
			is_sorted = true;
			for( j = 1; j< _size; j++)
			{
				if(!(COM.lessStock(items[j-1].item, items[j].item)))
					{
						swap(items[j-1], items[j]);
						is_sorted = false;
				    }

			}
			if (is_sorted) return;
		}

		for(i = 0; i< _size;i++)
		{
			items[i].stockRank = i+1;
		}

		// BubbleSort Price
		for(i = 0; i< _size; i++)
		{
			is_sorted = true;
			for( j = 1; j< _size; j++)
			{
				if(!(COM.cheap(items[j-1].item, items[j].item)))
					{
						swap(items[j-1], items[j]);
						is_sorted = false;
				    }

			}
			if (is_sorted) return;
		}

		for(i = 0; i< _size;i++)
		{
			items[i].priceRank = i+1;
		}

		// Radix Sort Worth
		// find max
        int max=0,d=0;
		for( i = 0; i< _size; i++)
		{
			if(items[i].priceRank + items[i].stockRank > max)
			{
				max = items[i].priceRank + items[i].stockRank;
			}
		}

		while(max!=0)
		{
			max = max/10;
			d++;
		}

		int power=1;
		Queue<VNode> digitQueue[10];
		for(i = 0; i<d; i++)
		{
			distribute(digitQueue,power);
			collect(digitQueue);
			power*=10;
		}
		

	}


	

	void swap(VNode& N1, VNode& N2)
	{
		VNode temp;
		temp = N1;
		N1 = N2;
		N2 = temp;
		return;
	}

	void distribute(Queue<VNode> digitQ[], int power)
	{
		int digit;
		for( int i = 0; i < _size; i++)
		{
			digit = ((items[i].priceRank + items[i].stockRank)/power) % 10;
			digitQ[digit].enqueue(items[i]);
		}
	}

	void collect( Queue<VNode> digitQ[])
	{
		int i = 0, digit;
		for(digit = 0; digit < 10; digit++)
		{
			while(!digitQ[digit].empty())
			{
				items[i]=digitQ[digit].dequeue();
				i++;
			}
		}
	}

	void mergeIndexer(){}

	void setState(int x){}

	int getState(){return 0;}
	int AccessIndex(char temp){return 0;}//Pointless functions

	int LetterCheck(char letter,bool checking){}
};