//Midterm Programming -- Sum of Even and Odd Separate Calculator
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
	const int sentinel = -999;
	int oddnumbersum = 0;
	int evennumbersum = 0;
	int oddnumbercount = 0;
	int evennumbercount = 0;

	cout << "Welcome to Kyle's calculator which calculates sum of even and odd numbers separately that you will wish to input. " << endl;
	cout << "Note: When you are done entering your numbers, type -999." << endl;
	cout << "Another Note: Negative numbers will be ignored! " << endl;
	cout << "Enter a number: ";			//Enter the first number
	cin >> number;
	while (number != sentinel) { //Condition to exit loop is to enter -999. Otherwise, stay in loop and crunch numbers and get another number
		if (number >= 0) {	//If positive number, we will start crunching it
			//If odd number
			if (number % 2 == 1) {
				oddnumbersum = oddnumbersum + number;			//Add to sum
				oddnumbercount++;								//Add the count 
			}
			//If even number
			if (number % 2 == 0) {
				evennumbersum = evennumbersum + number;			//Add to sum
				evennumbercount++;								//Add to count
			}
		}
		else {
			cout << "This is a negative number, it will be ignored. " << endl;		//You didn't enter a positive number, it will be ignored
		}

		cout << "Enter another number: ";
		cin >> number;										//After entering a number that isn't -999, enter another number. Previous number will be stored and added into sum (assuming not ignored)
	}
	cout << "The sum of all even numbers is " << evennumbersum << "." << endl;			//After user enters -999, escape the while loop and output the sum and counts of the even and odds
	cout << "The count of all even numbers is " << evennumbercount << "." << endl;
	cout << "The sum of all odd numbers is " << oddnumbersum << "." << endl;
	cout << "The count of all odd numbers is " << oddnumbercount << "." << endl;

	char reply;											//Ending program
	cout << "Press any key to quit... ";
	cin >> reply;
	return 0;
}