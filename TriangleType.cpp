#include <iostream>
#include <cmath>

using namespace std;

void sideInput(int* side);
void makeSide1Longest(int* side1, int* side2, int* side3);
bool isTriangleNotExist(int side1, int side2, int side3);
bool isTriangleEquilateral(int side1, int side2, int side3);
bool isTriangleRight(int side1, int side2, int side3);
bool isTriangleAcuteAngled(int side1, int side2, int side3);
bool isTriangleIsosceles(int side1, int side2, int side3);
void triangleTypeDefinition(int side1, int side2, int side3);
void swapSidesIfRequired(int* side1, int* side2);

int main()
{
	int side1 = 0, side2 = 0, side3 = 0;

	cout << "This programm will define triangle type after entering all 3 sides." << endl << endl;

	sideInput(&side1);
	sideInput(&side2);
	sideInput(&side3);

	makeSide1Longest(&side1, &side2, &side3);

	if (isTriangleNotExist(side1, side2, side3))
	{
		cout << "Triangle does not exist" << endl;
		cout << endl;
		system("pause");
		return -1;
	}
	else {}

	triangleTypeDefinition(side1, side2, side3);

	cout << endl;
	system("pause");
	return 0;
}

void sideInput(int* side)
{
	cout << "Enter the side length: ";
	cin >> *side;
}

void makeSide1Longest(int* side1, int* side2, int* side3)
{
	swapSidesIfRequired(side1, side2);
	swapSidesIfRequired(side1, side3);
}

void swapSidesIfRequired(int* side1, int* side2)
{
	int temp;

	if (*side1 < *side2)
	{
		temp = *side1;
		*side1 = *side2;
		*side2 = temp;
	}
}

bool isTriangleNotExist(int side1, int side2, int side3)
{
	return side1 > (side2 + side3);
}

bool isTriangleEquilateral(int side1, int side2, int side3)
{
	return side1 == side2 and side2 == side3;
}

bool isTriangleRight(int side1, int side2, int side3)
{
	return pow(side1, 2) == (pow(side2, 2) + pow(side3, 2));
}

bool isTriangleAcuteAngled(int side1, int side2, int side3)
{
	return pow(side1, 2) < (pow(side2, 2) + pow(side3, 2));
}

bool isTriangleIsosceles(int side1, int side2, int side3)
{
	return side1 == side2 or side2 == side3 or side1 == side3;
}

void triangleTypeDefinition(int side1, int side2, int side3)
{
	if (isTriangleEquilateral(side1, side2, side3))
	{
		cout << endl << "The triangle is equilateral." << endl;
	}
	else
	{
		if (isTriangleRight(side1, side2, side3))
		{
			cout << "Triangle is right";
		}
		else if (isTriangleAcuteAngled(side1, side2, side3))
		{
			cout << "Triangle is acute-angled";
		}
		else
		{
			cout << "Triangle is obtuse-angled";
		}

		if (isTriangleIsosceles(side1, side2, side3))
		{
			cout << ", isosceles.";
		}
		else { cout << "."; }
	}
}