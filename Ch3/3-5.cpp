#include<iostream>
#include<stack>

using namespace std;

// Implement a queue using two stacks
// Could do better by implementing a lazy approach where the elements stay in one stack until they must be moved
template <class Type> class MyQueue
{
private:
	stack<Type> _s1;
	stack<Type> _s2;

public:
	MyQueue()
	{}

	~MyQueue()
	{}

	void push(Type n)
	{
		while (!_s1.empty())
		{
			_s2.push(_s1.top());
			_s1.pop();
		}

		_s2.push(n);
		while (!_s2.empty())
		{
			_s1.push(_s2.top());
			_s2.pop();
		}
	}

	void pop()
	{
		if (!_s1.empty())
			_s1.pop();
	}

	Type front()
	{
		return _s1.top();
	}

	bool empty()
	{
		return _s1.empty();
	}
};

void main()
{
	MyQueue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.front() << "\n";
	q.pop();

	cout << q.front() << "\n";
	q.pop();
	q.pop();

	cout << (q.empty() ? "True" : "False") << "\n";
	system("pause");
}