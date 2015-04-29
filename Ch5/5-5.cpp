#include<iostream>

using namespace std;

// Find the number of bits required to convert from int a to int b
int findNumberOfBits(int a, int b)
{
	// Assume integer has 32 bits
	int n = 0;
	if ((a >= 0 && b < 0) || ((a < 0 && b >= 0)))
		n++;

	for (int i = 30; i >= 0; i--)
	{
		int m = 1 << i;
		bool a1 = a >= m;
		bool b1 = b >= m;

		if (a1)
			a -= m;

		if (b1)
			b -= m;

		if (a1 ^ b1)
			n++;
	}

	return n;
}

void main()
{
	int n = findNumberOfBits(31, 14);
	cout << n << "\n";
	system("pause");
}
