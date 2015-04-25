#include<iostream>
#include "LinkedList.h"

using namespace std;

Node* FindKthToLast(Node* head, int k)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* p1 = head;
	Node* p2 = head;
	int c = 0;
	while (p1 != NULL)
	{
		if (c >= k)
			p2 = p2->next;

		c++;
		p1 = p1->next;
	}

	return p2;
}

void main()
{
	Node* head = new Node(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 4);
	head = addToTail(head, 5);
	head = addToTail(head, 6);
	head = addToTail(head, 7);

	Node* p = head;
	while(p != NULL)
	{
		cout << p->value << ", ";
		p = p->next;
	}
	cout << "\n";

	Node* node = FindKthToLast(head, 2);
	cout << node->value << "\n";

	system("pause");
}