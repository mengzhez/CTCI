#include<iostream>
using namespace std;

// Count the number of ways of representing n cents
// Argument last is the amount of cents deducted in the last recursion
int representNCents(int n, int last)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	if (last >= 25)
		num1 = representNCents(n - 25, 25);

	if (last >= 10)
		num2 = representNCents(n - 10, 10);

	if (last >= 5)
		num3 = representNCents(n - 5, 5);
	
	if (last >= 1)
		num4 = representNCents(n - 1, 1);

	return num1 + num2 + num3 + num4;
}

void main()
{
	int count = representNCents(15, 25);
	cout << count << endl;
	system("pause");
}