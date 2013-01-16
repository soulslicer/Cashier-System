#include "ListBase.h"
#include "Product.h"

#ifndef PRODUCTDOUBLELINKEDLIST_H
#define PRODUCTDOUBLELINKEDLIST_H
using namespace std;

//circular double link list class template

template <class T>
class ProductDoubleLinkedList: public ListBase<T>
{
private:
	struct ListNode
	{
	  T item;
	  ListNode* prev;
	  ListNode* next;
	};

    //no list head now
	ListNode* _tail;
	ListNode* _cur;

	ListNode* transverseTo(int index)//go to position
	{
	if ((index < 0) || (index >= _size))
            return NULL;
        else
        {  
            _cur = _tail->next;
            
            for ( int skip = 0; skip < index; skip++ )
                _cur = _cur->next;
            
            return _cur;
        }
	}
public:

	ListNode* getTail(){return _tail;}//return tail
	ListNode*& getCur(){return _cur;}//return current position
	ProductDoubleLinkedList()
	{
		_tail=NULL;
		_cur=_tail;
	}

	~ProductDoubleLinkedList()
	{
		while(_size!=0)
		{
			remove(0);
		}
	}

	void sortByWorth(){}
	bool insert(int index, T& newItem)
	{
		if (index<0)//if invalid index
			return false;
		else
		{  
			ListNode *newPtr = new ListNode;//make new container
			newPtr->item = newItem;
			newPtr->next = NULL;
			newPtr->prev = NULL;
               
			if(_size==0)//if 1st node
			{
				_tail=newPtr;
				_tail->next=_tail;
			}

			else 
			{
				if (index == 0)
				{//First Node
                
					newPtr->next=_tail->next;//Make Circular
					newPtr->prev=_tail;
					_tail->next->prev=newPtr; 
					_tail->next = newPtr;  
				} 

				else 
				{
					if(index!=_size) 
					{  
						 _cur = transverseTo( index-1 );//Previous object
						newPtr->prev=_cur;
						newPtr->next=_cur->next;
						_cur->next->prev=newPtr;
						_cur->next=newPtr;
					}

					else
					{
						newPtr->next=_tail->next;//Make Circular
						newPtr->prev=_tail;
						_tail->next->prev=newPtr; 
						_tail->next = newPtr;
						_tail=newPtr;

					}
				}
			}
		}
		
		_size++;
		_cur=_tail;

		return true;
	}
	bool remove(int index)
	{   
		if ((index<0 || index>=_size) && _size==0)//if size == 0 
			return false;
		else
		{
			if(index!=_size-1)
			{
				_cur=transverseTo(index);
				_cur->prev->next=_cur->next;
				_cur->next->prev=_cur->prev;
				delete _cur;
			}
			else
			{
				_tail->next->prev=_tail->prev;
				_tail->prev->next=_tail->next;
				_cur=_tail;
				_tail=_tail->prev;
				delete _cur;	
			}

			_cur=_tail;
			_size--;
			return true;
		}
	}
	
	 bool retrieve(int index,T& dataItem)
	{
		if((index>=_size || index<0) && _size==0)
			return false;
        
		_cur=_tail->next;//set to first element
		for(int i=0;i<index;i++)
			 _cur=_cur->next;
    
		dataItem=_cur->item;//set dataitem = current
		_cur=_tail;

		return true;    
	}

	T operator[](int index)//operator overload
	{
		return transverseTo(index)->item;
	}

	void mergeIndexer(){}

	void setState(int x){}

	int getState(){return 0;}

	int AccessIndex(char temp){return 0;}
};

#endif