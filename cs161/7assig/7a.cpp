//DeleteItem
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//constants
const int CAP = 100;

//function prototypes
bool openFile(ifstream&);
void readData(ifstream&, int[], int&);
void printData(const int[], int);
void deleteItem(int[], int&, int);




int main()
{
	ifstream inFile;
	int list[CAP], size = 0;

	if (!openFile(inFile))
	{
		cout << "Program terminating!! File not found!" << endl;
		return -1;
	}
	//read the data from the file
	readData(inFile, list, size);
	inFile.close();
	cout << "Data in file:" << endl;
	printData(list, size);
	//delete a few items
	deleteItem(list, size, 20);
	deleteItem(list, size, 210);
	deleteItem(list, size, 110);
	deleteItem(list, size, 220);
	cout << "New Data: " << endl;						//This is where the new data (with the deletes) begin.
	printData(list, size);
	//end program
	cin.ignore(100, '\n');
	cout << "Press any key to continue...";
	getchar();

	return 0;
}

//function to open file
bool openFile(ifstream& inFile)
{							  
	inFile.open("numbers.txt");		
	if (!inFile)
	{
		return false;
	}
	return true;
}

//reads the data from the file
void readData(ifstream& inFile, int list[], int& size)
{
	while (!inFile.eof())
	{
		inFile >> list[size++];
	}
}

//print the contents of the array
void printData(const int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
	cout << endl;
}


void deleteItem(int list[], int& size, int num) {
	
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (list[i] == num) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << num << " was not found in the file." << endl;
		return;
	}
	

	if (index >= 0 && index < size) {
		for (int j = index; j < size; j++) {
			list[j] = list[j + 1];
		}
		size--;
	}
	
}
