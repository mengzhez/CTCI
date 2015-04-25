#include<iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;

	Node(int v)
	{ 
		value = v;
		left = NULL;
		right = NULL;
	}

	~Node()
	{}
};

int checkBalance(Node* root)
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
	Node* root = new Node(1);
	root->left = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	//root->left->right->right = new Node(5);
	root->right = new Node(6);

	int n = checkBalance(root);
	cout << (n != -1 ? "balanced" : "not balanced") << "\n";
	system("pause");
}