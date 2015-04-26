#include<iostream>

using namespace std;

class BinaryTreeNode
{
public:
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	// Only used in 4-6
	BinaryTreeNode* parent;

	BinaryTreeNode(int v)
	{ 
		value = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	~BinaryTreeNode()
	{}
};

BinaryTreeNode* addNodeToBST(BinaryTreeNode* root, int val);