#include<iostream>
#include "LinkedList.h"

using namespace std;

// Find the kth element to the end of the linked list
LinkedListNode* FindKthToLast(LinkedListNode* head, int k)
{
	if (head == NULL || head->next == NULL)
		return head;

	LinkedListNode* p1 = head;
	LinkedListNode* p2 = head;
	int c = 0;
	while (p1 != NULL)
	{
		// p2 is k steps behind p1
		if (c >= k)
			p2 = p2->next;

		c++;
		p1 = p1->next;
	}

	return p2;
}

void main()
{
	LinkedListNode* head = new LinkedListNode(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 4);
	head = addToTail(head, 5);
	head = addToTail(head, 6);
	head = addToTail(head, 7);
	printLinkedList(head);

	LinkedListNode* node = FindKthToLast(head, 2);
	cout << node->value << "\n";

	system("pause");
}