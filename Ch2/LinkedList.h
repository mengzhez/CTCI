#include<iostream>

using namespace std;

class LinkedListNode
{
public:
	int value;
	LinkedListNode* next;

	LinkedListNode(int v)
	{
		value = v;
		next = NULL;
	}

	~LinkedListNode()
	{}
};

LinkedListNode* addToHead(LinkedListNode* head, int n);

LinkedListNode* addToTail(LinkedListNode* head, int n);