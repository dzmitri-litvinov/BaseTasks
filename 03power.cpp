#include <iostream>

using namespace std;

double calculateNumberInPower(double numberX, int powerN);
double inputNumber();

int main()
{
	double numberX, numberXInPowerN;
	int powerN;

	cout << "This program raises the number x to the power n." << endl << endl;

	cout << "Enter your number x: ";
	numberX = inputNumber();
	cout << "Enter your power n: ";
	powerN = inputNumber();


	if (numberX == 0)
	{
		cout << endl << "Error! Invalid number x = 0." << endl << endl;

		system("pause");
		return -1;
	}

	numberXInPowerN = calculateNumberInPower(numberX, powerN);

	cout << endl << "The number x = " << numberX << " in the power of n = " << powerN << " is " << numberXInPowerN << endl << endl;

	system("pause");
	return 0;
}

double inputNumber()
{
	double number;

	cin >> number;

	return number;
}

double calculateNumberInPower(double numberX, int powerN)
{
	double result = 1;

	if (powerN > 0)
	{
		for (int i = 0; i < powerN; i++)
		{
			result *= numberX;
		}
	} 
	else if (powerN < 0)
	{
		for (int i = 0; i > powerN; i--)
		{
			result /= numberX;
		}
	}

	return result;
}