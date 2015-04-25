#include<iostream>
#include "LinkedList.h"

using namespace std;

Node* partitionLinkedList(Node* head, int x)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* p1 = head;
	Node* p2 = NULL;
	Node* mid = NULL;
	while (p1 != NULL)
	{
		if (p1->value < x)
		{
			Node* temp = p1->next;

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
	Node* head = new Node(1);
	head = addToTail(head, 5);
	head = addToTail(head, 9);
	head = addToTail(head, 2);
	head = addToTail(head, 4);
	head = addToTail(head, 7);

	Node* p = head;
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