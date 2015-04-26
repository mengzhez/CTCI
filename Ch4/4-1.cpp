#include<iostream>
#include "BinaryTree.h"

using namespace std;

int checkBalance(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = checkBalance(root->left);
	int rightHeight = checkBalance(root->right);

	if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1)
		return -1;
	else
		return max(leftHeight, rightHeight) + 1;
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

	int n = checkBalance(root);
	cout << (n != -1 ? "True" : "False") << "\n";
	system("pause");
}