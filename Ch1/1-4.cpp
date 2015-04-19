#include<iostream>
using namespace std;

void replaceSpaces(char* str, int n)
{
	if (n <= 2)
		return;

	for (int i = 0; i < (n - 1); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = n - 3; j >= i + 1; j--)
				str[j + 2] = str[j];

			str[i] = '%';
			str[++i] = '2';
			str[++i] = '0';
		}
	}
}

void main()
{
	char str[] = "Mr  John Smith      ";
	replaceSpaces(str, (sizeof(str) / sizeof(char) - 1));
	cout << str << "\n";
	system("pause");
}