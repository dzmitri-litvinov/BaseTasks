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
bool isMonthWrong(int month);
bool isDayWrong(int day, int month, int year);
bool isYearLip(int year);
bool isMonth31Days(int month);

int main()
{
	int year = 0, month = 0, day = 0;

	printDecription();

	year = input(year, "year: ");

	while (isMonthWrong(month))
	{
		month = input(month, "month: ");
	}

	while (isDayWrong(day, month, year))
	{
		day = input(day, "day: ");
	}

	printFateNumber(calculateFateNumber(year, month, day));

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

bool isMonthWrong(int month)
{
	bool flag = false;

	if (month < 1 or month >12)
	{
		flag = true;
	}

	return flag;
}

bool isDayWrong(int day, int month, int year)
{
	bool flag = false;

	if (day < 1)
	{
		flag = true;
	}
	else if (isMonth31Days(month))
	{
		if (day > 31)
		{
			flag = true;
		}
	}
	else if (month == 2)
	{
		if (isYearLip(year))
		{
			if (day > 29)
			{
				flag = true;
			}
		}
		else
		{
			if (day > 28)
			{
				flag = true;
			}
		}
	}
	else
	{
		if (day > 30)
		{
			flag = true;
		}
	}

	return flag;
}

bool isYearLip(int year)
{
	bool flag = true;

	if (year % 4)
	{
		flag = false;
	}

	return flag;
}

bool isMonth31Days(int month)
{
	bool flag = false;

	if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12)
	{
		flag = true;
	}

	return flag;
}