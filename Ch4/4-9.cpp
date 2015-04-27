#include<iostream>
#include<string>
#include "BinaryTree.h"

using namespace std;

// Print all the paths which have the sum equal to a given number 
void printPaths(BinaryTreeNode* root, string &path, int n)
{
	if (root == NULL || root->value > n)
		return;

	if (root->value == n)
	{
		path += ('0' + root->value);
		cout << path << "\n";
	}

	string p = path;
	p += ('0' + root->value);
	p += " -> ";
	
	string s = "";
	if (root->left != NULL)
	{
		// Check the path recursively
		printPaths(root->left, p, n - root->value);
		
		// Check the path starting from root->left
		printPaths(root->left, s, n);
	}

	if (root->right != NULL)
	{
		// Check the path recursively
		printPaths(root->right, p, n - root->value);
		
		// Check the path starting from root->right
		printPaths(root->right, s, n);
	}
}

void main()
{
	//      1
	//     / \
	//    3   6    
	//   / \
	//  4   2
	//       \
	//        5
	BinaryTreeNode* root = new BinaryTreeNode(1);
	root->left = new BinaryTreeNode(3);
	root->left->left = new BinaryTreeNode(4);
	root->left->right = new BinaryTreeNode(2);
	root->left->right->right = new BinaryTreeNode(5);
	root->right = new BinaryTreeNode(6);

	string s = "";
	printPaths(root, s, 7);
	system("pause");
}