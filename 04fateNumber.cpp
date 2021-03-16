/*
* 1)	NUMBER OF FATE. The digits of the full date of birth are added together until one digit is obtained.
*/

#include <iostream>

using namespace std;

int input(int number, string s);
int calculateSingleNumber(int number);
int calculateFateNumber(int year, int month, int day);
void printFateNumber(int fateNumber);
void printDecription();

int main()
{
	int year = 0, month = 0, day = 0, fateNumber;

	printDecription();

	year = input(year, "year: ");
	month = input(month, "month: ");
	day = input(day, "day: ");

	//fateNumber = calculateSingleNumber(year) + calculateSingleNumber(month) + calculateSingleNumber(day);
	//fateNumber = calculateSingleNumber(fateNumber);

	fateNumber = calculateFateNumber(year, month, day);

	printFateNumber(fateNumber);

	return 0;
}

int input(int number, string s)
{
	cout << "Enter your " << s;
	cin >> number;

	return number;
}

int calculateSingleNumber(int number)
{
	int temp;

	while (number >= 10)
	{
		temp = 0;

		while (number > 0)
		{
			temp += number % 10;
			number /= 10;
		}

		number = temp;
	}

	return number;
}

void printFateNumber(int fateNumber)
{
	cout << endl << "Your fate number is " << fateNumber << endl;
}

void printDecription()
{
	cout << "This program will calculate your fate number after you enter your date of birth." << endl << endl;
}

int calculateFateNumber(int year, int month, int day)
{
	int number;

	number = calculateSingleNumber(year) + calculateSingleNumber(month) + calculateSingleNumber(day);

	return calculateSingleNumber(number);
}