#pragma once
typedef int ListItem;

#define INVALID_LIST_ITEM (-1)
//#include  <vector>
#include  "stdio.h"
using namespace std;


class List
{

public:

	unsigned int GetSize();
	virtual bool AppendItem(ListItem)= 0;
	virtual bool PrependItem(ListItem) =0;
	virtual ListItem GetItemAt(unsigned int) =0;
	virtual void DeleteItemAt(unsigned int)= 0;

	 List();
	~List();
	void Print();
	void ReversePrint();

	protected:
	int size;
};

class ArrayList:public List
{
public:
	ArrayList(unsigned int Capacity);

	bool AppendItem(ListItem item);

	bool PrependItem(ListItem item);

	ListItem GetItemAt(unsigned int i);

	void DeleteItemAt(unsigned int i);

	void Print();

private:

	 unsigned int CAPACITY;

	 unsigned int ITEMS_COUNT;

	 ListItem* ITEMS;

};

struct Node {

	ListItem data_;

	Node* next_;

	Node(ListItem data)

	{

		data_ = data;

	}

};

class DoublyLinkedList : public List {

public:

	Node * head;

	Node* tail;

	bool AppendItem(ListItem item);

	bool PrependItem(ListItem item);

	ListItem GetItemAt(unsigned int i);

	void DeleteItemAt(unsigned int i);

	void Print();

private:

	unsigned int node_count_ = 0;

};