#include<iostream>
#include<bitset>

using namespace std;

void main()
{
	// ((n & (n - 1)) == 0)
	// (n - 1) is to make the lowest 1 of n become 0
	// This is used to check if n has only one '1' in the binary representation

	int n = 8; // 00001000
	bool b = ((n & (n - 1)) == 0);
	cout << (b ? "True" : "False") << "\n";

	n = 40; // 00101000
	b = ((n & (n - 1)) == 0);
	cout << (b ? "True" : "False") << "\n";

	system("pause");
}