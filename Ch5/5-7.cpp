#include<iostream>

using namespace std;

// Fetch the jth bit of the ith integer in array a
int fetchBit(int a[], int i, int j)
{
	return (a[i] & (1 << j)) != 0;
}

// Fetch the jth bit of the integer n
int fetchBit(int n, int j)
{
	return (n & (1 << j)) != 0;
}

// Find the missing number in a[]
// If we assume the length of n is log2(n), then this implementation is O(n log(n))
// We could do better by counting the numbers of 0s and 1s for each bit
int findMissingNumber(int a[], int n)
{
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		// Assume integer has 32 bits
		for (int j = 0; j < 31; j++)
		{
			int b = fetchBit(x, j);
			b ^= fetchBit(a, i, j);
			b ^= fetchBit(i, j);
			x &= (~(1 << j));
			x |= (b << j);
		}
	}

	for (int j = 0; j < 31; j++)
	{
		int b = fetchBit(x, j);
		b ^= fetchBit(n, j);
		x &= (~(1 << j));
		x |= (b << j);
	}

	return x;
}

void main()
{
	int n = 10;
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10};
	int m = findMissingNumber(a, n);
	cout << m << "\n";
	
	system("pause");
}