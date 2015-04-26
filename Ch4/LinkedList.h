#include<iostream>
#include "BinaryTree.h"

using namespace std;

class LinkedListNode
{
public:
	BinaryTreeNode* value;
	LinkedListNode* next;

	LinkedListNode(BinaryTreeNode* v)
	{
		value = v;
		next = NULL;
	}

	~LinkedListNode()
	{}
};

LinkedListNode* addToHead(LinkedListNode* head, BinaryTreeNode* n);

LinkedListNode* addToTail(LinkedListNode* head, BinaryTreeNode* n);

void printLinkedList(LinkedListNode* head);