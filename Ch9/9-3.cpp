#include<iostream>
#include<vector>
using namespace std;

// Find the magic index which satisfies a[i] = i
// Assume that if the magic index exists, only one exists in the input array. If it doesn't exist, return -1
// Current algorithm is not efficient enough
int findMagicIndex(vector<int> a, int low, int high)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;
	if (a[mid] == mid)
		return mid;

	if (a[mid] > mid)
	{
		int left = findMagicIndex(a, low, mid - 1);
		if (left >= 0)
			return left;

		int right = findMagicIndex(a, max(a[mid], mid), high);
		if (right >= 0)
			return right;
	}
	else
	{
		int left = findMagicIndex(a, low, min(a[mid], mid));
		if (left >= 0)
			return left;

		int right = findMagicIndex(a, mid + 1, high);
		if (right >= 0)
			return right;
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

	int index = findMagicIndex(a, 0, a.size() - 1);
	cout << index << endl;
	system("pause");
}