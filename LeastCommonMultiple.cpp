#include <iostream>

using namespace std;

int main()
{
	int LeastCommonMultiple, GreatestCommonDivisor, numb1, numb2, temp, a, b;

	cout << "This programm will calculate the least common multiple." << endl << endl;

	cout << "Enter the first number: ";
	cin >> numb1;
	cout << "Enter the second number: ";
	cin >> numb2;

	if (numb1 < numb2)
	{
		a = numb1;
		b = numb2;
	}
	else
	{
		b = numb1;
		a = numb2;
	}

	while (1)
	{
		if (b % a)
		{
			temp = b % a;
			b = a;
			a = temp;
		}
		else
		{
			GreatestCommonDivisor = a;
			LeastCommonMultiple = numb1 * numb2 / GreatestCommonDivisor;
			cout << endl << "The least common multiple is " << LeastCommonMultiple << endl;

			cout << endl;
			system("pause");
			return 0;
		}
	}
}