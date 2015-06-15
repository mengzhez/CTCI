#include<iostream>
using namespace std;

// Count the number of possible path for the robot to move from (0, 0) to (x, y)
// Assume we have a 5x5 map. In the map, 1 means possible path, 0 means obstacles
int countPaths(int map[][5], int flag[][5], int cx, int cy, int tx, int ty)
{
	if (cx > tx || cy > ty)
		return 0;

	if (map[cx][cy] == 0)
		return 0;
	
	if (cx == tx && cy == ty)
		return 1;

	int count1 = (flag[cx + 1][cy] != 0) ? flag[cx + 1][cy] : countPaths(map, flag, cx + 1, cy, tx, ty);
	flag[cx + 1][cy] = count1;
	int count2 = (flag[cx][cy + 1] != 0) ? flag[cx][cy + 1] : countPaths(map, flag, cx, cy + 1, tx, ty);
	flag[cx][cy + 1] = count2;

	return count1 + count2;
}

void main()
{
	int map[5][5] = {
		{ 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 }
	};

	int flag[5][5] = {0};

	cout << countPaths(map, flag, 0, 0, 3, 1) << endl;
	system("pause");
}