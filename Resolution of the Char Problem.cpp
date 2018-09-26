#include<iostream>

#define sysColor() system("color 17")
#define sysClear() system("cls||clear")
#define sysPause() system("pause")

using namespace std;
void header();
char getCh();


int main(){ 
	bool iWant = true;
	char thatValueYouKnowWhatDoes;
	
	while(iWant) {
		header();
		
		cout << "Enter a value (Clue a or b): ";
		thatValueYouKnowWhatDoes = getCh();
		
		thatValueYouKnowWhatDoes = toupper(thatValueYouKnowWhatDoes);
		cout << endl;
		
		if(thatValueYouKnowWhatDoes == 'A' ||  
		thatValueYouKnowWhatDoes == 'B'){
			cout << "You got it bro!" << endl;
		} else {
			cout << "Naa, but at least you tried!" << endl;		
		}
		
		sysPause();
	}
	
	return 0;
}

void header(){
	sysColor();
	sysClear();
	
	cout << "User ID: 101181292" << endl;
}

char getCh() {
	char retValue, tempValue;
	retValue = getchar();
	while ((tempValue = getchar()) != '\n' && tempValue != EOF);
	
	return retValue;
}
