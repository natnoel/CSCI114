#include <iostream>
#include <time.h>
//#include <random>

using namespace std;

const int MIN_INT = 97;
const int MAX_INT = 122;

int constructArray(char*&);
bool isVowel(char);
void printArray(const char*, const int&);
void swap(char&, char&);
void sortVowels(char*&, const int&);
void sortVowelsR(char*&, int, int);

void main() {
	srand(time(NULL));
	cout << "Lab 8" << endl;

	char *arr = NULL;
	int size;
	cout << "Given the following array of size " << (size = constructArray(arr)) << endl;
	if (arr != NULL)
		printArray(arr, size);
	else
		cout << "array is null\n";
	/*int a = 3, b = 6;
	swap(a, b);
	cout << a << ' ' << b << endl;*/
	sortVowels(arr, size);

	cout << endl << "Iterative swap of array" << endl;
	printArray(arr, size);

	cout << endl << "Given the following array of size " << (size = constructArray(arr)) << endl;
	printArray(arr, size);
	cout << endl << "Recursive swap of array" << endl;
	sortVowelsR(arr, 0, size - 1);
	printArray(arr, size);

	return;
}

int constructArray(char* &arr)
{
	int size = rand() % (30 - 20 + 1) + 20;

	arr = new char[size];

	for (int i = 0; i < size; i++)
		arr[i] = rand() % (MAX_INT - MIN_INT + 1) + MIN_INT;

	return size;
}

bool isVowel(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}

void printArray(const char* arr, const int &size) {
	//cout << "Size is " << size << endl;
	//cout << "Printing.." << endl;
	//cout << arr[1] << endl;
	for (int i = 0; i < size; i++)
		cout << ' ' << arr[i];
	cout << endl;
}

void sortVowels(char *&arr, const int &size)
{
	/*
	int a = 2, b = 8;
	swap(a, b);
	cout << a << ' ' << b << endl;*/
	int left = 0, right = size - 1;

	do {
		//Find a consonant
		while (left < size && isVowel(arr[left]))
			left++;
		//Find a vowel
		while (right >= 0 && !isVowel(arr[right]))
			right--;

		if (left < right)
			swap(arr[left], arr[right]);

	} while (left < right);
}

void swap(char& a, char& b) {
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}

void sortVowelsR(char*& arr, int left, int right) {
	if (left < right) {
		if (isVowel(arr[left]))
			sortVowelsR(arr, ++left, right);
		else if (!isVowel(arr[right]))
			sortVowelsR(arr, left, --right);
		else {
			swap(arr[left], arr[right]);
			sortVowelsR(arr, ++left, --right);
		}
	}
}