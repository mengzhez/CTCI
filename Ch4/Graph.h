#include<iostream>
#include<vector>

using namespace std;

class GraphNode
{
public:
	int value;
	vector<GraphNode*> adj;
	bool visited;

	GraphNode(int v)
	{ 
		value = v;
		visited = false;
	}

	~GraphNode()
	{}
};