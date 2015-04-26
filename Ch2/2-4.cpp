#include<iostream>
#include "LinkedList.h"

using namespace std;

// Partition the linked list with a given pivot value
LinkedListNode* partitionLinkedList(LinkedListNode* head, int x)
{
	if (head == NULL || head->next == NULL)
		return head;

	LinkedListNode* p1 = head;
	LinkedListNode* p2 = NULL;

	// mid pointer is used to store where to insert the small element
	LinkedListNode* mid = NULL;

	while (p1 != NULL)
	{
		if (p1->value < x)
		{
			LinkedListNode* temp = p1->next;

			if (mid == NULL)
			{
				mid = p1;
				if (p1 != head)
				{
					p1->next = head;
					head = p1;
				}
			}
			else if (mid->next != p1)
			{
				p1->next = mid->next;
				mid->next = p1;
				mid = p1;
			}

			if (p1->next == temp)
				p2 = p1;
			else if (p2 != NULL)
				p2->next = temp;
			
			p1 = temp;
		}
		else
		{
			p2 = p1;
			p1 = p1->next;
		}
	}

	return head;
}

void main()
{
	LinkedListNode* head = new LinkedListNode(1);
	head = addToTail(head, 5);
	head = addToTail(head, 9);
	head = addToTail(head, 2);
	head = addToTail(head, 4);
	head = addToTail(head, 7);

	LinkedListNode* p = head;
	while(p != NULL)
	{
		cout << p->value << ", ";
		p = p->next;
	}
	cout << "\n";

	head = partitionLinkedList(head, 6);

	p = head;
	while(p != NULL)
	{
		cout << p->value << ", ";
		p = p->next;
	}
	cout << "\n";

	system("pause");
}