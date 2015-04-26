#include<iostream>
#include "LinkedList.h"

using namespace std;

// Find the beginning of the loop in a circular linked list
// The code doesn't work when the linked list is not a circular linked list
LinkedListNode* findLoopBeginning(LinkedListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	LinkedListNode* p1 = head;
	LinkedListNode* p2 = head;
	while (p1 != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;

		// Let p1 has twice length of p2
		if (p1 == p2)
			break;
	}

	p2 = head;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}

void main()
{
	LinkedListNode* head = new LinkedListNode(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 4);
	head = addToTail(head, 5);
	LinkedListNode* p = head;
	while (p->next != NULL)
		p = p->next;

	p->next = head->next->next;
	
	p = findLoopBeginning(head);
	cout << p->value << "\n";
	system("pause");
}