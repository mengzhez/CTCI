#include<iostream>
#include<stack>
using namespace std;

// Implement a stack with min function
// Could do better by not storing additional data in _mins
template <class Type> class MyStack
{
private:
	stack<Type> _values;
	stack<Type> _mins;

public:
	MyStack()
	{}

	~MyStack()
	{}

	void push(Type val)
	{
		_values.push(val);

		if (_mins.empty())
			_mins.push(val);
		else
			_mins.push(std::min(_mins.top(), val));
	}

	void pop()
	{
		_values.pop();
		_mins.pop();
	}

	int top()
	{
		return _values.top();
	}

	int min()
	{
		return _mins.top();
	}

	bool empty()
	{
		return _values.empty();
	}
};

void main()
{
	MyStack<int> s;
	s.push(3);
	s.push(5);
	s.push(2);
	s.push(8);

	while (!s.empty())
	{
		cout << s.min() << ", ";
		s.pop();
	}
	cout << "\n";
	system("pause");
}
