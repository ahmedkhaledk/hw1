


// Headers files

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
// this function of type unsigned int and it does not take 
// any argument and it will return the the size of the list
unsigned int List::GetSize()

{
 
	return size;

}



// this function Print has a type void and does not take 
// any arguments. it wwill print out each item in the list from first to last



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

// this function has a type of void and 
//prints out each item in the list from last to first

void List::ReversePrint()
{


 
	for (int i = size - 1; i > -1; i--) {
		cout << GetItemAt(i);
	}
	

}


// this function ArrayList derives from List.    
//The constructor should take an unsigned int specifying the capacity of the 

ArrayList::ArrayList(unsigned int capacity)

{


	CAPACITY = capacity;

	ITEMS = new ListItem[CAPACITY];

	ITEMS_COUNT = 0;

}

// this function has a type of bool and it should fail  should fail meaning ruturn false
//if the array is full.
bool ArrayList::AppendItem(ListItem item)

{

	if (ITEMS_COUNT == CAPACITY)

		return false;

	ITEMS[ITEMS_COUNT] = item;

	ITEMS_COUNT++;

	return true;

}

// this function is type of bool and and it should fail  should fail meaning ruturn false
//if the array is full.
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

// this function GetItemAt takes unsigned int as an argument and return 
// the iteam

ListItem ArrayList::GetItemAt(unsigned int i)

{

	return ITEMS[i];

}

// this function has a type of void and takes one argument and 
//deletes the list item at the passed-in index

void ArrayList::DeleteItemAt(unsigned int i)

{

	for (unsigned int start = i; start < ITEMS_COUNT - 1; start++)

	{

		ITEMS[i] = ITEMS[i + 1];

	}

	ITEMS_COUNT--;

}
// this function call the List class Print function and then print 
//the contents of the list in the format "\t[0, 1, 2, 3]"
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

// this function should fail (return false) if the array is full.
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

//  PrependItem should fail (i.e. return false) if the array is full.


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
//this function should first call the List class Print function
//and then print the contents of the list in the format "\t[0, 1, 2, 3]"

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