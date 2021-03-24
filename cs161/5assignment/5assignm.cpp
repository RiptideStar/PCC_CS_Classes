//Mersenne Primes -- Assignment 5
//By: Kyle Zhang
//7/26/19
//Sources: None

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

long power2min1(long n);
bool isPrime(long testvalue);

int main() {
	long n;
	bool prime;

	cout << "Here is the Mersenne Primes by Kyle Zhang" << endl;
	cout << setw(2) << "n" << setw(14) << "Mersenne Prime" << endl;
	cout << endl;
	for (n = 1; n != 100; n++) {			//Test values up to 100 for n
		long mersennevalue;
		mersennevalue = power2min1(n);
		prime = isPrime(mersennevalue);
		if (prime == true) {
			cout << setw(2) << n << setw(14) << mersennevalue << endl;
		}
	}

	char reply;
	cout << "Press any key and 'Enter' to exit... ";
	cin >> reply;
	return 0;
}

long power2min1(long n) {
	long sum = 2;
	long counter = 1;
	while (counter != n) {
		sum = 2 * sum;
		counter++;
	}
	return sum - 1;
}

bool isPrime(long testvalue) {		//To test if prime, just divide by all prime numbers under the sqrt of that number we try to test
	long i = 5;
	if (testvalue == 3 || testvalue == 5 || testvalue == 7) {
		return true;
	}
	else if (testvalue % 2 == 0 || testvalue % 3 == 0) {
		return false;
	}
	while (i * i <= testvalue) {
		if (testvalue % i == 0 || testvalue % (i + 2) == 0) {					//all primes can be represented as 6n +- 1
			return false;
		}
		i = i + 6;
	}
	return true;
}