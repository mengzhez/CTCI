#include<iostream>
#include "LinkedList.h"

using namespace std;

Node* findLoopBeginning(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* p1 = head;
	Node* p2 = head;
	while (p1 != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;

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
	Node* head = new Node(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 4);
	head = addToTail(head, 5);
	Node* p = head;
	while (p->next != NULL)
		p = p->next;

	p->next = head->next->next;
	
	p = findLoopBeginning(head);
	cout << p->value << "\n";
	system("pause");
}