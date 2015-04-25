#include<iostream>
#include<vector>

using namespace std;

class Node
{
public:
	int value;
	vector<Node*> adj;
	bool visited;

	Node(int v)
	{ 
		value = v;
		visited = false;
	}

	~Node()
	{}
};