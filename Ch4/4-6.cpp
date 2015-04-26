#include<iostream>
#include "BinaryTree.h"

using namespace std;

// Find the next node (in-order successor) in a binary search tree
BinaryTreeNode* findNextNode(BinaryTreeNode* node)
{
	if (node == NULL)
		return NULL;

	if (node->right != NULL)
	{
		// The next node is in the right subtree
		BinaryTreeNode* p = node->right;
		while (p->left != NULL)
			p = p->left;

		return p;
	}
	else
	{
		// The next node is an ancestor
		BinaryTreeNode* p = node;
		while (p->parent != NULL && p->parent->right == p)
			p = p->parent;

		if (p->parent != NULL)
			return p->parent;
		else
			return NULL;
	}
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
	root = addNodeToBST(root, 2);
	root = addNodeToBST(root, 6);
	root = addNodeToBST(root, 1);
	root = addNodeToBST(root, 3);
	root = addNodeToBST(root, 4);

	BinaryTreeNode* n1 = findNextNode(root->left->left);
	BinaryTreeNode* n2 = findNextNode(root->left->right->right);
	BinaryTreeNode* n3 = findNextNode(root);

	cout << n1->value << ", " << n2->value << ", " << n3->value << "\n";
	system("pause");
}