#include<iostream>
#include<string>
using namespace std;

// Compress the string
// Could be improved by using StringBuffer
string compressString(string str)
{
	int n = str.size();
	if (n <= 2)
		return str;

	string cstr;
	int c = 1;
	for (int i = 1; i < n; i++)
	{
		if (str[i] == str[i - 1])
			c++;
		else
		{
			cstr += str[i - 1];
			cstr += ('0' + c);
			c = 1;
		}
	}

	cstr += str[n - 1];
	cstr += ('0' + c);
	if (cstr.size() < n)
		return cstr;
	else
		return str;
}

void main()
{
	string str = "aaa444dbbbttttttttt";
	string cstr = compressString(str);
	cout << cstr << "\n";
	system("pause");
}