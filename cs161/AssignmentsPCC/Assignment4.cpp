//Advertising Survey -- Assignment 4
//By: Kyle Zhang
//7/20/19
//Sources: None

#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string>

using namespace std;

int main() {
	string reply;
	string personname;
	string surveyyn;
	int age;
	double score;
	double scorey18 = 0;
	double amounty18 = 0;
	double scorey35 = 0;
	double amounty35 = 0;
	double scoreyold = 0;
	double amountyold = 0;
	double scoren18 = 0;
	double amountn18 = 0;
	double scoren35 = 0;
	double amountn35 = 0;
	double scorenold = 0;
	double amountnold = 0;
	double avgscorey18;
	double avgscoren18;
	double avgscorey35;
	double avgscoren35;
	double avgscoreyold;
	double avgscorenold;

	string inputFilename;
	ifstream inputFile;

	cout << "Input file name: ";
	getline(cin, inputFilename);
	inputFile.open(inputFilename.c_str());   //Open up file!
	
	if (!inputFile.is_open()) {
		cout << "Unable to open file" << endl;	//Error if can't open
		cout << "Press enter to continue";
		getline(cin, reply);
		exit(1);
	}
	while (inputFile.peek() != EOF) {		//Not end of file, then receive input
		inputFile >> personname;			//Name
		inputFile >> surveyyn;				//Y or N
		inputFile >> age;					//Age
		inputFile >> score;					//Their Score. We just got input of one line of the data.
		if (surveyyn == "y" || surveyyn == "Y") {		//Time to isolate each person into a group by going through these ifs. Yes to survey, then we add their score into the group.
			if (age < 18) {
				scorey18 = score + scorey18;			//Under 18
				amounty18++;
			}
			else if (age >= 18 && age <= 35) {			//18-35
				scorey35 = score + scorey35;
				amounty35++;
			}
			else {
				scoreyold = score + scoreyold;			//Old (35+)
				amountyold++;
			}
		}
		if (surveyyn == "n" || surveyyn == "N") {       //No to survey, then we add their score into the group.
			if (age < 18) {								//Under 18
				scoren18 = score + scoren18;
				amountn18++;
			}
			else if (age >= 18 && age <= 35) {			//18-35
				scoren35 = score + scoren35;
				amountn35++;
			}
			else {										//Old (35+)
				scorenold = score + scorenold;
				amountnold++;
			}
		}
	}

	cout << fixed << showpoint << setprecision(2);		//2 post-decimal digits
	cout << "Averages of each age group" << endl;
	//Output
	if (amounty18 == 0) {		//For each group, it will check if there were any people in the group, because can't average if divide by zero, so no data to report
		cout << "No data to report for under 18 year olds who have seen the ad." << endl;
	}
	else {
		avgscorey18 = scorey18 / amounty18;
		cout << "The average score for under 18 year olds who have seen the ad is: " << avgscorey18 << endl;
	}
	if (amounty35 == 0) {
		cout << "No data to report for 18-35 year olds who have seen the ad." << endl;
	}
	else {
		avgscorey35 = scorey35 / amounty35;
		cout << "The average score for 18-35 year olds who have seen the ad is: " << avgscorey35 << endl;
	}
	if (amountyold == 0) {
		cout << "No data to report for 35+ year olds who have seen the ad." << endl;
	}
	else {
		avgscoreyold = scoreyold / amountyold;
		cout << "The average score for 35+ year olds who have seen the ad is: " << avgscoreyold << endl;
	}
	if (amountn18 == 0) {
		cout << "No data to report for under 18 year olds who haven't seen the ad." << endl;
	}
	else {
		avgscoren18 = scoren18 / amountn18;
		cout << "The average score for under 18 year olds who haven't seen the ad is: " << avgscoren18 << endl;
	}
	if (amountn35 == 0) {
		cout << "No data to report for 18-35 year olds who haven't seen the ad." << endl;
	}
	else {
		avgscoren35 = scoren35 / amountn35;
		cout << "The average score for 18-35 year olds who haven't seen the ad is: " << avgscoren35 << endl;
	}
	if (amountnold == 0) {
		cout << "No data to report for 35+ year olds who haven't seen the ad." << endl;
	}
	else {
		avgscorenold = scorenold / amountnold;
		cout << "The average score for 35+ year olds who haven't seen the ad is: " << avgscorenold << endl;
	}

	char replies;					//Ending
	cout << "Press any key to exit ";
	cin >> replies;
	return 0;

}