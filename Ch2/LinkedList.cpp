#include<iostream>
#include "LinkedList.h"

using namespace std;

LinkedListNode* addToHead(LinkedListNode* head, int n)
{
	LinkedListNode* node = new LinkedListNode(n);
	if (head == NULL)
		return node;

	node->next = head;
	head = node;
	return head;
}

LinkedListNode* addToTail(LinkedListNode* head, int n)
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