#include<iostream>
#include<vector>
using namespace std;

const int _STACK_MAX = 2;

// Implement a set of stacks
template <class Type> class SetOfStacks
{
private:
	vector<vector<Type>> _values;
	
public:
	SetOfStacks()
	{
		_values = vector<vector<Type>>(1, vector<Type>());
	}

	~SetOfStacks()
	{}

	void push(Type val)
	{
		int n = _values.size();
		if (n == 0)
			_values = vector<vector<Type>>(1, vector<Type>());

		// Create a new stack
		if (n > 0 && _values[n - 1].size() >= _STACK_MAX)
		{
			vector<Type> v = vector<Type>(1, val);
			_values.push_back(v);
		}
		else if (n > 0)
			_values[n - 1].push_back(val);
	}

	void pop()
	{
		int n = _values.size();
		if (n > 0)
		{
			if (_values[n - 1].size() == 0)
			{
				_values.pop_back();
				n--;
			}

			if (n > 0 && _values[n - 1].size() > 0)
			{
				_values[n - 1].pop_back();
				if (_values[n - 1].size() == 0)
					_values.pop_back();
			}
		}
	}

	// Pop the element at a specific stack
	void popAt(int index)
	{
		int n = _values.size();
		if (index >= 0 && index < n)
		{
			if (_values[index].size() > 0)
				_values[index].pop_back();
		}
	}

	Type top()
	{
		int n = _values.size();
		if (n <= 0)
			return NULL;

		int m = _values[n - 1].size();
		if (m <= 0)
			return NULL;
		else
			return _values[n - 1][m - 1];
	}

	bool empty()
	{
		int n = _values.size();
		return !((n == 0) || (n == 1 && _values[0].size() == 0));
	}
};

void main()
{
	SetOfStacks<int> s = SetOfStacks<int>();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.top() << "\n";
	cout << (s.empty() ? "True" : "False") << "\n";

	s.pop();
	s.pop();
	cout << s.top() << "\n";

	s.popAt(0);
	cout << s.top() << "\n";

	s.pop();
	s.pop();
	cout << (s.empty() ? "True" : "False") << "\n";
	system("pause");
}