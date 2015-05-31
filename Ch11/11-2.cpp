#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

// Swap the specific strings in an array
void swapStrings(vector<string> &strs, int m, int n)
{
	string str_temp = strs[m];
	strs[m] = strs[n];
	strs[n] = str_temp;
}

// Sort an array of strings such that all the anagrams are next to each other
void sortStrings(vector<string> &strs)
{
	int len = strs.size();
	unordered_map<string, int> map; // Map the ordered string to its index
	for (int i = 0; i < len; i++)
	{
		string str_temp = strs[i];
		sort(str_temp.begin(), str_temp.end());

		while (map.count(str_temp) > 0)
		{
			int index_next =  map[str_temp] + 1;
			string str_next = strs[index_next];
			swapStrings(strs, i, index_next);
			map[str_temp] = index_next;

			str_temp = str_next;
			sort(str_temp.begin(), str_temp.end());
			if (index_next == map[str_temp])
				break;
		}

		map[str_temp] = i;
	}

}

void main()
{
	vector<string> strs;
	strs.push_back("abc");
	strs.push_back("def");
	strs.push_back("bca");
	strs.push_back("cba");
	strs.push_back("fed");
	strs.push_back("ghi");
	strs.push_back("jkl");
	strs.push_back("efd");
	strs.push_back("hig");
	strs.push_back("mno");

	sortStrings(strs);
	for (int i = 0; i < strs.size(); i++)
		cout << strs[i] << endl;

	system("pause");
}