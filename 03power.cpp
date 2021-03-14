#include <iostream>

using namespace std;

double calculateNumberInPower(double numberX, int powerN);
void inputNumberX(double* numberX);
void inputPowerN(int* powerN);

int main()
{
	double numberX, numberXInPowerN;
	int powerN;

	cout << "This program raises the number x to the power n." << endl << endl;

	inputNumberX(&numberX);
	inputPowerN(&powerN);

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

void inputPowerN(int* powerN)
{
	cout << "Enter your power n: ";
	cin >> *powerN;
}

void inputNumberX(double* numberX)
{
	cout << "Enter your number x: ";
	cin >> *numberX;
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