#include<iostream>
using namespace std;

void reverse(char* str)
{
	int n = 0;
	char* p = str;
	while (*p)
	{
		n++;
		p++;
	}

	for (int i = 0; i < (n / 2); i++)
	{
		char temp = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = temp;
	}
}

void main()
{
	char str[] = "abcdefghijk";
	reverse(str);
	cout << str << "\n";
	system("pause");
}