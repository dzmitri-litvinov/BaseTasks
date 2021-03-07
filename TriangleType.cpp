#include <iostream>
#include <cmath>

using namespace std;

void sideInput(int* side);
void triangleInput(int *side1, int *side2, int *side3);
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

	triangleInput(&side1, &side2, &side3);

	makeSide1Longest(&side1, &side2, &side3);

	if (isTriangleNotExist(side1, side2, side3))
	{
		cout << "Triangle does not exist" << endl;
		cout << endl;
		system("pause");
		return -1;
	}	else {}
	
	triangleTypeDefinition(side1, side2, side3);	

	cout << endl;
	system("pause");
	return 0;
}

void sideInput(int* side)
{
	cin >> *side;
}

void triangleInput(int *side1, int *side2, int *side3)
{
	cout << "Enter the 1st side length: ";
	sideInput(side1);
	cout << "Enter the 2nd side length: ";
	sideInput(side2);
	cout << "Enter the 3rd side length: ";
	sideInput(side3);
}

void makeSide1Longest(int* side1, int* side2, int* side3)
{
	swapSidesIfRequired(side1, side2);
	swapSidesIfRequired(side1, side3);
}

void swapSidesIfRequired(int *side1, int *side2)
{
	int temp;

	if ((*side1) < (*side2))
	{
		temp = *side1;
		*side1 = *side2;
		*side2 = temp;
	}
}

bool isTriangleNotExist(int side1, int side2, int side3)
{
	if (side1 > (side2 + side3))
	{
		return true;
	}

	return false;
}

bool isTriangleEquilateral(int side1, int side2, int side3)
{
	if (side1 == side2 and side2 == side3)
	{
		return true;
	}
	else { return false; }
}

bool isTriangleRight(int side1, int side2, int side3)
{
	if (pow(side1, 2) == (pow(side2, 2) + pow(side3, 2)))
	{
		return true;
	}
	else { return false; }
}

bool isTriangleAcuteAngled(int side1, int side2, int side3)
{
	if (pow(side1, 2) < (pow(side2, 2) + pow(side3, 2)))
	{
		return true;
	}
	else { return false; }
}

bool isTriangleIsosceles(int side1, int side2, int side3)
{
	if (side1 == side2 or side2 == side3)
	{
		return true;
	}
	else { return false; }
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