#include<iostream>
#include<vector>
#include "BinaryTree.h"

using namespace std;

// Check if two trees are identical
bool isIdentical(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	else if (root1 == NULL || root2 == NULL)
		return false;

	if (root1->value == root2->value && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
		return true;
	else
		return false;
}

// Compute the height of the binary tree
int getHeight(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return (max(getHeight(root->left), getHeight(root->right)) + 1);
}

// Find the nodes with given height
int findNodeByHeight(BinaryTreeNode* root, vector<BinaryTreeNode*> &v, int h)
{
	int height = 0;
	if (root == NULL)
		height = 0;
	else
		height = max(findNodeByHeight(root->left, v, h), findNodeByHeight(root->right, v, h)) + 1;

	if (height == h)
		v.push_back(root);

	return height;
}

// Check if tree2 is a subtree of tree1
// Tested with small binary trees, didn't test on large binary trees
bool checkSubtree(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
	// Compute the height of tree2
	int h2 = getHeight(root2);

	// Find the nodes that have height h2
	vector<BinaryTreeNode*> v;
	findNodeByHeight(root1, v, h2);

	for (int i = 0; i < v.size(); i++)
	{
		if (isIdentical(v[i], root2))
			return true;
	}

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
	BinaryTreeNode* root1 = new BinaryTreeNode(1);
	root1->left = new BinaryTreeNode(2);
	root1->left->left = new BinaryTreeNode(3);
	root1->left->right = new BinaryTreeNode(4);
	root1->left->right->right = new BinaryTreeNode(5);
	root1->right = new BinaryTreeNode(6);

	//    2    
	//   / \
	//  3   4
	//       \
	//        5
	BinaryTreeNode* root2 = new BinaryTreeNode(2);
	root2->left = new BinaryTreeNode(3);
	root2->right = new BinaryTreeNode(4);
	root2->right->right = new BinaryTreeNode(5);

	bool b = checkSubtree(root1, root2);
	cout << (b ? "True" : "False") << "\n";
	system("pause");
}