#include<iostream>
using namespace std;

// Count the number of ways for the child to run up a staircase with n steps
// The child can hop either one, two or three steps
// This implementation could be improved by using dynamic programming (we can avoid computing the same n for multiple times)
int countWays(int n)
{
	if (n < 0)
		return 0;
	else if (n == 0 || n == 1)
		return 1;
	else
		return (countWays(n - 1) + countWays(n - 2) + countWays(n - 3));
}

void main()
{
	cout << countWays(4) << endl;
	system("pause");
}