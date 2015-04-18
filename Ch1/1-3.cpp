#include<iostream>
#include<unordered_set>
using namespace std;

bool isPermutation(string s1, string s2)
{
	int length1 = s1.size();
	int length2 = s2.size();

	if (length1 != length2)
		return false;

	unordered_set<char> set;
	for (int i = 0; i < length1; i++)
		set.insert(s1[i]);

	for (int i = 0; i < length2; i++)
	{
		if (set.count(s2[i]) == 0)
			return false;

		set.erase(s2[i]);
	}

	if (set.size() == 0)
		return true;
	else
		return false;
}

void main()
{
	string s1 = "abcdefa";
	string s2 = "cfgabde";
	bool b = isPermutation(s1, s2);
	cout << (b ? "true" : "false") << "\n";
	system("pause");
}