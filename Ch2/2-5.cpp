#include<iostream>
#include "LinkedList.h"

using namespace std;

Node* addForward(Node* n1, Node* n2)
{
	int num1 = 0;
	int num2 = 0;
	Node* p1 = n1;
	Node* p2 = n2;
	while (p1 != NULL || p2 != NULL)
	{
		if (p1 != NULL)
		{
			num1 = num1 * 10 + p1->value;
			p1 = p1->next;
		}

		if (p2 != NULL)
		{
			num2 = num2 * 10 + p2->value;
			p2 = p2->next;
		}
	}

	int num = num1 + num2;
	Node* n = NULL;
	while (num > 0)
	{
		n = addToHead(n, (num % 10));
		num /= 10;
	}

	return n;
}

Node* addReverse(Node* n1, Node* n2)
{
	int num1 = 0;
	int num2 = 0;
	Node* p1 = n1;
	Node* p2 = n2;
	int exp = 0;
	while (p1 != NULL || p2 != NULL)
	{
		if (p1 != NULL)
		{
			num1 += (p1->value * pow(10, exp));
			p1 = p1->next;
		}

		if (p2 != NULL)
		{
			num2 += (p2->value * pow(10, exp));
			p2 = p2->next;
		}

		exp++;
	}

	int num = num1 + num2;
	Node* n = NULL;
	while(num > 0)
	{
		n = addToTail(n, (num % 10));
		num /= 10;
	}
	
	return n;
}

void main()
{
	Node* n1 = new Node(7);
	n1 = addToTail(n1, 1);
	n1 = addToTail(n1, 6);
	
	Node* n2 = new Node(5);
	n2 = addToTail(n2, 9);
	n2 = addToTail(n2, 2);

	Node* nf = addForward(n1, n2);
	Node* nr = addReverse(n1, n2);

	cout << "Forward: ";
	Node* p = nf;
	while (p != NULL)
	{
		cout << p->value;
		p = p->next;
	}

	cout << "\n";

	cout << "Reverse: ";
	p = nr;
	while (p != NULL)
	{
		cout << p->value;
		p = p->next;
	}

	cout << "\n";
	system("pause");
}

