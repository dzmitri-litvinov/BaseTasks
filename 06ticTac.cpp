/*Tic-Tac with computer*/
#include <iostream>

#define O_SIGN 79
#define X_SIGN 88

using namespace std;

void printDescription();
void initialTableFill(char table[3][3]);
void printTable(char table[3][3]);
string getPlayerName(string player, int playerNumber);
void clearScreen();
void printPlayersSigns(string player1, string player2, char humanSign, char computerSign);
void printEndGameMenu();
int inputNumber(int choice, string s);
int inputCell(string player,char table[3][3], int cell);
bool isCellNumberApplicable(int cell, char table[3][3]);
void changeCellInTable(int cell, char table[3][3], char playerSign);
void printPlayScreen(string player1, string player2, char table[3][3], char humanSign, char computerSign);
bool isHorisontalWin(char table[3][3]);
bool isVerticalWin(char table[3][3]);
bool isDiagonalWin(char table[3][3]);
bool isWin(char table[3][3]);
void printWin(string player);
void printDraw();
void chooseCellComputer(string player, char playerSign, char table[3][3], int turnCounter, char humanSign, char computerSign, int cellByHuman, int cellByHumanHistory[5]);
int cellByComp(char table[3][3], char humanSign, char computerSign, int turnCounter, int cellByHuman, int cellByHumanHistory[5]);
int cellByCompX3rdTurn(int turnCounter, int cellByHuman);
int cellByCompForWin(char table[3][3], char computerSign);
int cellByCompForNotLoose(char table[3][3], char humanSign);
int cellByCompOdd(char table[3][3]);
int cellByCompEven(char table[3][3]);

int main()
{
	char table[3][3];
	string player1, player2, playerInTurn;
	int gameCounter = 1, turnCounter = 1, choice = 0, cellByHuman = 0,  turnByHuman;
	int cellByHumanHistory[5];
	char humanSign = X_SIGN, computerSign = O_SIGN, signInTurn;
	bool isPlayer = true;
	
	initialTableFill(table);
	printDescription();
	printTable(table);

	//player1 = getPlayerName(player1, 1);
	player1 = "Dm";
	player2 = "Computer";

	while (true)
	{
		initialTableFill(table);
		cellByHuman = 0;
		turnCounter = 0;
		turnByHuman = 0;
				
		while (true)
		{
			if ((gameCounter + turnCounter) % 2)
			{
				playerInTurn = player1;
				signInTurn = humanSign;
			}
			else
			{
				playerInTurn = player2;
				signInTurn = computerSign;
			}

			if (playerInTurn == "Computer")
			{
				chooseCellComputer(playerInTurn, signInTurn, table, turnCounter, humanSign, computerSign, cellByHuman, cellByHumanHistory);
			}
			else
			{
				printPlayScreen(player1, player2, table, humanSign, computerSign);
				
				cellByHuman = inputCell(playerInTurn, table, cellByHuman);
				changeCellInTable(cellByHuman, table, signInTurn);
				cellByHumanHistory[turnByHuman] = cellByHuman;
				turnByHuman++;
			}
			
			turnCounter++;

			if (isWin(table))
			{
				printPlayScreen(player1, player2, table, humanSign, computerSign);
				printWin(playerInTurn);
				gameCounter++;
				break;
			}

			if (turnCounter == 9)
			{
				printPlayScreen(player1, player2, table, humanSign, computerSign);
				printDraw();
				gameCounter++;
				break;
			}
		}
				
		printEndGameMenu();
		choice = inputNumber(choice, "Please, enter the number: ");
		if (choice == 1) 
		{
			swap(computerSign, humanSign);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}

void printDescription()
{
	cout << "This is Tic-Tac!" << endl;
	cout << "Enter the number of the cell you want to mark in the table below." << endl;
	cout << "The player who succeeds in placing three of their marks in a diagonal, horizontal, or vertical row is the winner." << endl;
}

void initialTableFill(char table[3][3])
{
	int counter = 49;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			table[i][j] = counter;
			counter++;
		}
	}
}

void printTable(char table[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ' ' << table[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

string getPlayerName(string player, int playerNumber)
{
	cout << "Enter Player " << playerNumber << " name: ";
	cin >> player;

	return player;
}

void clearScreen()
{
	system("cls");
}

void printPlayersSigns(string player1, string player2, char humanSign, char computerSign)
{
	cout << player1 << " plays with " << humanSign << endl;
	cout << player2 << " plays with " << computerSign << endl << endl;
}

void printEndGameMenu()
{
	cout << "Would you like to play again?" << endl;
	cout << "1 to play again." << endl;
	cout << "Any button to exit." << endl << endl;
}

int inputNumber(int choice, string s)
{
	cout << s;
	cin >> choice;

	return choice;
}

int inputCell(string player, char table[3][3], int cell)
{
	cout << player << " is to make a choice: ";
	cin >> cell;

	while (isCellNumberApplicable(cell, table) == false)
	{
		cout << "Wrong input! Try another cell: ";
		cin >> cell;
	}

	return cell;
}

bool isCellNumberApplicable(int cell, char table[3][3])
{
	if (1 > cell or cell > 9)
	{
		return false;
	}

	if (cell % 3 != 0)
	{
		if (table[cell / 3][cell % 3 - 1] == X_SIGN or table[cell / 3][cell % 3 - 1] == O_SIGN)
		{
			return false;
		}
	}
	else
	{
		if (table[cell / 3 - 1][2] == X_SIGN or table[cell / 3 - 1][2] == O_SIGN)
		{
			return false;
		}
	}

	return true;
}

void changeCellInTable(int cell, char table[3][3], char playerSign)
{
	if (cell % 3 == 0)
	{
		table[cell / 3 - 1][2] = playerSign;
	}

	if (cell % 3 != 0)
	{
		table[cell / 3][cell % 3 - 1] = playerSign;
	}
}

void printPlayScreen(string player1, string player2, char table[3][3], char humanSign, char computerSign)
{
	clearScreen();
	printPlayersSigns(player1, player2, humanSign, computerSign);
	printTable(table);
}

bool isHorisontalWin(char table[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (table[i][0] == table[i][1] and table[i][0] == table[i][2])
		{
			return true;
		}
	}

	return false;
}


bool isVerticalWin(char table[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (table[0][i] == table[1][i] and table[0][i] == table[2][i])
		{
			return true;
		}
	}

	return false;
}


bool isDiagonalWin(char table[3][3])
{
	if ((table[0][0] == table[1][1] and table[0][0] == table[2][2]) or (table[0][2] == table[1][1] and table[0][2] == table[2][0]))
	{
		return true;
	}
	return false;
}

bool isWin(char table[3][3])
{
	return isHorisontalWin(table) or isVerticalWin(table) or isDiagonalWin(table);
}

void printWin(string player)
{
	cout<< endl << "*** " << player << " WIN ***" << endl << endl;
}

void printDraw()
{
	cout << endl << "*** DRAW ***" << endl << endl;
}

void chooseCellComputer(string player, char playerSign, char table[3][3], int turnCounter, char humanSign, char computerSign, int cellByHuman, int cellByHumanHistory[5])
{
	int cell = 0;

	cell = cellByComp(table, humanSign, computerSign, turnCounter, cellByHuman, cellByHumanHistory);
	
	changeCellInTable(cell, table, playerSign);
}

int cellByComp(char table[3][3], char humanSign, char computerSign, int turnCounter, int cellByHuman, int cellByHumanHistory[5])
{
	int temp;

	temp = cellByCompX3rdTurn(turnCounter, cellByHuman);

	if (temp != 0)
		return temp;

	temp = cellByCompForWin(table, computerSign);
	if (temp != 0)
		return temp;

	temp = cellByCompForNotLoose(table, humanSign);
	if (temp != 0)
		return temp;

	if (turnCounter == 3 and table[1][1] == O_SIGN)
	{
		if ((cellByHumanHistory[0] % 2) * (cellByHumanHistory[1] % 2))
		{
			return cellByCompEven(table);
		}
		else
		{
			int evenCell = 0;

			if (cellByHumanHistory[0] % 2) 
				evenCell = cellByHumanHistory[1];
			else 
				evenCell = cellByHumanHistory[0];

			if (evenCell == 8 or evenCell == 4)
				return 7;
			else
				return 3;
		}
	}

	temp = cellByCompOdd(table);
	if (temp != 0)
		return temp;
	
	temp = cellByCompEven(table);
	return temp;	
}

int cellByCompX3rdTurn(int turnCounter, int cellByHuman)
{
	if (turnCounter == 2)
	{
		if (cellByHuman == 2 or cellByHuman == 4)
		{
			return 9;
		}
		else if (cellByHuman == 8 or cellByHuman == 6)
		{
			return 1;
		}
		else {}
	}

	return 0;
}

int cellByCompForWin(char table[3][3], char computerSign)
{
	for (int i = 1; i < 10; i++) //for win
	{
		if (isCellNumberApplicable(i, table))
		{
			changeCellInTable(i, table, computerSign);
			if (isWin(table))
			{
				changeCellInTable(i, table, i + 48);
				return i;
			}
			else
			{
				changeCellInTable(i, table, i + 48);
			}
		}
	}

	return 0;
}

int cellByCompForNotLoose(char table[3][3], char humanSign)
{
	for (int i = 1; i < 10; i++) //for not to loose
	{
		if (isCellNumberApplicable(i, table))
		{
			changeCellInTable(i, table, humanSign);
			if (isWin(table))
			{
				changeCellInTable(i, table, i + 48);
				return i;
			}
			else
			{
				changeCellInTable(i, table, i + 48);
			}
		}
	}

	return 0;
}

int cellByCompOdd(char table[3][3])
{
	if (isCellNumberApplicable(5, table))
	{
		return 5;
	}

	for (int i = 1; i < 10; i += 2)
	{
		if (isCellNumberApplicable(i, table))
		{
			return i;
		}
	}

	return 0;
}

int cellByCompEven(char table[3][3])
{
	for (int i = 2; i < 9; i += 2)
	{
		if (isCellNumberApplicable(i, table))
		{
			return i;
		}
	}

	return 0;
}
