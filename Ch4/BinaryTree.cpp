#include<iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTreeNode* addNodeToBST(BinaryTreeNode* root, int val)
{
	BinaryTreeNode* node = new BinaryTreeNode(val);
	
	if (root == NULL)
		return node;

	BinaryTreeNode* n = root;
	while (!n == NULL)
	{
		if (val <= n->value)
		{
			if (n->left == NULL)
			{
				n->left = node;
				break;
			}
			else
				n = n->left;
		}
		else
		{
			if (n->right == NULL)
			{
				n->right = node;
				break;
			}
			else
				n = n->right;
		}
	}

	return root;
}