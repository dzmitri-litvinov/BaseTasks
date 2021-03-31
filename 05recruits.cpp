/*
The recruits are lined up. On command LEFT! some of them turn left, while others turn right. 
This is the starting position of the line. 
Further, each recruit acts as follows: seeing the face of a neighbor in front of him, he turns around in exactly a second. 
Eventually the turns will stop and the sergeant will sound the horn.
*/
#include <iostream>
#include <random>
#include <time.h>

#define QUANTITY 10

using namespace std;

void fillRecruitsRandom(char recruitsArray[QUANTITY]);
void printRecruitsArray(char recruitsArray[QUANTITY]);
void turnRecruits(char recruitsArray[QUANTITY]);
bool isTurnRequired(char recruitsArray[QUANTITY]);
void printCommandLeft();
void printHornSound();

int main()
{
	char recruitsArray[QUANTITY] = { '>','>','>', '<','<', '>', '<','>', '<','<' };
	
	printCommandLeft();
	fillRecruitsRandom(recruitsArray);
	printRecruitsArray(recruitsArray);

	while (isTurnRequired(recruitsArray)) 
	{
		turnRecruits(recruitsArray);
		printRecruitsArray(recruitsArray);
	}

	printHornSound();
	
	return 0;
}

void fillRecruitsRandom(char recruitsArray[QUANTITY])
{
	srand(time(NULL));

	for (int i = 0; i < QUANTITY; i++) {
		if (rand() % 2)
		{
			recruitsArray[i] = '<';
		}
		else
		{
			recruitsArray[i] = '>';
		}
	}
}

void printRecruitsArray(char recruitsArray[QUANTITY])
{
	for (int i = 0; i < QUANTITY; i++)
	{
		cout << recruitsArray[i];
	}
	cout << endl;
}

void turnRecruits(char recruitsArray[QUANTITY])
{
	int i = 0;
	while (i < QUANTITY - 1) 
	{
		if (recruitsArray[i] == '>' and recruitsArray[i + 1] == '<') 
		{
			recruitsArray[i] = '<';
			recruitsArray[i + 1] = '>';
			i += 2;
		}
		else
		{
			i++;
		}
	}
		
}

bool isTurnRequired(char recruitsArray[QUANTITY])
{
	for (int i = 0; i < QUANTITY - 1; i++)
	{
		if (recruitsArray[i] == '>' and recruitsArray[i + 1] == '<')
		{
			return true;
		}
	}

	return false;
}

void printCommandLeft()
{
	cout << "LEFT!" << endl;
}

void printHornSound()
{
	cout << "*** HORN SOUND ***" << endl;
}