#include<iostream>
#include<vector>
using namespace std;

template <class Type> class Stack
{
private:
	vector<vector<Type>> _values;

public:
	Stack()
	{
		_values = vector<vector<Type>>(3, vector<Type>());
	}

	~Stack()
	{}

	void push(Type val, int n)
	{
		if (n >= 0 && n <= 2)
			_values[n].push_back(val);
	}

	void pop(int n)
	{
		if (n >= 0 && n <= 2)
			_values[n].pop_back();
	}

	int top(int n)
	{
		if (n >= 0 && n <= 2)
			return _values[n][_values[n].size() - 1];
		else
			return 0;
	}

	bool empty(int n)
	{
		if (n >= 0 && n <= 2)
			return !_values[n].size();
		else
			return false;
	}
};

void main()
{
	Stack<int> s = Stack<int>();
	s.push(6, 0);
	s.push(8, 0);
	s.push(11, 1);
	s.push(22, 2);
	cout << s.top(0) << ", " << s.top(1) << ", " << s.top(2) << "\n";

	s.pop(2);
	cout << (s.empty(0) ? "true" : "false") << ", " << (s.empty(1) ? "true" : "false") << ", " << (s.empty(2) ? "true" : "false") << "\n";
	
	system("pause");
}