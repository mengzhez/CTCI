#include<iostream>
#include<stack>
using namespace std;

class Stack
{
private:
	stack<int> values;
	stack<int> mins;

public:
	Stack()
	{
	}

	~Stack()
	{
	}

	void push(int n)
	{
		values.push(n);

		if (mins.empty())
			mins.push(n);
		else
			mins.push(min(mins.top(), n));
	}

	void pop()
	{
		values.pop();
		mins.pop();
	}

	int top()
	{
		return values.top();
	}

	int minTop()
	{
		return mins.top();
	}

	bool empty()
	{
		return values.empty();
	}
};

void main()
{
	Stack s;
	s.push(3);
	s.push(5);
	s.push(2);
	s.push(8);

	while (!s.empty())
	{
		cout << s.minTop() << ", ";
		s.pop();
	}
	cout << "\n";
	system("pause");
}
