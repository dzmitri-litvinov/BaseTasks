#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
	int numberByComp, numberByUser;

	cout << "Guess the number between 1 and 10. Computer will say, is the number less or more than entered." << endl << endl;

	srand(time(NULL));
	numberByComp = rand() % 10 + 1;

	while (true)
	{
		cout << "Enter your number: ";
		cin >> numberByUser;

		if (numberByComp == numberByUser)
		{
			cout << endl << "***********" << endl << "You are right!!!" << endl << endl;

			break;
		}
		else if (numberByComp < numberByUser)
		{
			cout << "Try smth less... ";
		}
		else { cout << "Try smth more... "; }
	}

	system("pause");
	return 0;
}