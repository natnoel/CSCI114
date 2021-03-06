// Lab 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isValidInt(int);

int main()
{
	int n;
	do {
		cout << "Enter an integer: ";
		cin >> n;
	} while (!isValidInt(n));

	while (n > 0) {
		int digit = n % 10;

		for (int i = 1; i <= digit; i++) {
			for (int k = 0; k < i; k++) {
				cout << "  ";
			}
			for (int j = 1; j <= digit; j++) {
				cout << j;
			}
			cout << endl;
		}
		n /= 10;
	}

    return 0;
}

bool isValidInt(int n) {
	while (n > 0) {
		//cout << "n is " << n << endl;
		//cout << "last digit is " << n % 10 << endl;
		int lastDigit = n % 10;
		if (!lastDigit || lastDigit == 1) {
			//cout << "found digit " << n % 10 << endl;
			return false;
		}

		n /= 10;
	}

	return true;
}
