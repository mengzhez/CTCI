#include<iostream>
#include<vector>
using namespace std;

// Set the entire row and column to zero of which the element is zero
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
				// Find the first row where the zero lies, use it to store the colunm indices of all zeros
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

		// Set all the target rows to zero, except the first target row
		if (b)
		{
			for (int j = 0; j < n; j++)
				matrix[i][j] = 0;

			b = false;
		}
	}

	// Set the target columns to zero according to the information in the first target row
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