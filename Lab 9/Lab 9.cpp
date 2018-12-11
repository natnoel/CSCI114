#include <iostream>
#include <fstream>

using namespace std;

const char *infileName = "infile.txt";
const char outfileName[] = "outfile.txt";

enum NumType { even, odd };
struct Number
{
	int no;
	NumType type;
	int oddDigits;
	int evenDigits;
	int sumDigits;
	int noDigits;
};

int createInfile(const char[]);
void readInfile(const char*, const int&, Number*&);
void processArray(Number[], const int&);
void arrayToOutfile(const char[], Number[], const int&);

int main() {
	cout << "Lab 9" << endl;
	/*ifstream infile("infile.txt");
	if (infile.is_open()) {
		int n;
		infile >> n;
		infile.close();
	}*/

	int noOfInts = createInfile(infileName);
	Number *numbers = NULL;
	readInfile(infileName, noOfInts, numbers);
	processArray(numbers, noOfInts);
	arrayToOutfile(outfileName, numbers, noOfInts);

	return 0;
}

int createInfile(const char infileName[]) {
	ofstream outfile(infileName);
	if (outfile.is_open()) {
		int numOfInts = rand() % 100;
		int num;
		for (int i = 1; i <= numOfInts; i++) {
			num = rand() % 100000;
			outfile << num << "\t// Number " << i << endl;
		}
		outfile.close();
		cout << "Created infile.txt!" << endl;
		return numOfInts;
	}
	else {
		cout << "Cannot create infile.txt" << endl;
	}

	return -1;
}

void readInfile(const char* infileName, const int& numOfInts, Number* &numbers) {
	ifstream infile(infileName);
	if (infile.is_open()) {
		numbers = new Number[numOfInts];
		int i = 0;
		while (infile >> numbers[i].no) {
			infile.ignore(100, '\n');
			cout << numbers[i].no << endl;
			i++;
		}
		infile.close();
	}
	else {
		cout << "Cannot open " << infileName << endl;
	}
}

void processArray(Number num[], const int& noOfInts) {
	cout << "Entering loop\n";
	if (num == NULL) {
		cout << "NULL\n";
		return;
	}
	for (int i = 0; i < noOfInts; i++) {
		num[i].type = static_cast<NumType>(num[i].no % 2);
		//cout << num[i].no << " is " << (num[i].type == even ? "even" : "odd") << endl;
		num[i].evenDigits = 0, num[i].oddDigits = 0, num[i].sumDigits = 0, num[i].noDigits = 0;
		int n = num[i].no;
		while (n > 0) {
			int digit = n % 10;
			if (digit % 2)
				num[i].oddDigits++;
			else
				num[i].evenDigits++;
			num[i].sumDigits += digit;
			num[i].noDigits++;

			n /= 10;
		}
	}
}

void arrayToOutfile(const char outfileName[], Number num[], const int& noOfInts) {
	ofstream outfile(outfileName);
	if (outfile.is_open()) {
		outfile << "No\tType\tOdd\tEven\tSum\tDigits" << endl;
		for (int i = 0; i < noOfInts; i++) {
			outfile << num[i].no << '\t' << (num[i].type ? "Odd" : "Even") << '\t' << num[i].oddDigits << '\t' << num[i].evenDigits << '\t' << num[i].sumDigits << '\t' << num[i].noDigits << endl;
		}
		outfile.close();
	}
	else
		cout << "Cannot open " << outfileName << " for writing" << endl;
}