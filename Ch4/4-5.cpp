#include<iostream>
#include "BinaryTree.h"

using namespace std;

// Check if a binary tree is a binary search tree
// Could use a global variable to implement in-order traversal to make the algorithm better
bool checkBST(BinaryTreeNode* root)
{
	if (root == NULL)
		return true;

	// Check the left subtree
	if (root->left != NULL)
	{
		// Check the biggest node in the left subtree
		BinaryTreeNode* p = root->left;
		while (p->right != NULL)
			p = p->right;

		if (root->value < p->value)
			return false;

		if (!checkBST(root->left))
			return false;
	}

	// Check the right subtree
	if (root->right != NULL)
	{
		// Check the smallest node in the right subtree
		BinaryTreeNode* p = root->right;
		while (p->left != NULL)
			p = p->left;

		if (root->value >= p->value)
			return false;

		if (!checkBST(root->right))
			return false;
	}

	return true;
}

void main()
{
	//      5
	//     / \
	//    2   6    
	//   / \
	//  1   3
	//       \
	//        4
	BinaryTreeNode* root = new BinaryTreeNode(5);
	root->left = new BinaryTreeNode(2);
	root->left->left = new BinaryTreeNode(1);
	root->left->right = new BinaryTreeNode(3);
	root->left->right->right = new BinaryTreeNode(4);
	root->right = new BinaryTreeNode(6);

	bool b = checkBST(root);
	cout << (b ? "True" : "False") << "\n";
	system("pause");
}