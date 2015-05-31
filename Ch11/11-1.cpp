#include<iostream>
using namespace std;

// Merge two sorted arrays into the first array
// Assume that the first array has enough space to handle the second array
// In the arguments, m and n are the number of valid elements in the two arrays, respectively
void mergeArrays(int a[], int b[], int m, int n)
{
	int i = m + n - 1;
	int index1 = m - 1;
	int index2 = n - 1;

	while (i >= 0 && index1 >= 0 && index2 >= 0)
	{
		if (a[index1] > b[index2])
		{
			a[i] = a[index1];
			index1--;
		}
		else
		{
			a[i] = b[index2];
			index2--;
		}

		i--;
	}

	while (index1 >= 0)
	{
		a[i] = a[index1];
		index1--;
		i--;
	}

	while (index2 >= 0)
	{
		a[i] = b[index2];
		index2--;
		i--;
	}
}

void main()
{
	int a[10] = {1, 2, 6, 9, 15, 0, 0, 0, 0, 0};
	int b[5] = {0, 2, 3, 8, 18};

	mergeArrays(a, b, sizeof(a) / sizeof(int) - sizeof(b) / sizeof(int), sizeof(b) / sizeof(int));
	for (int i = 0; i < 10; i++)
		cout << a[i] << ", ";

	cout << endl;
	system("pause");
}