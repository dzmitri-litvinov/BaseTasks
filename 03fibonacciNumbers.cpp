#include <iostream>

using namespace std;

void fibonacciNumberPositionInput(int* fibonacciNumberPosition);
int fibinacciNumberInPositionNCalculation(int fibonacciNumberPosition);

int main()
{
	int fibonacciNumberPosition, fibonacciNumberInDesiredPosition;

	cout << "This program will show you the Fibonacci number in desired position." << endl << endl;

	fibonacciNumberPositionInput(&fibonacciNumberPosition);
	fibonacciNumberInDesiredPosition = fibinacciNumberInPositionNCalculation(fibonacciNumberPosition);

	cout << "Your Fibonacci number is " << fibonacciNumberInDesiredPosition << endl << endl;

	system("pause");
	return 0;
}

void fibonacciNumberPositionInput(int* fibonacciNumberPosition)
{
	cout << "Enter the desired position of the Fibonacci number you want to see: ";
	cin >> *fibonacciNumberPosition;
}

int fibinacciNumberInPositionNCalculation(int fibonacciNumberPosition)
{
	int numberBefore = 0, numberCurrent = 1;

	if (fibonacciNumberPosition == 1)
	{
		return numberBefore;
	}
	else if (fibonacciNumberPosition == 2)
	{
		return numberCurrent;
	}
	else
	{
		for (int i = 0; i < fibonacciNumberPosition - 2; i++)
		{
			int temp = numberCurrent;
			numberCurrent += numberBefore;
			numberBefore = temp;
		}

		return numberCurrent;
	}	
}