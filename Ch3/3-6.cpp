#include<iostream>
#include<stack>

using namespace std;

void sortStack(stack<int> &s)
{
	stack<int> help;

	while (!s.empty())
	{
		int temp = s.top();
		int count = 0;
		s.pop();
		while (!help.empty() && help.top() < temp)
		{
			s.push(help.top());
			help.pop();
			count++;
		}

		s.push(temp);
		for (int i = 0; i <= count; i++)
		{
			help.push(s.top());
			s.pop();
		}
	}

	while (!help.empty())
	{
		s.push(help.top());
		help.pop();
	}
}


void main()
{
	stack<int> s;
	s.push(12);
	s.push(6);
	s.push(5);
	s.push(1);
	s.push(9);
	stack<int> temp = s;
	while (!temp.empty())
	{
		cout << temp.top() << ", ";
		temp.pop();
	}
	cout << "\n";

	sortStack(s);
	temp = s;
	while (!temp.empty())
	{
		cout << temp.top() << ", ";
		temp.pop();
	}
	cout << "\n";

	system("pause");
}