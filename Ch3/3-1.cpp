#include<iostream>
#include<vector>
using namespace std;

// Implement three stacks using a single array
// Implemented using a 2D array
template <class Type> class MyStack
{
private:
	vector<vector<Type>> _values;

public:
	MyStack()
	{
		_values = vector<vector<Type>>(3, vector<Type>());
	}

	~MyStack()
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
	MyStack<int> s = MyStack<int>();
	s.push(6, 0);
	s.push(8, 0);
	s.push(11, 1);
	s.push(22, 2);
	cout << s.top(0) << "; " << s.top(1) << "; " << s.top(2) << "\n";

	s.pop(2);
	cout << (s.empty(0) ? "True" : "False") << "; " << (s.empty(1) ? "True" : "False") << "; " << (s.empty(2) ? "True" : "False") << "\n";
	
	system("pause");
}