#include<iostream>
#include<string>
using namespace std;

// Count the number of ways of parenthesizing the expression
// Maybe this algorithm is too complicated
int parenthesizeExpression(string str, int n)
{
	int len = str.size();
	if (len == 0)
		return 0;
	else if (len == 1)
		return (str[0] - '0' == n) ? 1 : 0;
	else if (len == 3)
	{
		int n1 = str[0] - '0';
		int n2 = str[len - 1] - '0';
		if ((str[1] == '|' && n1 | n2 == n) || (str[1] == '&' && n1 & n2 == n) || (str[1] == '^' && n1 ^ n2 == n))
			return 1;
		else
			return 0;
	}

	// Check invalid values
	if ((str[0] != '0' && str[0] != '1') || (str[len-1] != '0' && str[len-1] != '1'))
		return 0;

	int count = 0;
	string sub1 = str.substr(2, len - 2);
	string sub2 = str.substr(0, len - 2);
	
	// Recursively check the substring without the first two characters
	if (str[1] == '|')
		count = count + ((str[0] == '0') ? parenthesizeExpression(sub1, n) : ((n == 1) ? parenthesizeExpression(sub1, 1) + parenthesizeExpression(sub1, 0) : 0));
	else if (str[1] == '&')
		count = count + ((str[0] == '1') ? parenthesizeExpression(sub1, n) : ((n == 0) ? parenthesizeExpression(sub1, 1) + parenthesizeExpression(sub1, 0) : 0));
	else if (str[1] == '^')
		count = count + ((str[0] == '0') ? parenthesizeExpression(sub1, n) : parenthesizeExpression(sub1, abs(~n)));

	// Recursively check the substring without the last two characters
	if (str[len - 2] == '|')
		count = count + ((str[len - 1] == '0') ? parenthesizeExpression(sub2, n) : ((n == 1) ? parenthesizeExpression(sub2, 1) + parenthesizeExpression(sub2, 0) : 0));
	else if (str[len - 2] == '&')
		count = count + ((str[len - 1] == '1') ? parenthesizeExpression(sub2, n) : ((n == 0) ? parenthesizeExpression(sub2, 1) + parenthesizeExpression(sub2, 0) : 0));
	else if (str[len - 2] == '^')
		count = count + ((str[len - 1] == '0') ? parenthesizeExpression(sub2, n) : parenthesizeExpression(sub2, ~n));

	return count;
}

void main()
{
	int count = parenthesizeExpression("1^0|0|1", 0);
	cout << count << endl;
	system("pause");
}