#include<iostream>
#include<string>
using namespace std;

// Print all combinations of n-pair of parentheses
void printParentheses(int n, string str, int left, int right)
{
	if (n == 0)
		return;

	if (left == n && right == n)
	{
		cout << str << endl;
		return;
	}

	string temp_str = str;
	if (left < n)
	{
		temp_str.append("(");
		printParentheses(n, temp_str, left + 1, right);
	}

	temp_str = str;
	if (right < n && left > right)
	{
		temp_str.append(")");
		printParentheses(n, temp_str, left, right + 1);
	}
}

void main()
{
	printParentheses(3, "", 0, 0);
	system("pause");
}