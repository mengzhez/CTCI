#include<iostream>
#include "LinkedList.h"

using namespace std;

LinkedListNode* addToHead(LinkedListNode* head, BinaryTreeNode* n)
{
	LinkedListNode* node = new LinkedListNode(n);
	if (head == NULL)
		return node;

	node->next = head;
	head = node;
	return head;
}

LinkedListNode* addToTail(LinkedListNode* head, BinaryTreeNode* n)
{
	LinkedListNode* node = new LinkedListNode(n);
	if (head == NULL)
		return node;

	LinkedListNode* p = head;
	while(p->next != NULL)
		p = p->next;

	p->next = node;
	return head;
}

void printLinkedList(LinkedListNode* head)
{
	if (head == NULL)
		return;

	LinkedListNode* p = head;
	while(p->next != NULL)
	{
		cout << p->value->value << ", ";
		p = p->next;
	}
	cout << p->value->value << "\n";
}