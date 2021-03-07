#include <iostream>
#include <cmath>

using namespace std;

int main()
{	
	int binaryNumber, decimalNumber = 0, counter = 0;

	cout << "This program converts a number from binary to decimal." << endl;

	cout << "Enter binary number: ";
	cin >> binaryNumber;

	while (binaryNumber)
	{
		decimalNumber += (binaryNumber % 10) * pow(2, counter);
		counter++;
		binaryNumber /= 10;
	}
	
	cout << "Decimal number is " << decimalNumber << endl;
	

	cout << endl;
	system("pause");
	return 0;
}