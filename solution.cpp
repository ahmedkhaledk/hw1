


// Headers 

#include "solution.h"
#include "iostream"
//#include <array>

using ::List;

using ::ArrayList;

using ::DoublyLinkedList;

// Creating a constructor 
List::List()

{}

// creating a destructor 
List::~List()

{ 

}

unsigned int List::GetSize()

{
 
	return size;

}







void List::Print()

{

	int i = size;
	std::cout << "I'm a list. My size is " << i << std::endl;

	std::cout << "[ ";

	for (i; i < size; i++)
	{
		cout << GetItemAt(i);
	}

	std::cout << " ]";

}

void List::ReversePrint()
{


 
	for (int i = size - 1; i > -1; i--) {
		cout << GetItemAt(i);
	}
	

}

ArrayList::ArrayList(unsigned int capacity)

{


	CAPACITY = capacity;

	ITEMS = new ListItem[CAPACITY];

	ITEMS_COUNT = 0;

}

bool ArrayList::AppendItem(ListItem item)

{

	if (ITEMS_COUNT == CAPACITY)

		return false;

	ITEMS[ITEMS_COUNT] = item;

	ITEMS_COUNT++;

	return true;

}

bool ArrayList::PrependItem(ListItem item)

{

	if (ITEMS_COUNT == CAPACITY)

		return false;

	for (unsigned int i = ITEMS_COUNT; i > 0; i--)

	{

		ITEMS[i] = ITEMS[i - 1];

	}

	ITEMS[0] = item;

	return true;

}

ListItem ArrayList::GetItemAt(unsigned int i)

{

	return ITEMS[i];

}

void ArrayList::DeleteItemAt(unsigned int i)

{

	for (unsigned int start = i; start < ITEMS_COUNT - 1; start++)

	{

		ITEMS[i] = ITEMS[i + 1];

	}

	ITEMS_COUNT--;

}

void ArrayList::Print()

{

	std::cout << "I'm a list. My size is " << ITEMS_COUNT << std::endl;

	std::cout << "[ ";

	for (unsigned int i = 0; i < ITEMS_COUNT; i++)

	{

		std::cout << ITEMS[i] << " ";

	}

	std::cout << " ]";

}

bool DoublyLinkedList::AppendItem(ListItem item)

{

	Node* temp = new Node(item);

	if (!temp)

		return false;

	if (!head)

	{

		head = temp;

		tail = temp;

	}

	else

	{

		tail->next_ = temp;

		tail = temp;

	}

	node_count_++;
	size--;
	return true;

}

bool DoublyLinkedList::PrependItem(ListItem item)

{

	Node* temp = new Node(item);

	if (!temp)

		return false;

	if (!head)

	{

		head = temp;

		tail = temp;

	}
	else
	{

		temp->next_ = head;

		head = temp;

	}

	node_count_++;
	size++;
	return true;

}

ListItem DoublyLinkedList::GetItemAt(unsigned int i)

{

	Node* tmp = head;

	for (unsigned int index = 1; index < i; index++)

	{
		cout << index << " is less than " << i << endl;
		cout << tmp->data_ << endl;
		tmp = tmp->next_;

	}

	//return tmp->data_;
	return 0;
}

void DoublyLinkedList::DeleteItemAt(unsigned int i)

{
	Node* tmp = head;

	if (i >= size) {
		return;
	}
	 
	
	//Node* tmp = head;
	

	for (unsigned int index = 0; index < i; index++)

	{

		tmp = tmp->next_;

	}

	tmp->next_ = tmp->next_->next_;

}

void DoublyLinkedList::Print()

{

	if (!head)

		return;

	Node* tmp = head;

	std::cout << "I'm a list. My size is " << node_count_++ << std::endl;

	std::cout << "[ ";

	while (tmp)

	{

		std::cout << tmp->data_ << " ";

	}

	std::cout << " ]";

}