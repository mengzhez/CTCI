#include<iostream>
using namespace std;

// Count the number of possible path for the robot to move from (0, 0) to (x, y)
// Assume we have a 5x5 map. In the map, 1 means possible path, 0 means obstacles
int countPaths(int map[][5], int cx, int cy, int tx, int ty)
{
	if (cx > tx || cy > ty)
		return 0;

	if (map[cx][cy] == 0)
		return 0;
	
	if (cx == tx && cy == ty)
		return 1;

	return countPaths(map, cx + 1, cy, tx, ty) + countPaths(map, cx, cy + 1, tx, ty);
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

	cout << countPaths(map, 0, 0, 3, 1) << endl;
	system("pause");
}