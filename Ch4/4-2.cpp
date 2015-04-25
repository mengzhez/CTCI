#include<iostream>
#include "Graph.h"

using namespace std;

bool checkPath(Node* n1, Node* n2)
{
	n1->visited = true;

	if (n1 == n2)
		return true;

	for (int i = 0; i < n1->adj.size(); i++)
	{
		if (!n1->adj[i]->visited && checkPath(n1->adj[i], n2))
			return true;
	}

	return false;
}

void main()
{
	//    1
	//   / \
	//  2 - 3 - 4 <- 5  
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	n1->adj.push_back(n2);
	n1->adj.push_back(n3);
	n2->adj.push_back(n1);
	n2->adj.push_back(n3);
	n3->adj.push_back(n1);
	n3->adj.push_back(n2);
	n3->adj.push_back(n4);
	n4->adj.push_back(n3);
	n5->adj.push_back(n4);
	
	bool b = checkPath(n1, n5);
	cout << (b ? "True" : "False") << "\n";
	system("pause");
}