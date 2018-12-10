#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int generateInt(const int&);
void printALine(const int&, const int&);
void printATriangle(const int&, const int&);
void printAllTriangles(const int&);

void main() {
	srand(time(NULL));

	int num;
	cout << "Triangles for " << (num = generateInt(5)) << " are" << endl << endl;
	//cout << rand() % 1 << endl;
	//cout << "end\n";
	//printATriangle(7, 6);
	printAllTriangles(num);
	return;
}

int generateInt(const int& numOfDigits) {
	int exp = 1;
	for (int i = 0; i < numOfDigits; i++)
		exp *= 10;

	int num = rand() % exp;

	return num;
}

void printALine(const int& digit, const int& times) {
	if (times > 0) {
		cout << digit;
		printALine(digit, times - 1);
	}
	else
		cout << endl;
}

void printATriangle(const int& digit, const int& times) {
	if (times > 0) {
		printALine(digit, times);
		printATriangle(digit, times - 1);
	}
}

void printAllTriangles(const int& num) {
	if (num > 0) {
		int digit = num % 10;
		printATriangle(digit, digit);
		printAllTriangles(num / 10);
	}
}