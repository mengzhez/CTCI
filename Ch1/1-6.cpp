#include<iostream>
#include<cstdint>
#include<vector>
using namespace std;

// Clockwise rotation
void rotateImage(vector<vector<uint32_t>> &image)
{
	int n = image.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i + j < n; j++)
		{
			uint32_t temp = image[i][j];
			image[i][j] = image[n - 1 - j][n - 1 - i];
			image[n - 1 - j][n - 1 - i] = temp;
		}
	}

	for (int i = 0; i <= (n / 2); i++)
	{
		for (int j = 0; j < n; j++)
		{
			uint32_t temp = image[i][j];
			image[i][j] = image[n - 1 - i][j];
			image[n - 1 - i][j] = temp;
		}
	}
}

void main()
{
	vector<vector<uint32_t>> image;
	image.push_back(vector<uint32_t>(4, 0));
	image.push_back(vector<uint32_t>(4, 1));
	image.push_back(vector<uint32_t>(4, 2));
	image.push_back(vector<uint32_t>(4, 3));
	
	rotateImage(image);

	for (int i = 0; i < image.size(); i++)
	{
		for (int j = 0; j < image[0].size(); j++)
			cout << image[i][j] << ", "; 

		cout << "\n";
	}

	system("pause");
}