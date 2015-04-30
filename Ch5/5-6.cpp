#include<iostream>
#include<bitset>

using namespace std;

// Swap the adjacent bits
int swapBits(int n)
{
	// Assume that the integer has 32 bits and the highest bit is the sign
	int m = n;
	for (int i = 0; i < 30; i = i + 2)
	{
		int b0 = (n & (1 << i)) != 0;
		int b1 = (n & (1 << (i + 1))) != 0;

		if (b0 != b1)
		{
			m &= (~(1 << i));
			m &= (~(1 << (i + 1)));
			m |= (b1 << i);
			m |= (b0 << (i + 1));
		}
	}

	return m;
}

void main()
{
	int n = 4368789;
	cout << bitset<32>(n) << "\n";

	int m = swapBits(n);
	cout << bitset<32>(m) << "\n";

	system("pause");
}