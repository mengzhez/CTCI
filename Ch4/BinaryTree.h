#include<iostream>

using namespace std;

class BinaryTreeNode
{
public:
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(int v)
	{ 
		value = v;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode()
	{}
};

BinaryTreeNode* addNodeToBST(BinaryTreeNode* root, int val);