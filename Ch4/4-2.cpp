#include<iostream>
#include "Graph.h"

using namespace std;

// Check there is a feasible path between two nodes in a graph
bool checkPath(GraphNode* n1, GraphNode* n2)
{
	n1->visited = true;

	if (n1 == n2)
		return true;

	for (int i = 0; i < n1->adj.size(); i++)
	{
		// Use DFS
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
	GraphNode* n1 = new GraphNode(1);
	GraphNode* n2 = new GraphNode(2);
	GraphNode* n3 = new GraphNode(3);
	GraphNode* n4 = new GraphNode(4);
	GraphNode* n5 = new GraphNode(5);
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