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

Node* addToHead(Node* head, int n);

Node* addToTail(Node* head, int n);