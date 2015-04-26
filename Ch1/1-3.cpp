#include<iostream>
#include<unordered_set>
using namespace std;

// Check if one string is the permutation of the other
bool isPermutation(string str1, string str2)
{
	int n1 = str1.size();
	int n2 = str2.size();

	if (n1 != n2)
		return false;

	// Use Hash-table to store all characters
	unordered_set<char> set;
	for (int i = 0; i < n1; i++)
		set.insert(str1[i]);

	// Check if all the characters in the others string appear in the table
	for (int i = 0; i < n2; i++)
	{
		if (set.count(str2[i]) == 0)
			return false;

		set.erase(str2[i]);
	}

	if (set.size() == 0)
		return true;
	else
		return false;
}

void main()
{
	string str1 = "abcdefa";
	string str2 = "cfgabde";
	bool b = isPermutation(str1, str2);
	cout << (b ? "True" : "False") << "\n";
	system("pause");
}