//Midterm
//By: Kyle Zhang
//7/20/19
//Sources: None

#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string>

using namespace std;

int main() {

	int number;
	int sentinel = -999;
	int oddnumbersum = 0;
	int evennumbersum = 0;
	int oddnumbercount = 0;
	int evennumbercount = 0;

	cout << "Welcome to Kyle's program which calculates sum of even and odd numbers from -999 to a number that you will wish to input. " << endl;
	cin >> number;
	while (number != sentinel) { // Condition to exit loop
		if (number >= 0) {
			//If odd number
			if (number % 2 == 1) {
				oddnumbersum = oddnumbersum + number;
				oddnumbercount++;
			}
			//If even number
			if (number % 2 == 0) {
				evennumbersum = evennumbersum + number;
				evennumbercount++;
			}
		}
		else {
			cout << "This is a negative number, it will be ignored. " << endl;
		}
		
		cout << "Enter another number: ";
		cin >> number;
	} 
	cout << "The sum of all even numbers is " << evennumbersum << "." << endl;
	cout << "The count of all even numbers is " << evennumbercount << "." << endl;
	cout << "The sum of all odd numbers is " << oddnumbersum << "." << endl;
	cout << "The count of all odd numbers is " << oddnumbercount << "." << endl;
}