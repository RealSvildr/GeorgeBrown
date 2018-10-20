#include <iostream>
#include <string>

#define sysColor() system("color 17")
#define sysClear() system("cls||clear")
#define sysPause() system("pause")
#define sysName() system("title Tic Tac Toe")


using namespace std;

//
void header();
char getCh();
void printTable();
void clearTable();
int checkValidity(int input);
bool checkWinningCondition();

//
const char players[2] = { 'O', 'X' };
const int height = 3, length = 3;
int table[height][length];

int main()
{
	sysName();
	header();

	bool isRunning = true;
	bool playingGame = true;
	int playerInput = -1;
	int tempHeight, tempLength;
	int endGame = -1;
	int winner = -1;


	while (isRunning) {
		clearTable();

		while (playingGame) {
			printTable();

			for (int i = 0; i < sizeof(players) / sizeof(*players); i++) {
				cout << "It's players '" << players[i] << " turn: ";
				cin >> playerInput;

				switch (checkValidity(playerInput)) {
				case 0:
					tempHeight = playerInput / length;
					tempLength = playerInput - (length * tempHeight);

					table[tempHeight][tempLength] = i;
					printTable();

					if(checkWinningCondition()) {
						winner = i;
						break;
					}

					break;
				case 1:
					printTable();
					cout << "The input is invalid." << endl;
					i--;
					break;
				case 2:
					printTable();
					cout << "This position is already taken." << endl;
					i--;
					break;
				}
			}

			cout << endl << "Type 0 to finalize the game, or any other key to continue: ";
			cin >> endGame;

			
			playingGame = isRunning = !(endGame == 0);
		}

		if (winner != -1) {
			cout << "The Winner is " << players[winner] << endl;
			cout << "Type 0 to finalize the game, or any other key to continue: ";
			cin >> endGame;

			winner = -1;
			playingGame = isRunning = !(endGame == 0);
		}
	}


	return 0;
}

void header() {
	sysColor();
	sysClear();

	cout << "      \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF" << endl;
	cout << "      \xB3                 Dev. My Name and User ID || Thats Private                 \xB3" << endl;
	cout << "      \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" << endl;
	cout << endl;

}

void printTable() {
	header();

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			if (j != 0) {
				cout << " | ";
			}

			if (table[i][j] == 0) {
				cout << players[0];
			}
			else if (table[i][j] == 1) {
				cout << players[1];
			}
			else {
				cout << length * i + j;
			}

			//cout << (table[i][j] == 0) ? "X" : (table[i][j] == 1) ? "O" : to_string(length * i + j);
		}
		cout << endl;
	}
}

void clearTable() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < height; j++) {
			table[i][j] = -1;
		}
	}
}

int checkValidity(int input) {
	if (input < 0 || input > height * length - 1) {
		return 1;
	}

	int inputHeight = input / length;
	int inputLength = input - (length * inputHeight);

	if (table[inputHeight][inputLength] != -1) {
		return 2;
	}

	return 0;
}

bool checkWinningCondition() {
	// X - X
	// X X -
	// X X X

	//  1   2   4
	//  8  16  32
	// 64 128 256

	// 64 + 8 + 1 = 73
	// 2 + 16 + 128 = 146
	// 4 + 32 + 256 = 292
	// 1 + 2 + 4 = 7
	// 8 + 16 + 32 = 56
	// 64 + 128 + 256 = 448
	// 4 + 16 + 64 = 84
	// 1 + 16 + 256 = 273

	// Check Lines

	for (int i = 0; i < length; i++) {
		
	}

	
}

char getCh() {
	char retValue, tempValue;
	retValue = getchar();
	while ((tempValue = getchar()) != '\n' && tempValue != EOF);

	return retValue;
}
