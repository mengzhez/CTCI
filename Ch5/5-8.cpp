#include<iostream>
#include<bitset>

using namespace std;

typedef bitset<8> byte;

// Draw a horizontal line in a screen stored by a single array of bytes
// Assume x is counted based on the left line, y is counted based on the top line
// x1, x2 and y are 0-based
void drawHorizontalLine(byte scr[], int w, int x1, int x2, int y)
{
	int p1 = y * w + x1;
	int p2 = y * w + x2;
	
	int byte1 = p1 / 8;
	int byte2 = p2 / 8;

	int bit1 = p1 % 8;
	int bit2 = p2 % 8;

	for (int i = byte1; i <= byte2; i++)
	{
		if (byte1 == byte2)
		{
			int mask = (~((1 << bit1) - 1));
			mask &= ((1 << (bit2 + 1)) - 1);
			scr[i] |= mask;
			break;
		}

		if (i == byte1)
			scr[i] |= (~((1 << bit1) - 1)); // Set 'bit 1' to 'bit 8' to 1
		else if (i == byte2)
			scr[i] |= ((1 << (bit2 + 1)) - 1); // Set 'bit 0' to 'bit 2' to 1
		else
			scr[i] = 255; // Set all the bits to 1
	}
}

void main()
{
	byte scr[] = {0, 0, 0, 0, 0, 0};
	int width = 16;
	int x1 = 3, x2 = 11, y = 1;
	drawHorizontalLine(scr, width, x1, x2, y);

	for (int i = 0; i < (sizeof(scr) / sizeof(byte)); i++)
	{
		if (i != 0 && i % (width / 8) == 0)
			cout << "\n";

		// Print order should be reversed
		cout << scr[i] << ", ";
	}

	cout << "\n";

	system("pause");
}