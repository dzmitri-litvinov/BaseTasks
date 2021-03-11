#include <iostream>

using namespace std;

int main()
{
	double number;
	int temp;

	cout << "This programm will show the first number after point in double number." << endl << endl;

	cout << "Enter double: ";
	cin >> number;

	temp = number * 10;

	cout << "The first number after point is " << temp % 10 << endl;

	system("pause");
	return 0;
}