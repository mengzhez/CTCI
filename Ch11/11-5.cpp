#include<iostream>
#include<string>
using namespace std;

// Find the specific string in a sorted array with empty strings
// The algorithm may be not efficient enough
int findString(string strs[], int n, string target)
{
	int low = 0;
	int high = n - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (strs[mid] == target)
			return mid;
		else if (strs[mid] == "")
		{
			if (strs[low] != target)
				low++;
			else
				return low;
		}
		else if (strs[mid].compare(target) > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

void main()
{
	string strs[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "", "", "", ""};
	int index = findString(strs, sizeof(strs) / sizeof(string), "ball");
	cout << index << endl;
	system("pause");
}