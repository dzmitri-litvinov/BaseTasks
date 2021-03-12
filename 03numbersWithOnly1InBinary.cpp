#include <iostream>
#include <cmath>

using namespace std;

int fromBinaryToDecimal(int binaryNumber);
void printOnly1ContainBinary(int decimalNumberEntered);

int main()
{
	int decimalNumberEntered;

	cout << "This program will show you all decimal numbers from 0 to desired which consist of only 1 if converted to binary numbers." << endl << endl;

	cout << "Enter desired decimal number: ";
	cin >> decimalNumberEntered;

	printOnly1ContainBinary(decimalNumberEntered);

	system("pause");
	return 0;
}

int fromBinaryToDecimal(int binaryNumber)
{
	int decimalNumber = 0, counter = 0;

	while (binaryNumber)
	{
		decimalNumber += (binaryNumber % 10) * pow(2, counter);
		counter++;
		binaryNumber /= 10;
	}

	return decimalNumber;
}

void printOnly1ContainBinary(int decimalNumberEntered)
{
	int binaryNumber = 1, add1 = 10;

	while (decimalNumberEntered >= fromBinaryToDecimal(binaryNumber))
	{
		cout << "decimal: " << fromBinaryToDecimal(binaryNumber);
		//cout << "\t\tbinary: " << binaryNumber << endl;

		binaryNumber += add1;
		add1 *= 10;
	}
}
