/*TRANSPARENCY. The cube consists of n3 transparent and opaque cubes. Is there at least one transparent?*/

#include <iostream>
#include<time.h>

#define SIDE 2
#define FILLS 10

using namespace std;

void printDescription();
void fillCube(bool square[SIDE][SIDE][SIDE]);
void fillCubeRandom(bool square[SIDE][SIDE][SIDE]);
void printTransparent();
void printNotTransparent();
void printTotal(int transparent, int notTransparent);
bool isXAxisTransparent(bool square[SIDE][SIDE][SIDE]);
bool isYAxisTransparent(bool square[SIDE][SIDE][SIDE]);
bool isZAxisTransparent(bool square[SIDE][SIDE][SIDE]);

int main()
{
	srand(time(NULL));

	bool square[SIDE][SIDE][SIDE];
	int transparent = 0, notTransparent = 0, counter = 0;
	printDescription();

	while (counter < FILLS)
	{
		fillCubeRandom(square);

		if (isXAxisTransparent(square))
		{
			transparent++;
		}
		else if (isYAxisTransparent(square))
		{
			transparent++;
		}
		else if (isZAxisTransparent(square))
		{
			transparent++;
		}
		else
		{
			notTransparent++;
		}

		counter++;
	}

	printTotal(transparent, notTransparent);	

	return 0;
}

void printDescription()
{
	cout << "This program cheks if a cube is transparent." << endl << endl;
}

void fillCube(bool square[SIDE][SIDE][SIDE])
{
	cout << "Fill the cube with cells: 1 for transparent, 0 for not transparent." << endl;

	for (int z = 0; z < SIDE; z++)
	{
		for (int y = 0; y < SIDE; y++)
		{
			for (int x = 0; x < SIDE; x++)
			{
				cout << "Transparency of the cell z = " << z + 1
					<< " y = " << y + 1
					<< " x = " << x + 1 << ": ";
				cin >> square[z][y][x];
			}
		}
	}
}

void fillCubeRandom(bool square[SIDE][SIDE][SIDE])
{
	for (int z = 0; z < SIDE; z++)
	{
		for (int y = 0; y < SIDE; y++)
		{
			for (int x = 0; x < SIDE; x++)
			{
				square[z][y][x] = rand() % 2;
			}
		}
	}
}

void printTotal(int transparent, int notTransparent)
{
	cout << "**************************" << endl;
	cout << "Total transparent: " << transparent << endl;
	cout << "Total not transparent: " << notTransparent << endl;
	cout << "**************************" << endl;
}

bool isXAxisTransparent(bool square[SIDE][SIDE][SIDE])
{
	bool flag = true;

	for (int z = 0; z < SIDE; z++)
	{
		for (int y = 0; y < SIDE; y++)
		{
			for (int x = 0; x < SIDE; x++)
			{
				flag *= square[z][y][x];
			}

			if (flag)
			{
				return flag;
			}
		}
	}

	return flag;
}

void printTransparent()
{
	cout << "*************************************" << endl;
	cout << "Cube has at least 1 transparent part." << endl;
	cout << "*************************************" << endl;
}

void printNotTransparent()
{
	cout << "**********************************" << endl;
	cout << "Cube has not any transparent part." << endl;
	cout << "**********************************" << endl;
}

bool isYAxisTransparent(bool square[SIDE][SIDE][SIDE])
{
	bool flag = true;

	for (int z = 0; z < SIDE; z++)
	{
		for (int x = 0; x < SIDE; x++)
		{
			for (int y = 0; y < SIDE; y++)
			{
				flag *= square[z][y][x];
			}

			if (flag)
			{
				return flag;
			}
		}
	}

	return flag;
}

bool isZAxisTransparent(bool square[SIDE][SIDE][SIDE])
{
	bool flag = true;

	for (int y = 0; y < SIDE; y++)
	{
		for (int x = 0; x < SIDE; x++)
		{
			for (int z = 0; z < SIDE; z++)
			{
				flag *= square[z][y][x];
			}

			if (flag)
			{
				return flag;
			}
		}
	}

	return flag;
}