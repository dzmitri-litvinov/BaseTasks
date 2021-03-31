/*
The array stores the values of the terrain profile heights with a constant horizontal step. 
Find areas (elevation points) that are invisible to the observer at the first point.
*/
#include <iostream>
#include <random>
#include <time.h>

#define QUANTITY 10

using namespace std;

void fillHeightRandom (double heightArray[QUANTITY]);
void printAllHeights(double heightArray[QUANTITY]);
bool isNotVisible(double heightOfOblerver, int numberOfPoint, double heightArray[QUANTITY]);
void printHeight(double heightArray[], int i);

int main()
{
	double heightArray[QUANTITY] = { 8,0,1,3,8,8,7,2,9,4 };

	fillHeightRandom(heightArray);
	printAllHeights(heightArray);

	cout << "Not visible heights are: " << endl;	
	for (int i = 2; i < QUANTITY; i++)
	{
		if (isNotVisible(heightArray[0], i, heightArray))
		{
			printHeight(heightArray, i);
		}
	}

	return 0;
}

void fillHeightRandom(double heightArray[QUANTITY])
{
	srand(time(NULL));

	for (int i = 0; i < QUANTITY; i++)	{
		heightArray[i] = rand() % 20;
	}
}

void printAllHeights(double heightArray[QUANTITY])
{
	for (int i = 0; i < QUANTITY; i++) {
		cout << i+ 1 << ")\t" << heightArray[i] << "\t";

		for (int j = 0; j < heightArray[i]; j++) {
			cout << "_";
		}

		cout << endl;
	}
}

bool isNotVisible(double heightOfOblerver, int numberOfPoint, double heightArray[QUANTITY])
{
	bool isNotVisible = false;
	double coefOfTriangle;
	
	
		if (heightOfOblerver > heightArray[numberOfPoint])
		{
			for (int i = 1; i < numberOfPoint; i++)
			{
				if (heightArray[i] - heightArray[numberOfPoint] > 0)
				{
					coefOfTriangle = (heightOfOblerver - heightArray[numberOfPoint]) / numberOfPoint;
					if (coefOfTriangle <= (heightArray[i] - heightArray[numberOfPoint]) / (numberOfPoint - i))
					{
						return true;
					}
				}
			}
		}
		else if (heightOfOblerver < heightArray[numberOfPoint])
		{
			for (int i = 1; i < numberOfPoint; i++)
			{
				if (heightArray[i] - heightOfOblerver > 0)
				{
					coefOfTriangle = (heightArray[numberOfPoint] - heightOfOblerver) / numberOfPoint;
					if (coefOfTriangle <= (heightArray[i] - heightOfOblerver) / i)
					{
						return true;
					}
				}
			}
		}
		else
		{
			for (int i = 1; i < numberOfPoint; i++) 
			{
				if (heightOfOblerver <= heightArray[i])
				{
					return true;
				}
			}			
		}
	
	return false;
}

void printHeight(double heightArray[], int i)
{
	cout << i + 1 << ")\t" << heightArray[i] << endl;
}