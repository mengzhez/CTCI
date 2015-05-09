#include<iostream>
#include<stack>

using namespace std;

// Find the kth number such that the only prime factors are 3, 5 and 7
int findNum(int k, int product, int num)
{
	if (k == 0)
		return product;

	int p = product;
	int n = num;
	if (n == 3)
	{
		// Change the last factor to be 5
		p = p / 3 * 5;
		n = 5;
	}
	else if (n == 5)
	{
		// Change the last factor to be 7
		p = p / 5 * 7;
		n = 7;
	}
	else
	{
		// Add the last factor 3
		p *= 3;
		n = 3;
	}

	return findNum(k - 1, p, n);
}

void main()
{
	for (int i = 1; i < 10; i++)
	{
		int p = findNum(i, 1, 1);
		cout << p << "\n";
	}
	system("pause");
}