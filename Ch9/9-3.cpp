#include<iostream>
#include<vector>
using namespace std;

// Find the magic index which satisfies a[i] = i
// Assume that if the magic index exists, only one exists in the input array. If it doesn't exist, return -1
// Current algorithm is not efficient enough
int findMagicIndex(vector<int> a)
{
	int index = 0;
	while (index < a.size())
	{
		if (a[index] == index)
			return index;

		if ((a[index] - index) > 0)
			index = a[index];
		else
			index++;
	}

	return -1;
}

void main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(5);
	a.push_back(6);
	a.push_back(12);
	a.push_back(12);
	a.push_back(12);

	int index = findMagicIndex(a);
	cout << index << endl;
	system("pause");
}