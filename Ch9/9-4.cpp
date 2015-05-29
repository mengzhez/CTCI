#include<iostream>
#include<vector>
using namespace std;

// Find all the subsets of a given set
void findSubset(vector<int> a, vector<vector<int>> &sub)
{
	if (a.size() == 0)
	{
		vector<int> empty;
		sub.push_back(empty);
		return;
	}

	vector<int> temp_a = a;
	int num = temp_a[0];
	
	temp_a.erase(temp_a.begin());
	findSubset(temp_a, sub);

	vector<vector<int>> temp_sub = sub;
	for (int i = 0; i < temp_sub.size(); i++)
	{
		temp_sub[i].push_back(num);
		sub.push_back(temp_sub[i]);
	}
}

void main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(2);
	a.push_back(4);

	vector<vector<int>> sub;
	findSubset(a, sub);

	for (int i = 0; i < sub.size(); i++)
	{
		for (int j = 0; j < sub[i].size(); j++)
			cout << sub[i][j] << ", ";

		cout << endl;
	}
	system("pause");
}
