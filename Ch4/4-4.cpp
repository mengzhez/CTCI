#include<iostream>
#include<vector>
#include "LinkedList.h"

using namespace std;

// Create linked lists of all the nodes at each depth
void createLinkedLists(BinaryTreeNode* root, vector<LinkedListNode*> &v)
{
	if (root == NULL)
		return;

	LinkedListNode* node = new LinkedListNode(root);
	v.push_back(node);

	int depth = 0;
	while (v.size() > depth)
	{
		v.push_back(NULL);
		LinkedListNode* n = v[depth];
		while (n != NULL)
		{
			BinaryTreeNode* left = n->value->left;
			if (left != NULL)
				v[depth + 1] = addToTail(v[depth + 1], left);

			BinaryTreeNode* right = n->value->right;
			if (right != NULL)
				v[depth + 1] = addToTail(v[depth + 1], right);

			n = n->next;
		}

		if (v[depth + 1] == NULL)
			v.pop_back();

		depth++;
	}
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

	vector<LinkedListNode*> v;
	createLinkedLists(root, v);
	for (int i = 0; i < v.size(); i++)
		printLinkedList(v[i]);

	system("pause");
}