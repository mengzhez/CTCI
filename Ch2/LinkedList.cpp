#include<iostream>
#include "LinkedList.h"

using namespace std;

Node* addToHead(Node* head, int n)
{
	Node* node = new Node(n);
	if (head == NULL)
		return node;

	node->next = head;
	head = node;
	return head;
}

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