#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
private:
	int size;
	struct Node
	{
		T item;
		Node* next;
	};
	Node* _head;
	Node* _tail;
public:
	Queue()
	{
		_head= 0;
		_tail= 0;
		size=0;
	}
	T& dequeue()
	{ 
		Node* cur;
		cur=_head;
		if(!empty())
		_head=_head->next;
		T* t = new T;
		*t=cur->item;
		delete cur;
		size--;
		return *t;
	}
	void enqueue(T Item)
	{
		Node* N = new Node;
		N->item = Item;
		if(!empty())
		_tail->next=N;
		else
			{
				_tail=N;
				_head=N;
		    }
		//N->next=NULL;
		N->next=0;
		_tail=N;
		size++;
		return;
	}
	bool empty(){return (size==0);}

};
#endif
