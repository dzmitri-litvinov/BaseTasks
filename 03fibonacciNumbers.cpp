#include <iostream>

using namespace std;

void inputNumberPosition(int* numberPosition);
int calculateNumberInPosition(int numberPosition);

int main()
{
	int numberPosition, numberInDesiredPosition;

	cout << "This program will show you the Fibonacci number in desired position." << endl << endl;

	inputNumberPosition(&numberPosition);
	numberInDesiredPosition = calculateNumberInPosition(numberPosition);

	cout << "Your Fibonacci number is " << numberInDesiredPosition << endl << endl;

	system("pause");
	return 0;
}

void inputNumberPosition(int* numberPosition)
{
	cout << "Enter the desired position of the Fibonacci number you want to see: ";
	cin >> *numberPosition;
}

int calculateNumberInPosition(int numberPosition)
{
	int numberBefore = 0, numberCurrent = 1;

	if (numberPosition == 1)
	{
		return numberBefore;
	}
	else if (numberPosition == 2)
	{
		return numberCurrent;
	}
	else
	{
		for (int i = 0; i < numberPosition - 2; i++)
		{
			int temp = numberCurrent;
			numberCurrent += numberBefore;
			numberBefore = temp;
		}

		return numberCurrent;
	}	
}