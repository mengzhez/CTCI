#include<iostream>
#include<bitset>

using namespace std;

// Insert a number into another number on specific bits
int insertBits(int m, int n, int i, int j)
{
	for (int k = i; k <= j; k++)
	{
		int b = (m & (1 << (k - i))) != 0;
		int mask = ~(1 << k);
		n = (n & mask) | (b << k);
	}
	
	return n;
}

void main()
{
	int m = 19; // 10011
	int n = 1024; //10000000000
	int i = 2;
	int j = 6;

	n = insertBits(m, n, i, j); 

	cout << bitset<32>(n) << "\n";
	system("pause");
}