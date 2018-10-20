/*
* Carrier, with five holes
* Battleship, with four holes
* Cruiser, with three holes
* Submarine, with three holes
* Destroyer, with two holes
*/

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define sysPause() system("Pause")
#define sysClear() system("cls||clear")


using namespace std;

//
void header();
void start();
void initArrays();

//
void generateMap();

//
void match();

//
void setUserLocation();
void setComputerLocation();

//
void gotoXY(int x, int y);

const int vertSize = 13, horzSize = 12; //Map is 12 x 13
const bool seeComputerShips = false; // Set True to see the computer 
bool isAlive = true;
HANDLE  hConsole;


int userMap[vertSize][horzSize];
int compMap[vertSize][horzSize];

int main(){
	system("title Battleship Game");
	//system("color 17");
    srand (time(NULL));
	HWND hwnd = GetConsoleWindow();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 27);
	if( hwnd != NULL ){ MoveWindow(hwnd, 50, 25, 680, 650, TRUE); }

	header();
	start();
	
	while(isAlive) {
		// Set Locations
		initArrays();
		setComputerLocation();
		setUserLocation();

		// Start Game
		header();
		generateMap();
		
		// Play
		match();
		
		
		// Play Again;
		header();
		char continueGame;
		cout << "Do you want to start a new Game (Y/n)? ";
		continueGame = getchar();
		continueGame = toupper(continueGame);
		isAlive = (continueGame == 'Y');
		
	}    
	
	sysPause();
}

// Starters 
void header() {
	sysClear();
	
	cout << "      \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF" << endl;
	cout << "      \xB3                 Dev. My Name and User ID || Thats Private                 \xB3" << endl;
	cout << "      \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" << endl;	
	cout << endl;
	
}
void start() {
	int option = 0;
	
	while(option != 3 && option != 1) {
		cout << "Press" << endl;
		cout << " 1 - To Start Game" << endl;
		cout << " 2 - To See the Rules" << endl;
		cout << " 3 - To Exit" << endl;
		cin >> option;
		
		switch(option) {
			//case 1: 
			//	break;
			case 2:
				cout << endl << "Each player has 5 ships to place somewhere on their board." << endl;
				cout << "The ships can only be placed vertically or horizontally." << endl;
				cout << "No part of a ship may hang off the edge of the board." << endl;
				cout << "Ships must not overlap each other." << endl;
				cout << endl << "The ships are:" << endl;
				cout << "  Carrier\tUses 5 Spaces" << endl;
				cout << "  Battleship\tUses 4 Spaces" << endl;
				cout << "  Cruiser\tUses 3 Spaces" << endl;
				cout << "  Submarine\tUses 3 Spaces" << endl;
				cout << "  Destroyer\tUses 2 Spaces" << endl << endl;
				cout << "Each player has a a turn to choose the position where they will shoot." << endl;
				cout << "In response discover if it hitted the enemy or not." << endl;
				cout << "The winner is the one that sinks all enemy ships first." << endl;
				
				sysPause();
				header();
				
				break;
			case 3: 
				isAlive = false;
				break;
		};
	}
}
void initArrays() {
	for (int i = 0; i < vertSize; i++) {
		for (int j = 0; j < horzSize; j++) {
			userMap[i][j] = 0;
			compMap[i][j] = 0;
		}
	}
}


/// Draw Map
void drawUserShips() {
	//Base 3, 6	
	for (int i = 0; i < vertSize; i++) {
		for (int j = 0; j < horzSize; j++) {
			if(userMap[i][j] == 1) {
				gotoXY(3 + (3 * j), 6 + (2 * i));
				printf("\xB0\xB0");
			} else if(userMap[i][j] == 2) {
				gotoXY(3 + (3 * j), 6 + (2 * i));
				printf("\xDB\xDB");
			} else if(userMap[i][j] == 3) {
				gotoXY(3 + (3 * j), 6 + (2 * i));
				SetConsoleTextAttribute(hConsole, 12);
				printf("\xDB\xDB");
				SetConsoleTextAttribute(hConsole, 27);
			}
		}
	}
	
	gotoXY(0, 33);
}
void drawComputerShips() {
	//Base 3, 72
	for (int i = 0; i < vertSize; i++) {
		for (int j = 0; j < horzSize; j++) {
			if(compMap[i][j] == 1 && seeComputerShips) {
				gotoXY(72 - (3 * j), 6 + (2 * i));
				printf("\xB0\xB0");
			} else if(compMap[i][j] == 2) {
				gotoXY(72 - (3 * j), 6 + (2 * i));
				printf("\xDB\xDB");
			} else if(compMap[i][j] == 3) {
				gotoXY(72 - (3 * j), 6 + (2 * i));
				SetConsoleTextAttribute(hConsole, 12);
				printf("\xDB\xDB");
				SetConsoleTextAttribute(hConsole, 27);
			}
		}
	}
	
	gotoXY(0, 33);
}

void generateMap() {
	cout << "    1  2  3  4  5  6  7  8  9 10 11 12 12 11 10  9  8  7  6  5  4  3  2  1" << endl;
	cout << "  \xC9\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xCB\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xD1\xCD\xCD\xBB" << endl;
	
	cout << "A \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "B \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "C \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "D \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "E \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "F \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "G \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "H \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "I \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "J \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "K \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "L \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xD7\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xB6" << endl;
	
	cout << "M \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xB3  \xBA" << endl;
	cout << "  \xC8\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCA\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xCF\xCD\xCD\xBC" << endl;
	
	
	cout << endl ;
	
	drawUserShips();
	drawComputerShips();
	
}


// Set Ship Locations
void insertShip(int shipSpaceSize) {
	bool isVertical = rand() % 2;
	int vertPos = rand() % vertSize;
	int horzPos = rand() % horzSize;
	bool goodToGo = true;
	
	if(isVertical) {
		if(vertPos + shipSpaceSize > vertSize) {
			goodToGo = false;
		} else {
			for(int i = vertPos; i < (vertPos + shipSpaceSize) && goodToGo; i++) {
				if(compMap[i][horzPos] == 1) {
					goodToGo = false;
				}
			}
		}
	} else {
		if(horzPos + shipSpaceSize > horzSize) {
			goodToGo = false;
		} else {
			for(int j = horzPos; j < (horzPos + shipSpaceSize) && goodToGo; j++) {
				if(compMap[vertPos][j] == 1) {
					goodToGo = false;
				}
			}
		}
	}
	
	
	if(goodToGo) {
		if(isVertical) {
			for(int i = vertPos; i < (vertPos + shipSpaceSize) && goodToGo; i++) {
				compMap[i][horzPos] = 1;
			}
		} else {
			for(int j = horzPos; j < (horzPos + shipSpaceSize) && goodToGo; j++) {
				compMap[vertPos][j] = 1;
			}
		}
	} else {
		insertShip(shipSpaceSize);
	}
}
bool insertShip(int shipSpaceSize, bool isVertical, int vertPos, int horzPos) {
	bool goodToGo = true;
	
		if(isVertical) {
		if(vertPos + shipSpaceSize > vertSize) {
			goodToGo = false;
		} else {
			for(int i = vertPos; i < (vertPos + shipSpaceSize) && goodToGo; i++) {
				if(userMap[i][horzPos] == 1) {
					goodToGo = false;
				}
			}
		}
	} else {
		if(horzPos + shipSpaceSize > horzSize) {
			goodToGo = false;
		} else {
			for(int j = horzPos; j < (horzPos + shipSpaceSize) && goodToGo; j++) {
				if(userMap[vertPos][j] == 1) {
					goodToGo = false;
				}
			}
		}
	}
	
	if(goodToGo) {
		if(isVertical) {
			for(int i = vertPos; i < (vertPos + shipSpaceSize) && goodToGo; i++) {
				userMap[i][horzPos] = 1;
			}
		} else {
			for(int j = horzPos; j < (horzPos + shipSpaceSize) && goodToGo; j++) {
				userMap[vertPos][j] = 1;
			}
		}
	}
	
	return goodToGo;
}
void insertUserShip(string shipName, int shipSize) {
	bool isPossible = false;
	char isVertical = 'B';
	char vertPos = 'Z';
	int horzPos = 0;
	
	while(!isPossible) {
		header();
		generateMap();
		
		cout << "Insert " << shipName << " (" << shipSize << " Spaces)" << endl;
		cout << "Vertical or Horizontal (Insert V or H): ";
		fflush(stdin);
		isVertical = getchar();
		isVertical = toupper(isVertical);
		
		if(isVertical != 'V' && isVertical != 'H') {
			cout << endl << "INVALID POSITION." << endl;
			sysPause();
			continue;
		}
		
		cout << "Which line (A to M): ";		
		fflush(stdin);
		vertPos = getchar();
		vertPos = toupper(vertPos);
		
		if(vertPos < 65 || vertPos > 77) {
			cout << endl << "INVALID POSITION." << endl;
			sysPause();
			continue;
		}
		
		cout << "Which row (1 to 12): ";
		cin >> horzPos;
		
		if(horzPos < 1 || horzPos > 12) {
			cout << endl << "INVALID POSITION." << endl;
			sysPause();
			continue;
		}
		
		isPossible = insertShip(shipSize, isVertical == 'V',  vertPos - 65, horzPos - 1);
		
		if(!isPossible) {			
			cout << endl << "Invalid Position." << endl;
			sysPause();
		}
	}
}

void setUserLocation(){
	insertUserShip("Carrier", 5);
	insertUserShip("Battleship", 4);
	insertUserShip("Cruiser", 3);
	insertUserShip("Submarine", 3);
	insertUserShip("Destroyer", 2);
}
void setComputerLocation() {
	insertShip (5); //Carrier    5 Spaces
	insertShip (4); //Battleship 4 Spaces
	insertShip (3); //Cruiser    3 Spaces
	insertShip (3); //Submarine  3 Spaces
	insertShip (2); //Destroyer  2 Spaces
}

// Artificial Intelligence
void computerTurn(int* userLife) {
	int vertPos = rand() % vertSize;
	int horzPos = rand() % horzSize;
	
	if(userMap[vertPos][horzPos] == 0) {		
		userMap[vertPos][horzPos] = 2;
	} else if(userMap[vertPos][horzPos] == 1) {
		userMap[vertPos][horzPos] = 3;
		*userLife -= 1;	
	} else {
		computerTurn(userLife);
	}
}

void playerTurn(int userLife, int* computerLife) {
	bool movimentPossible = false;
	int vertPos = 0;//rand() % vertSize;
	int horzPos = 0;//rand() % horzSize;
	
	
	while(!movimentPossible) {
		header();
		generateMap();
		cout << "Player Life: " << userLife << " || PC Life: " << *computerLife << endl;
		
		cout << "Your turn to Attack" << endl;
		cout << "Which line (A to M): ";		
		fflush(stdin);
		vertPos = getchar();
		vertPos = toupper(vertPos);
		
		if(vertPos < 65 || vertPos > 77) {
			cout << endl << "INVALID POSITION." << endl;
			sysPause();
			continue;
		}
		
		cout << "Which row (1 to 12): ";
		cin >> horzPos;
		
		if(horzPos < 1 || horzPos > 12) {
			cout << endl << "INVALID POSITION." << endl;
			sysPause();
			continue;
		}
		
		vertPos -= 65;
		horzPos -= 1;
		
		
		if(compMap[vertPos][horzPos] == 0) {		
			compMap[vertPos][horzPos] = 2;
			movimentPossible = true;
		} else if(compMap[vertPos][horzPos] == 1) {
			compMap[vertPos][horzPos] = 3;
			*computerLife -= 1;
			movimentPossible = true;
		} else {
			cout << "Invalid Moviment." << endl;
			sysPause();
		}
	}
}


void match() {
	// The one that reaches 0 loses 
	// 17 is the sum of all ship squares.
	int userLife = 17, 
		computerLife = 17;
	// TODO: Show Status 
		
	bool isPlayerFirst = rand() % 2;
	
	//while(userLife > 0 && computerLife > 0)
	while(userLife * computerLife > 0) {
		if(isPlayerFirst) {
			playerTurn(userLife, &computerLife);
			computerTurn(&userLife); 
		} else {
			computerTurn(&userLife);
			playerTurn(userLife, &computerLife);
		}
	}
	
	header();
	generateMap();
	cout << "Player Life: " << userLife << " || PC Life: " << computerLife << endl << endl;
		
	if(computerLife == 0) {
		cout << "Player Won!!!" << endl;
	} else {
		cout << "YOU LOSE!!!!!!1!" << endl;
	}
	
	sysPause();	
}

////////////////////////////////////////////
//Extra
void gotoXY(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



