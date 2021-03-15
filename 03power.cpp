#include <iostream>

using namespace std;

double calculateNumberInPower(double numberX, double powerN);
double inputNumber(double number, string s);

int main()
{
	double numberX = 0, powerN = 0, numberXInPowerN;
	
	cout << "This program raises the number x to the power n." << endl << endl;

	numberX = inputNumber(numberX, "number x: ");
	powerN = inputNumber(powerN, "power n: ");

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

double inputNumber(double number, string s)
{
	cout << "Enter your " << s;
	cin >> number;

	return number;
}

double calculateNumberInPower(double numberX, double powerN)
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