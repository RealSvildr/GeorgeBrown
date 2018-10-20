#include <iostream>
#include <time.h>

#define setColor() system("color 17")
#define sysStop() system("pause")
#define sysClear() system("cls")

using namespace std;

void generateMenu();

const double hstValue = .13;


int main() {
	setColor();
	int value = 1;
	
	
	while(value == 1 || value == 2){
		generateMenu();
		
		cin >> value;
		
		if(value == 1) {
			int bornYear;
			
			
			time_t theTime = time(NULL);
			struct tm *aTime = localtime(&theTime);
			int thisYear = aTime->tm_year + 1900; // Year is # years since 1900
			
			cout << "Enter the year you were born." << endl; 
			cin >> bornYear;
			
			cout << "Your Age is: " << (thisYear - bornYear) << endl;
			
		}else if(value == 2) {
			double value;
			
			cout << "Total Value: ";
			cin >> value;
			
			cout << endl << "HST: C$ " << (value * hstValue) << endl << "Total: C$ " << (value * (1 + hstValue)) << endl;
			
		} else {
			cout << "Exiting." << endl;
		}
		
		sysStop();
	}

	
	
	return 0;
}


void generateMenu() {
	sysClear();
	
	cout << "---------------------------------" << endl;
	cout << "||   Dev. By My Name and User ID || Thats Private   ||" << endl; 
	cout << "---------------------------------" << endl << endl;
	
	cout << " Press " << endl;
	cout << " 1 - To Enter the Year you were born." << endl;
	cout << " 2 - To Calculate the HST." << endl << endl;
	
	cout << " V.: ";

}

//void OddEven(){
		//int value;
	
	//cout << "Enter a Value: ";
	//cin >> value;
	//cout << endl << "The number is " << 
	//		(value % 2 == 0 ? "even" : "odd") << endl;
	//
	//sysStop();
//}
