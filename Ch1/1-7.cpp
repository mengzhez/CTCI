#include<iostream>
#include<vector>
using namespace std;

void setZero(vector<vector<int>> &matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int row = -1;
	for (int i = 0; i < m; i++)
	{
		bool b = false;
		for (int j = 0; j < n; j++)
		{
			if (!matrix[i][j])
			{
				if (row == -1)
				{
					row = i;
					break;
				}
				else
					matrix[row][j] = 0;

				b = true;
			}
		}

		if (b)
		{
			for (int j = 0; j < n; j++)
				matrix[i][j] = 0;

			b = false;
		}
	}

	for (int j = 0; j < n; j++)
	{
		if (!matrix[row][j])
		{
			for (int i = 0; i < m; i++)
				matrix[i][j] = 0;
		}

		matrix[row][j] = 0;
	}
}

void main()
{
	vector<vector<int>> matrix(4, vector<int>(4, 1));
	matrix[0][0] = 0;
	matrix[0][2] = 0;
	matrix[2][2] = 0;

	setZero(matrix);

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << ", "; 

		cout << "\n";
	}

	system("pause");
}