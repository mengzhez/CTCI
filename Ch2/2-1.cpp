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

Node* removeDuplicates(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* p1 = head;
	Node* p2 = head;
	while (p1->next != NULL)
	{
		p2 = head;
		while (p2 != p1->next)
		{
			if (p2->value == p1->next->value)
			{
				Node* temp = p1->next->next;
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
	Node* head = new Node(1);
	head = addToTail(head, 4);
	head = addToTail(head, 1);
	head = addToTail(head, 3);
	head = addToTail(head, 1);
	head = addToTail(head, 3);
	head = addToTail(head, 7);

	Node* p = head;
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