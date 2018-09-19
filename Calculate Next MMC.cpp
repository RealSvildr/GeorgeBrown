#include <iostream>

#define sysStop() system("pause")
#define sysClear() system("cls")

using namespace std;

int main() {
	
	int Value, test = 2;
	
	cout << "Value: ";
	cin >> Value;
	
	while(Value % test != 0){
		test ++;
		
	}
	
	cout << "MMC = " << test << endl;
	
	
	return 0;
}