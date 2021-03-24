//Mersenne Primes -- Assignment 5
//By: Kyle Zhang
//7/26/19
//Sources: None

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

unsigned long power2min1(long n);
bool isPrime(unsigned long testvalue);

int main() {
	long n;
	bool prime;

	cout << "Here is the Mersenne Primes by Kyle Zhang" << endl;
	cout << setw(2) << "n" << setw(17) << "Mersenne Prime" << endl;		//Formatting
	cout << endl;
	for (n = 1; n != 33; n++) {			//Test values up to 33 for n because unsigned long goes up to 2^32
		unsigned long mersennevalue;
		mersennevalue = power2min1(n);
		prime = isPrime(mersennevalue);
		if (prime == true) {											//Print number tested and the corresponding n if Prime test is True
			cout << setw(2) << n << setw(17) << mersennevalue << endl;
		}
	}

	char reply;											//Wrap up
	cout << "Press any key and 'Enter' to exit... ";
	cin >> reply;
	return 0;
}

unsigned long power2min1(long n) {			//Calculates 2^n-1 for a given n
	unsigned long sum = 2;
	int counter = 1;
	while (counter != n) {					//I keep doubling "n" amount of times
		sum = 2 * sum;
		counter++;
	}
	return sum - 1;							//I have to -1
}

bool isPrime(unsigned long testvalue) {		//To test if prime, just divide by all prime numbers under the sqrt of that number we try to test
	long i = 5;
	if (testvalue == 1) {
		return false;
	}
	if (testvalue == 3 || testvalue == 5 || testvalue == 7) {			//3,5,7 are prime
		return true;
	}
	else if (testvalue % 2 == 0 || testvalue % 3 == 0) {				//If can be divided by 2 and 3, not prime
		return false;
	}
	while (i * i <= testvalue) {										//sqrt of number being tested and all the primes under that divided into the number being tested will give me if prime/not
		if (testvalue % i == 0 || testvalue % (i + 2) == 0) {			//Of course, if it doesn't divide into the number being tested, it is prime		//all primes can be represented as 6n +- 1
			return false;
		}
		i = i + 6;														//6n pretty much. shifting the new prime numbers within the domain
	}

	return true;
}
