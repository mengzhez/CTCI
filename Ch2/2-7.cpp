#include<iostream>
#include<stack>
#include "LinkedList.h"

using namespace std;

// Check if a linked list is a palindrome
bool isPalindrome(LinkedListNode* head)
{
	if (head == NULL || head->next == NULL)
		return true;

	stack<int> s;
	LinkedListNode* p1 = head;
	LinkedListNode* p2 = head;

	// Find the middle of the linked list and push the first half into a stack
	while (p1 != NULL && p1->next != NULL)
	{
		s.push(p2->value);

		p1 = p1->next->next;
		p2 = p2->next;
	}

	if (p1 != NULL)
		p2 = p2->next;

	// Compare the elements in stack with the second half
	while (!s.empty())
	{
		if (p2->value != s.top())
			return false;

		s.pop();
		p2 = p2->next;
	}

	return true;
}

void main()
{
	LinkedListNode* head = new LinkedListNode(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 2);
	head = addToTail(head, 1);

	bool b = isPalindrome(head);
	cout << (b ? "True" : "False") << "\n";
	system("pause");
}