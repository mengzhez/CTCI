#include<iostream>
#include<bitset>

using namespace std;

void main()
{
	// ((n & (n - 1)) == 0)
	// (n - 1) will make the least significant 1 to 0 and the 0s after it to 1s
	// This is used to check if n has only one '1' in the binary representation
	// or if n is a power of 2

	int n = 8; // 00001000
	bool b = ((n & (n - 1)) == 0);
	cout << (b ? "True" : "False") << "\n";

	n = 40; // 00101000
	b = ((n & (n - 1)) == 0);
	cout << (b ? "True" : "False") << "\n";

	system("pause");
}