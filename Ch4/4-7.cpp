#include<iostream>
#include<vector>
#include "BinaryTree.h"

using namespace std;

// Find the first common ancestor of two nodes
BinaryTreeNode* ancestor;
bool findAncestor(BinaryTreeNode* root, BinaryTreeNode* n1, BinaryTreeNode* n2)
{
	if (root == NULL)
		return false;

	if (root == n1 || root == n2)
		return true;

	// If we find two nodes in the left subtree and the right subtree respectively, the current node is the first common ancestor
	bool left = findAncestor(root->left, n1, n2);
	bool right = findAncestor(root->right, n1, n2);
	if (left && right)
	{
		ancestor = root;
		return true;
	}
	else if (left || right)
		return true;
	else
		return false;
}


void main()
{
	//      1
	//     / \
	//    2   6    
	//   / \
	//  3   4
	//       \
	//        5
	BinaryTreeNode* root = new BinaryTreeNode(1);
	root->left = new BinaryTreeNode(2);
	root->left->left = new BinaryTreeNode(3);
	root->left->right = new BinaryTreeNode(4);
	root->left->right->right = new BinaryTreeNode(5);
	root->right = new BinaryTreeNode(6);

	findAncestor(root, root->left->left, root->left->right->right);
	cout << ancestor->value << "\n";

	system("pause");
}