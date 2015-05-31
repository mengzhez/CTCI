#include<iostream>
using namespace std;

// Find the specific element in a matrix
// Assume the matrix is 10x10
void findElement(int a[][10], int &row_index, int &col_index, int target)
{
	int row_low = 0;
	int row_high = 9;
	int col_low = 0;
	int col_high = 9;
	while (row_low <= row_high || col_low <= col_high)
	{
		if (row_low <= row_high)
		{
			int mid = (row_low + row_high) / 2;

			if (a[mid][col_high] < target)
				row_low = mid + 1;
			else if (a[mid][col_low] > target)
				row_high = mid - 1;
			else
			{
				for (int j = col_low; j <= col_high ; j++)
				{
					if (a[row_low][j] == target)
					{
						row_index = row_low;
						col_index = j;
						return;
					}
				}

				row_low++;
			}
		}

		if (col_low <= col_high)
		{
			int mid = (col_low + col_high) / 2;
			
			if (a[row_high][mid] < target)
				col_low = mid + 1;
			else if (a[row_low][mid] > target)
				col_high = mid - 1;
			else
			{
				for (int i = row_low; i <= row_high ; i++)
				{
					if (a[i][col_low] == target)
					{
						row_index = i;
						col_index = col_low;
						return;
					}
				}

				col_low++;
			}
		}
	}
}

void main()
{
	int a[][10] = {
		{ 1, 11, 21, 31, 41, 51, 61, 71, 81, 91},
		{ 2, 12, 21, 32, 42, 52, 62, 72, 82, 92},
		{ 3, 13, 23, 33, 43, 53, 63, 73, 83, 93},
		{ 4, 14, 24, 34, 44, 54, 64, 74, 84, 94},
		{ 5, 15, 25, 35, 45, 55, 65, 75, 85, 95},
		{ 6, 16, 26, 36, 46, 56, 66, 76, 86, 96},
		{ 7, 17, 27, 37, 47, 57, 67, 77, 87, 97},
		{ 8, 18, 28, 38, 48, 58, 68, 78, 88, 98},
		{ 9, 19, 29, 39, 49, 59, 69, 79, 89, 99},
		{10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
	};

	int row_index = 0;
	int col_index = 0;
	findElement(a, row_index, col_index, 55);

	cout << row_index << ", " << col_index << endl;
	system("pause");
}