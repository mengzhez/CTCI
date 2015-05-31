#include<iostream>
#include<vector>
using namespace std;

// Track the number in an integer stream
class Tracker
{
private:
	int _value;
	int _rank;

public:
	Tracker(int n)
	{
		_value = n;
		_rank = -1;
	}

	int getValue()
	{
		return _value;
	}

	int getRankOfNumber()
	{
		return _rank;
	}

	void setRankOfNumber(int r)
	{
		_rank = r;
	}
};

void GenerateNumber(vector<int> &s, Tracker &t)
{
	int n = rand() % 100 + 1;

	// Track x
	if (n <= t.getValue())
		t.setRankOfNumber(t.getRankOfNumber() + 1);

	s.push_back(n);

}

void main()
{
	vector<int> s;
	Tracker t(5);
	for (int i = 0; i < 100; i++)
		GenerateNumber(s, t);

	cout << t.getRankOfNumber() << endl;
	system("pause");
}