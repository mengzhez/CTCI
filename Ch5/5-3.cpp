#include<iostream>
#include<iomanip>
#include<bitset>

using namespace std;

void printNextSmallest(int n)
{
	// Assume that a integer has 32 bits and the highest bit is for the sign
	int b0 = 31;
	int b1 = 31;
	int temp = 31;
	int m = n;
	for (int i = 30; i >= 0; i--)
	{
		if (m >= (1 << i))
		{
			m -= (1 << i);
			b0 = i;
			
			if (temp > b0)
				b1 = temp;
		}
		else
			temp = i;
	}

	int mask = ~(1 << b0);
	n = n & mask;

	mask = (1 << b1);
	n = n | mask;

	cout << setw(10) << "Smallest: " << bitset<32>(n) << "\n";
}

void printNextLargest(int n)
{
	// Assume that a integer has 32 bits and the highest bit is for the sign
	int b0 = 31;
	int b1 = 31;
	int m = n;
	for (int i = 30; i >= 0; i--)
	{
		if (m >= (1 << i))
		{
			m -= (1 << i);
			b0 = i;
		}
		else
			b1 = (b1 == 31) ? i : b1;
	}

	int mask = ~(1 << b0);
	n = n & mask;

	mask = (1 << b1);
	n = n | mask;

	cout << setw(10) << "Largest: " << bitset<32>(n) << "\n";
}

void main()
{
	int n = 159;
	cout << setw(10) << "Original: " << bitset<32>(n) << "\n";
	printNextSmallest(n);
	printNextLargest(n);

	system("pause");
}
