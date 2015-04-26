#include<iostream>
#include "LinkedList.h"

using namespace std;

// Delete the node in the middle when only the access to that node is given
// The code cannot delete the last node
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
	printLinkedList(head);

	deleteMiddleNode(head->next->next);
	printLinkedList(head);

	system("pause");
}