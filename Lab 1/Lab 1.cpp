// Lab 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

int main()
{
	int num, div;
	cout << "Hello World!" << endl;
	cout << "Enter a number: ";
	cin >> num;
	cout << "Enter a divisor: ";
	cin >> div;
	cout << endl;
	cout << "Number\t\tDivisor\t\tQuotient\tRemainder" << endl;
	do {
		cout << num << "\t\t" << div << "\t\t" << num / div << "\t\t" << num % div << endl;
		num /= div;
	} while (num > 0);
    return 0;
}

