#include<iostream>
#include<unordered_set>
using namespace std;

// Check if all the characters are unique
// Didn't check whether the character is ASCII or Unicode
bool uniqueCharacters(string str)
{
	// Use unordered_set to store characters, if one character appears twice, return false
	int n = str.size();
	unordered_set<char> set;
	for(int i = 0; i < n; i++)
	{
		if (set.count(str[i]) > 0)
			return false;
		else
			set.insert(str[i]);
	}

	return true;
}

void main()
{
	bool b = uniqueCharacters("abcdefghijklmnopqrstuvwxyz!");
	cout << (b ? "True" : "False") << "\n";
	system("pause");
}