#include<iostream>
#include<string>
using namespace std;

// Check if one string is the substring of the other
bool isSubstring(string str, string sub)
{
	if (str.size() < sub.size())
		return false;

	if (str.find(sub) != string::npos)
		return true;
	else
		return false;
}

// Check if one string is a rotation of the other
bool isRotation(string str1, string str2)
{
	if (str1.size() != str2.size())
		return false;

	// Concatenate two strings and check the substring
	string temp = str2 +str2;
	return isSubstring(temp, str1);
}

void main()
{
	string str1 = "waterbottle";
	string str2 = "erbottlewat";
	bool b = isRotation(str1, str2);
	cout << (b ? "True" : "False") << "\n";
	system("pause");
}