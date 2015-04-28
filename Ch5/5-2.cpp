#include<iostream>

using namespace std;

// Print the binary representation of a double number between 0 ~ 1
void printBinaryRep(double n)
{
	char c[32] = {'0'};
	c[0] = '0';
	c[1] = ',';

	int exp = -1;
	for (int i = 2; i < 32; i++)
	{
		c[i] = '0';
		double m = pow(2, exp);
		if (n >= m)
		{
			c[i] = '1';
			n -= m;

			if (n == 0)
				break;
		}

		exp--;
	}

	if (n == 0)
		cout << c << "\n";
	else
		cout << "ERROR" << "\n";
}

void main()
{
	printBinaryRep(0.75);
	printBinaryRep(0.72);

	system("pause");
}