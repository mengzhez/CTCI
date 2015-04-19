#include<iostream>
#include<string>
using namespace std;

void replaceSpaces(string &str)
{
	int n = str.size();
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
	string str = "Mr  John Smith      ";
	replaceSpaces(str);
	cout << str << "\n";
	system("pause");
}