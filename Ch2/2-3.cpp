#include<iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* next;

	Node(int v)
	{
		value = v;
		next = NULL;
	}
};

Node* addToTail(Node* head, int n)
{
	Node* node = new Node(n);
	if (head == NULL)
		return node;

	Node* p = head;
	while(p->next != NULL)
		p = p->next;

	p->next = node;
	return head;
}

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