#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Find all permutations of a given string
vector<string> findPermutation(string str)
{
	vector<string> perm_temp;
	vector<string> perm;
	if (str.size() <= 1)
	{
		perm.push_back(str);
		return perm;
	}

	char c = str[0];
	string str_temp = str.substr(1, str.size());
	perm_temp = findPermutation(str_temp);

	for (int i = 0; i < perm_temp.size(); i++)
	{
		for (int j = 0; j < perm_temp[i].size() + 1; j++)
		{
			str_temp = perm_temp[i];
			str_temp.insert(str_temp.begin() + j, c);
			perm.push_back(str_temp);
		}
	}

	return perm;
}

void main()
{
	string str = "abcd";
	vector<string> perm = findPermutation(str);
	for (int i = 0; i < perm.size(); i++)
		cout << perm[i] << endl;

	system("pause");
}