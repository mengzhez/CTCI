#include<iostream>
#include<stack>
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

bool isPalindrome(Node* head)
{
	if (head == NULL || head->next == NULL)
		return true;

	stack<int> s;
	Node* p1 = head;
	Node* p2 = head;
	while (p1 != NULL && p1->next != NULL)
	{
		s.push(p2->value);

		p1 = p1->next->next;
		p2 = p2->next;
	}

	if (p1 != NULL)
		p2 = p2->next;

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
	Node* head = new Node(1);
	head = addToTail(head, 2);
	head = addToTail(head, 3);
	head = addToTail(head, 2);
	head = addToTail(head, 1);

	bool b = isPalindrome(head);
	cout << (b ? "true" : "false") << "\n";
	system("pause");
}