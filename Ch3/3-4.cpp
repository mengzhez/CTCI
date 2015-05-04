#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// Implement the problem Towers of Hanoi using stacks
// Move the top n plates from stack i1 to i2 (0-based index)
void moveStack(vector<stack<int>> &s, int n, int i1, int i2)
{
	// Exit condition
	if (n == 0)
		return;
	else if (n == 1)
	{
		s[i2].push(s[i1].top()); s[i1].pop();
		cout << "Move from " << i1 << " to " << i2 << "\n";
		return;
	}

	int temp = 3 - i1 - i2;
	moveStack(s, n - 1, i1, temp);

	s[i2].push(s[i1].top()); s[i1].pop();
	cout << "Move from " << i1 << " to " << i2 << "\n";

	moveStack(s, n - 1, temp, i2);
}

void main()
{
	vector<stack<int>> s = vector<stack<int>>(3, stack<int>());
	s[0].push(4);
	s[0].push(3);
	s[0].push(2);
	s[0].push(1);

	moveStack(s, s[0].size(), 0, 2);
	system("pause");
}