#ifndef PRODUCTLISTSORTED_H
#define PRODUCTLISTSORTED_H
#include "ListBase.h"
#include "ComparatorProduct.h"
#include "ComparatorBase.h"
#include <iostream>

using namespace std;
//tempate sorted class

template <class T>
class ProductListSorted : public ListBase<T>
{
private:
	struct ListNode//node
	{
	  T item;
	  ListNode* next;

	  //operator overload to support comparison
	  /*bool operator < (ListNode N2)
		{
			 bool check=(this->item->getCategory()<N2.item->getCategory());
			 return check;

		}*/
	};

	ListNode* _head;
	ComparatorProduct<T> COM;

	ListNode** Indexes;

	
	ListNode* transverseTo(int index)
	{
		if((index<0) || (index>=size()))
			return NULL;
		else
		{
			ListNode* cur =_head;
			for(int skip=0; skip<index; skip++)
				cur=cur->next;
			return cur;
		}
	}

public:
	ProductListSorted()//constructor
	{
			_head=NULL;
			_size=0;
			Indexes=new ListNode*[26];
			for(int i=0;i<26;i++)
				Indexes[i]=NULL;

			//Indexes= NULL ;
	}
	 ~ProductListSorted()//destructor
	{
		ListNode* prev=_head;//delete 1 by 1 from head onwards
		if(_head!=NULL)
		{
			_head=_head->next;
			delete prev;
		}
		for(int i=0;i<26;i++)
			Indexes[i]=NULL;
		delete Indexes;
	}
	ListNode* getHead(){return _head;}//returns 1st node

	void mergeIndexer(){}
	void setState(int x){}
	int getState(){return 0;}
	int AccessIndex(char temp){return 0;}//Pointless functions
	void sortByWorth(){}

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

	bool insert(int dummy, T& newItem)
	{
		int newLength=size()+1;//size ++
		ListNode* newPtr = new ListNode;//new container

		newPtr->item = newItem;//temporary container
		newPtr->next=NULL;
		_size=newLength;

		if(size()==1)//if only 1
		{
			int index=LetterCheck(COM.FirstLetter(newPtr->item,1),false);
			if(index!=-1)
			{
				Indexes[index]=newPtr;//Set index of first item
				cout<<"Index of "<<COM.FirstLetter(newPtr->item,1)<<" set"<<endl;
			}

			_head=newPtr;
			return true;
		}
		else
		{
			//compare values
			if(COM.Compare(newPtr->item,_head->item))//insert at 1st position
			{
					int index=LetterCheck(COM.FirstLetter(newPtr->item,1),false);
					if(index!=-1)
					{
						Indexes[index]=newPtr;//Set index of first item
						cout<<"Index of "<<COM.FirstLetter(newPtr->item,1)<<" set"<<endl;
					}

					newPtr->next=_head;
					_head=newPtr;
					return true;
			}
			else
			{
				bool cases=false;
				ListNode* cur;
				/*int indexs=LetterCheck(COM.FirstLetter(newPtr->item),true);//Check from specific index
				if(indexs!=-1)
				{
					cout<<"Item of letter looking at: "<<COM.FirstLetter(newPtr->item)<<endl;
					cur=Indexes[indexs];
					cases=true;
				}
				else*/
					cur=_head;

				ListNode* prev=cur;
				while(cur!=NULL /*|| ((cur!=Indexes[indexs+1]) && cases==true)*/)//for whole list
				{
					if(COM.Compare(newPtr->item,cur->item))
					{
						int index=LetterCheck(COM.FirstLetter(newPtr->item,1),false);
						if(index!=-1)
						{
							Indexes[index]=newPtr;//Set index of first item
							cout<<"Index of "<<COM.FirstLetter(newPtr->item,1)<<" set"<<endl;
						}

						prev->next=newPtr;//add infront of current
						newPtr->next=cur;
						return true;
					}	
					prev=cur;
					cur=cur->next;//traverse to next
				}

				int index=LetterCheck(COM.FirstLetter(newPtr->item,1),false);
				if(index!=-1)
				{
					Indexes[index]=newPtr;//Set index of first item
					cout<<"Index of "<<COM.FirstLetter(newPtr->item,1)<<" set"<<endl;
				}

				prev->next=newPtr;//assign at the end
				newPtr->next=NULL;
				return true;
			}
		}
			
	}	
	bool remove(int index)//remove from index
	{
		ListNode* cur;

		if((index<0) || (index>=size()))//if not found/invalid
			return false;
		else
		{
			--_size;
			if(index==0)//if at head
			{
				cur=_head;
				_head=_head->next;
			}
			else
			{
				//go to position and delete
				ListNode* prev = transverseTo(index-1);
				cur=prev->next;
				prev->next=cur->next;
			}

			delete cur;//deletion
			cur=NULL;//set pointer to null
		}
		return true;//found
	}

	bool retrieve(int index,T& dataItem)
	{
	if((index<0) || (index>=size()))//if index not found/invalid
		return false;
	else
	{
		ListNode* cur;
		cur = transverseTo(index);//go to position
		dataItem=cur->item;//set dataitem to item
	}
	return true;
	}

	T operator [](int index)//subscript overload
	{
		return transverseTo(index)->item;
	}

	/*ListNode* quickTraverse(int index)
	{
		if((index<0) || (index>=size()))
			return NULL;
		else
		{
			ListNode* cur =_head;
			for(int skip=0; skip<index; skip++)
				cur=cur->next;
			return cur;
		}
	}*/


	bool quickretreive(char letter,int index,T& dataItem)
	{

		int index=LetterCheck(letter,false);
		ListNode* cur;

		
		if(index!=-1)
			cur=Indexes[index];

		cur = transverseTo(index);//go to position
		dataItem=cur->item;//set dataitem to item
		
		return true;
	}
	

};

#endif