/*
* 2)	Create a fuction which turns int number, e.g. 1234 -> 4321
*/

#include <iostream>

using namespace std;

void printDescription();
int inputNumber(int number, string s);
int turnNumber(int numberInit);
void printNumberTurned(int numberTurned);

int main()
{
	int numberInit = 0, numberTurned;

	printDescription();

	numberInit = inputNumber(numberInit, "Enter your number: ");

	numberTurned = turnNumber(numberInit);

	printNumberTurned(numberTurned);

	return 0;
}

void printDescription()
{
	cout << "This program will turn over your number, e.g.: 1234 -> 4321" << endl << endl;
}

int inputNumber(int number, string s)
{
	cout << s;
	cin >> number;

	return number;
}

int turnNumber(int numberInit)
{
	int numberTurned = 0;

	while (numberInit > 0)
	{
		numberTurned = numberTurned * 10 + numberInit % 10;
		numberInit /= 10;
	}

	return numberTurned;
}

void printNumberTurned(int numberTurned)
{
	cout << endl << "Your turned number is: " << numberTurned << endl;
}