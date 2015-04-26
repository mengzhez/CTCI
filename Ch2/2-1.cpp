#include<iostream>
#include "LinkedList.h"

using namespace std;

// Remove duplicates from an unsorted linked list
// No additional buffer is used here. If we can use other buffers, Hash table will be better
LinkedListNode* removeDuplicates(LinkedListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	LinkedListNode* p1 = head;
	LinkedListNode* p2 = head;
	while (p1->next != NULL)
	{
		p2 = head;
		while (p2 != p1->next)
		{
			// Find and delete duplicates
			if (p2->value == p1->next->value)
			{
				LinkedListNode* temp = p1->next->next;
				delete p1->next;
				p1->next = temp;
				break;
			}

			p2 = p2->next;
		}

		if (p2 == p1->next)
			p1 = p1->next;
	}

	return head;
}

void main()
{
	LinkedListNode* head = new LinkedListNode(1);
	head = addToTail(head, 4);
	head = addToTail(head, 1);
	head = addToTail(head, 3);
	head = addToTail(head, 1);
	head = addToTail(head, 3);
	head = addToTail(head, 7);

	LinkedListNode* p = head;
	while(p != NULL)
	{
		cout << p->value << ", ";
		p = p->next;
	}
	cout << "\n";

	head = removeDuplicates(head);
	
	p = head;
	while(p != NULL)
	{
		cout << p->value << ", ";
		p = p->next;
	}
	cout << "\n";

	system("pause");
}