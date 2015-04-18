#include<iostream>
#include<unordered_set>
using namespace std;

bool uniqueCharacters(string s)
{
	int length = s.size();
	unordered_set<char> set;
	for(int i = 0; i < length; i++)
	{
		if (set.count(s[i]) > 0)
			return false;
		else
			set.insert(s[i]);
	}

	return true;
}

void main()
{
	bool b = UniqueCharacters("abcdefghijklmnopqrstuvwxyz!");
	cout << (b ? "true" : "false") << "\n";
	system("pause");
}