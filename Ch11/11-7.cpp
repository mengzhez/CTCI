#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// Compare the pair according to the first value
bool comparePair(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

// Find the largest possible number of people in the tower
void findPeople(vector<pair<int, int>> data, vector<pair<int, int>> &result)
{
	sort(data.begin(), data.end(), comparePair);

	
}