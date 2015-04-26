#include<iostream>
#include "LinkedList.h"

using namespace std;

// Delete the node in the middle when only the access to that node is given
// Could not delete the last node
void deleteMiddleNode(LinkedListNode* mid)
{
	if (mid == NULL)
		return;

	LinkedListNode* p1 = mid->next;
	LinkedListNode* p2 = mid;
	p2->value = p1->value;

	if (p1 != NULL)
		p2->next = p1->next;

	delete p1;
	p1 = NULL;
}

void main()
{
	LinkedListNode* head = new LinkedListNode(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 4);
	head = addToTail(head, 5);

	LinkedListNode* p = head;
	while(p != NULL)
	{
		cout << p->value << ", ";
		p = p->next;
	}
	cout << "\n";

	deleteMiddleNode(head->next->next);
	
	p = head;
	while(p != NULL)
	{
		cout << p->value << ", ";
		p = p->next;
	}
	cout << "\n";

	system("pause");
}