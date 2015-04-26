#include<iostream>
#include "LinkedList.h"

using namespace std;

LinkedListNode* addForward(LinkedListNode* n1, LinkedListNode* n2)
{
	int num1 = 0;
	int num2 = 0;
	LinkedListNode* p1 = n1;
	LinkedListNode* p2 = n2;
	while (p1 != NULL || p2 != NULL)
	{
		// Compute the first number
		if (p1 != NULL)
		{
			num1 = num1 * 10 + p1->value;
			p1 = p1->next;
		}

		// Compute the second number
		if (p2 != NULL)
		{
			num2 = num2 * 10 + p2->value;
			p2 = p2->next;
		}
	}

	int num = num1 + num2;
	LinkedListNode* n = NULL;
	while (num > 0)
	{
		n = addToHead(n, (num % 10));
		num /= 10;
	}

	return n;
}

LinkedListNode* addReverse(LinkedListNode* n1, LinkedListNode* n2)
{
	int num1 = 0;
	int num2 = 0;
	LinkedListNode* p1 = n1;
	LinkedListNode* p2 = n2;
	int exp = 0;
	while (p1 != NULL || p2 != NULL)
	{
		// Compute the first number
		if (p1 != NULL)
		{
			num1 += (p1->value * pow(10, exp));
			p1 = p1->next;
		}

		// Compute the second number
		if (p2 != NULL)
		{
			num2 += (p2->value * pow(10, exp));
			p2 = p2->next;
		}

		exp++;
	}

	int num = num1 + num2;
	LinkedListNode* n = NULL;
	while(num > 0)
	{
		n = addToTail(n, (num % 10));
		num /= 10;
	}
	
	return n;
}

void main()
{
	LinkedListNode* n1 = new LinkedListNode(7);
	n1 = addToTail(n1, 1);
	n1 = addToTail(n1, 6);
	
	LinkedListNode* n2 = new LinkedListNode(5);
	n2 = addToTail(n2, 9);
	n2 = addToTail(n2, 2);

	LinkedListNode* nf = addForward(n1, n2);
	LinkedListNode* nr = addReverse(n1, n2);

	cout << "Forward: ";
	LinkedListNode* p = nf;
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

