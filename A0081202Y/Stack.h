#ifndef STACK_H
#define STACK_H


template <class T>
class Stack
{
	int _size;
	struct Node
	{
		T item;
		Node* next;
	};
	Node* _head;
public:

	Stack(){_head=NULL;_size=0;}

	~Stack()
	{
		T dummy;
		while(!empty())
		pop(dummy);
	}

	bool getTop( T& stackTop)
	{ 
		if(empty())
			return false;
		else stackTop=_head->item;
		return true;
	}

	bool pop(T& stackTop)
	{
		Node* cur;
		if(empty())
			return false;
		else
		{
			stackTop = _head->item;
			cur = _head;
			_head = _head->next;
			_size--;
			delete cur;
			cur = 0;
			
		}
	return true;
	}

	bool  push(T& Item)
	{ 
		Node* newPtr= new Node;
		newPtr->item = Item;
		newPtr->next = _head;
		_head = newPtr;
		_size++;

		return true;
	}
	bool empty(){return (_size==0);}

	int size(){return _size;}
};
#endif
