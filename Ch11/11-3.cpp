#include<iostream>
using namespace std;

// Find the specific element in a rotated sorted array
int findElement(int a[], int n, int target)
{
	int low = 0;
	int high = n - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (a[mid] == target)
			return mid;
		else if (a[mid] > target)
		{
			if (target > a[0] || a[mid] < a[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		else
		{
			if (a[mid] > a[0] || target < a[0])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}

	return -1;
}

void main()
{
	int a[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	int index = findElement(a, sizeof(a) / sizeof(int), 5);
	cout << index << endl;
	system("pause");
}