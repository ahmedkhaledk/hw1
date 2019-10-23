

#include  "solution.h"
#include  <iostream>
#include  <string>


using namespace std;

int main()
{
	ArrayList a1 = ArrayList(10);
	ArrayList a2 = ArrayList(5);
	DoublyLinkedList l1 = DoublyLinkedList();

	List *lists[] = {
	&a1,
	&a2,
	&l1,
	nullptr
	};
	int index = 0;
	List *list = lists[0];
	while (list != nullptr)
	{
	printf("GetSize: %d\r\n", list->GetSize());

	printf("AppendItem %s\r\n", list->AppendItem(5) ? "succeeded" : "failed");
	printf("AppendItem %s\r\n", list->AppendItem(3) ? "succeeded" : "failed");
	printf("AppendItem %s\r\n", list->PrependItem(7) ? "succeeded" : "failed");
	printf("GetSize: %d\r\n", list->GetSize());
	printf("AppendItem %s\r\n", list->AppendItem(0) ? "succeeded" : "failed");
	printf("AppendItem %s\r\n", list->PrependItem(6) ? "succeeded" : "failed");
	printf("AppendItem %s\r\n", list->AppendItem(9) ? "succeeded" : "failed");
	printf("AppendItem %s\r\n", list->PrependItem(8) ? "succeeded" : "failed");
	printf("GetSize: %d\r\n", list->GetSize());
	printf("GetItemAt: %d\r\n", list->GetItemAt(4));
	printf("GetItemAt: %d\r\n", list->GetItemAt(8));

	list->Print();
	list->ReversePrint();

	list = lists[++index];

	}
	
	cout << "Main: this works";
	return 0;
}

