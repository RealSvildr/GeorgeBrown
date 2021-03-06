#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <thread>
#include <time.h>
#include <vector>
#include <windows.h>

#define sysPause() system("Pause")
#define sysClear() system("cls||clear")
#define playerPos 11
#define computerPos 47
#define computerSpeed 380

using namespace std;

#pragma region Prototypes
void init();
void header();
void ingameBody();
void gotoXY(int, int);

void Rock(int);
void Paper(int);
void Scissors(int);

///// DBO
void playGame(string);
string getPlayer();
void checkWinLoseRatio(string);
void updateWinLose(string, int);
int computerOption();

char getCh();
vector<string> splitString(string, char);
#pragma endregion


int main()
{
	init();
	string player;
	bool isAlive = true;
	bool isInsideMenu = true;

	while (isAlive) {
		player = getPlayer();

		isInsideMenu = true;
		while (isInsideMenu) {
			char c = 5;
			while (c < 49 || c > 52) {
				header();
				cout << "Press " << endl;
				cout << "1 - To Play" << endl;
				cout << "2 - Check your Win/Lose Ratio" << endl;
				cout << "3 - Change Player" << endl;
				cout << "4 - Exit" << endl;
				c = getCh();
			}

			switch (c)
			{
			case 49: // Play Time
				playGame(player);
				break;
			case 50: // Check Win/Lose
				checkWinLoseRatio(player);
				break;
			case 51: // Change Player
				isInsideMenu = false;
				break;
			case 52: // Exit
				isInsideMenu = false;
				isAlive = false;
				break;
			}
		}
	}

	//ComputerOption();


	sysPause();
	return 0;
}


#pragma region Graphic
void init() {
	HANDLE  hConsole;
	HWND hwnd = GetConsoleWindow();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 27);
	SetWindowTextA(hwnd, "Rock Paper Scissors");
	if (hwnd != NULL) { MoveWindow(hwnd, 50, 25, 680, 650, TRUE); }


	srand((unsigned)time(NULL));
}
void header() {
	sysClear();

	cout << "      \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF" << endl;
	cout << "      \xB3                 Dev. (My Name and User ID || Thats Private)                 \xB3" << endl;
	cout << "      \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" << endl;
	cout << endl << endl;

}
void ingameBody() {
	cout << "                   Player                              Computer" << endl;
	cout << "         \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF          \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xB3                        \xB3          \xB3                        \xB3" << endl;
	cout << "         \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9          \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" << endl;
}

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Rock(int posY) {
	gotoXY(posY, 9);  cout << "                      ";
	gotoXY(posY, 10); cout << "                      ";
	gotoXY(posY, 11); cout << "                      ";
	gotoXY(posY, 12);  cout << "                      ";
	gotoXY(posY, 13); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2";
	gotoXY(posY, 14); cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 15); cout << "\xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 16); cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 17); cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 18); cout << "  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 19); cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	gotoXY(posY, 20); cout << "     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	gotoXY(posY, 23); cout << "          Rock          ";
}
void Paper(int posY) {
	gotoXY(posY, 9);  cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2";
	gotoXY(posY, 10);  cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2";
	gotoXY(posY, 11); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2";
	gotoXY(posY, 12); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2";
	gotoXY(posY, 13); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2";
	gotoXY(posY, 14); cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 15); cout << "\xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 16); cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 17); cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 18); cout << "  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 19); cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	gotoXY(posY, 20); cout << "     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	gotoXY(posY, 23); cout << "          Paper         ";
}
void Scissors(int posY) {
	gotoXY(posY, 9);  cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2			   ";
	gotoXY(posY, 10); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2			   ";
	gotoXY(posY, 11); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2			   ";
	gotoXY(posY, 12); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2			   ";
	gotoXY(posY, 13); cout << "   \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2 \xB2\xB2\xB2";
	gotoXY(posY, 14); cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 15); cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 16); cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 17); cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 18); cout << "  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoXY(posY, 19); cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	gotoXY(posY, 20); cout << "     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	gotoXY(posY, 23); cout << "        Scissors        ";

}
#pragma endregion

#pragma region DBO
void playGame(string playerName) {
	bool isPlaying = true;
	while (isPlaying) {
		int valuePlayer, valueComputer;
		char playerSelection = -5;

		while (playerSelection < 49 || playerSelection > 51) {
			header();
			ingameBody();

			if (playerSelection != -5) {
				cout << "Invalid Character." << endl;
			}

			cout << "Have your selection:" << endl;
			cout << "1 - Rock" << endl;
			cout << "2 - Paper" << endl;
			cout << "3 - Scissors" << endl;

			playerSelection = getCh();
		}

		header();
		ingameBody();

		valuePlayer = playerSelection - 48;
		switch (valuePlayer) {
		case 1:
			Rock(playerPos);
			break;
		case 2:
			Paper(playerPos);
			break;
		case 3:
			Scissors(playerPos);
			break;
		}


		valueComputer = computerOption();


		if (valuePlayer == valueComputer) { // Tie
			updateWinLose(playerName, 3);
			cout << "It was a tie." << endl;
		}
		else if (valuePlayer == valueComputer + 1 || valuePlayer == valueComputer - 2) {
			updateWinLose(playerName, 1);
			cout << "You own the game" << endl;

		}
		else {
			updateWinLose(playerName, 2);
			cout << "You lost the game" << endl;
		}

		char pAgain;
		cout << "Do you want to play again (Y/n)";
		pAgain = getCh();
		pAgain = pAgain == 'Y' ? 'y' : pAgain;

		if (pAgain != 'y') {
			isPlaying = false;
		}
	}
}

int computerOption() {
	int numberTimes = 25; //Number of Times the option will flash before chosing
	int itemSelected = rand() % 3;

	for (int i = numberTimes; i >= 0; i--) {
		switch ((itemSelected + i) % 3) {
		case 0:
			Rock(computerPos);
			break;
		case 1:
			Paper(computerPos);
			break;
		case 2:
			Scissors(computerPos);
			break;
		}


		this_thread::sleep_for(chrono::milliseconds(computerSpeed - (15 * i)));
	}

	gotoXY(0, 25);

	return itemSelected + 1;
}

string getPlayer() {
	string player = "zmw";

	while (player.length() < 8 && player != "Svildr") {
		header();

		if (player != "zmw") {
			cout << "Username has to be at least 8 characters." << endl;
		}

		cout << "Please inform your username: ";
		cin >> player;
	}

	//ofstream playerFile;
	//I`d rather create a txt and put every player there ordered by name Asc, and use a Binary Search.
	ifstream playerFile(player + ".txt");

	//playerFile.
	//File doesnt Exists
	if (!playerFile.good()) {
		ofstream createFile(player + ".txt");
		createFile << "0/0/0";
		createFile.close();
	}

	playerFile.close();

	return player;
}

void checkWinLoseRatio(string playerName) {
	string score;
	int wins = 0, loses = 0, ties = 0;
	double wlRatio = 0;

	ifstream readFile(playerName + ".txt");
	if (readFile.good()) {
		getline(readFile, score);
		readFile.close();
		vector<string> str = splitString(score, '/');

		wins = stoi(str[0]);
		loses = stoi(str[1]);
		ties = stoi(str[2]);
		readFile.close();
	}


	if (wins == 0 && loses > 0) {
		wlRatio = 1 / (double)loses;
	}
	else if (wins > 0 && loses == 0) {
		wlRatio = wins;
	}
	else if (wins > 0 && loses > 0) {
		wlRatio = (double)wins / loses;
	}

	header();
	cout << "User:" << playerName << endl;
	cout << "Wins: " << wins << ".     Loses: " << loses << ".     Ties: " << ties << "." << endl;
	cout << "W/L Ratio: " << wlRatio << "." << endl;

	sysPause();
}
void updateWinLose(string playerName, int winLoseTie) {
	string oldScore;
	int wins, loses, ties;

	ifstream readFile(playerName + ".txt");
	if (readFile.good()) {
		getline(readFile, oldScore);
		readFile.close();
		vector<string> str = splitString(oldScore, '/');

		wins = stoi(str[0]);
		loses = stoi(str[1]);
		ties = stoi(str[2]);
		readFile.close();

		if (winLoseTie == 1) { wins++; }
		else if (winLoseTie == 2) { loses++; }
		else { ties++; }


		ofstream writeFile(playerName + ".txt");//, std::ios_base::app
		writeFile << wins << "/" << loses << "/" << ties;
		writeFile.close();
	}
	else {
		cout << "Err: Could not load user archive" << endl;
		cout << "This could be happening due to several reasons." << endl;
		cout << "   1) The file is already open." << endl;
		cout << "   2) The file could not be created." << endl;
		cout << "   3) Lack of file permissions." << endl;
			
		sysPause();
	}
}

char getCh() {
	char retValue, tempValue;
	retValue = getchar();
	while ((tempValue = getchar()) != '\n' && tempValue != EOF);

	return retValue;
}

vector<string> splitString(string str, char spliter) {
	vector<string> sString;
	string tempString = "";
	int totalSize = 0;

	while (str.length() > 0) {
		if (str[0] == spliter) {
			sString.push_back(tempString);
			tempString = "";

			totalSize++;
		}
		else {
			tempString += str[0];
		}

		str = str.substr(1, str.length() - 1);
	}


	if (tempString != "") {
		sString.push_back(tempString);
	}

	return sString;
}
#pragma endregion
