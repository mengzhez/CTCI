#include<iostream>
#include "LinkedList.h"

using namespace std;

void deleteMiddleNode(Node* mid)
{
	Node* p1 = mid;
	Node* p2 = NULL;
	while (p1->next != NULL)
	{
		p1->value = p1->next->value;
		p2 = p1;
		p1 = p1->next;
	}

	delete p1;
	p1 = NULL;
	p2->next = NULL;
}

void main()
{
	Node* head = new Node(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 4);
	head = addToTail(head, 5);

	Node* p = head;
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