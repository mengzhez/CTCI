#include<iostream>
#include<vector>
#include "BinaryTree.h"

using namespace std;

// Create a binary search tree with minimal height using a given array 
BinaryTreeNode* createBST(vector<int> v)
{
	int n = v.size();
	if (n == 0)
		return NULL;

	// Find the middle element of the array and create the node
	int m = n / 2;
	BinaryTreeNode* node = new BinaryTreeNode(v[m]);

	if (m - 1 >= 0)
	{
		// Create the left subtree
		vector<int> vl = vector<int>(v.begin(), v.begin() + m);
		node->left = createBST(vl);
	}

	if (m + 1 < n)
	{
		// Create the right subtree
		vector<int> vr = vector<int>(v.begin() + m + 1, v.end());
		node->right = createBST(vr);
	}

	return node;
}



void main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	BinaryTreeNode* root = createBST(v);
	// The final result is a balanced BST which is tested in Debug mode
	//       4
	//     /   \
	//    2     6
	//   / \   / \
	//  1   3 5   7
	system("pause");
}