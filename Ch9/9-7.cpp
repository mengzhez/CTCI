#include<iostream>
using namespace std;

// Fill the area of an image with a given color
// Assume the input arguments are a 10x10 image, a row index i, a column index j and a color represented by a single integer 
void paintFill(int image[][10], int i, int j, int old_color, int new_color)
{
	if (i < 0 || i >= 10 || j < 0 || j >= 10)
		return;

	if (image[i][j] != old_color && old_color != -1)
		return;

	if (old_color == -1)
		old_color = image[i][j];

	if (image[i][j] != new_color)
	{
		image[i][j] = new_color;
		paintFill(image, i + 1, j, old_color, new_color);
		paintFill(image, i - 1, j, old_color, new_color);
		paintFill(image, i, j + 1, old_color, new_color);
		paintFill(image, i, j - 1, old_color, new_color);
	}
}

void main()
{
	int image[][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 2, 1, 1, 2, 1, 1, 1},
		{1, 1, 3, 1, 1, 2, 2, 2, 1, 1},
		{1, 3, 3, 3, 3, 6, 2, 2, 1, 1},
		{1, 1, 3, 3, 6, 6, 6, 2, 1, 1},
		{1, 1, 1, 6, 6, 6, 6, 6, 1, 1},
		{1, 1, 1, 1, 6, 6, 6, 4, 1, 1},
		{1, 1, 1, 1, 1, 6, 4, 4, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	paintFill(image, 5, 5, -1, 8);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << image[i][j] << ", ";
		
		cout << endl;
	}

	system("pause");
}