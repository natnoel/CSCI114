#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void generateInt(int&, int&);
void compliment(void);
void encourage(void);

int main() {
	srand (time(NULL));
	cout << "Welcome to Arithmetic Learning System" << endl;
	int a, b;
	do {
		generateInt(a, b);
		int ans;
		do {
			cout << "What is " << a << " + " << b << "?" << endl;
			cin >> ans;

			if (a > 0 && b > 0) {
				if (ans == a + b)
					compliment();
				else
					encourage();

				cout << endl;
			}
		} while (a > 0 && b > 0 && ans != a + b);

	} while (a > 0 && b > 0);

	cout << "Hope you have enjoyed your learning :)" << endl;

	return 0;
}

void generateInt(int& a, int& b) {
	a = rand() % 10;
	b = rand() % 10;
}

void compliment() {
	static int count = 0;

	if (count % 2)
		cout << "Congratulations";
	else
		cout << "Well done!";

	cout << endl;

	count++;
}

void encourage(void) {
	static int count = 0;

	if (count % 2)
		cout << "Wrong answer, keep it up";
	else
		cout << "Please try again";

	cout << endl;

	count++;
}