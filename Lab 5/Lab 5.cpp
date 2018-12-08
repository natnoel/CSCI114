#include <iostream>
#include <math.h>

using namespace std;

bool isTriangle(const int&, const int&, const int&);
int perimeter(const int& a, const int &b, const int &c) {
	return a + b + c;
}
double area(const int& a, const int &b, const int &c) {
	double s = perimeter(a, b, c) / 2.0;
	return s * (s - a)*(s - b)*(s - c);
}

int main() {

	int a, b, c;

	do {
		cout << "Enter 3 sides: ";
		cin >> a >> b >> c;
		cin.ignore(100, '\n');

		if (a <= 0 || b <= 0 || c <= 0) {

		}
		else if (isTriangle(a, b, c)) {
			cout << "Triangle (" << a << ", " << b << ", " << c << ") ==> "
				<< "Perimeter (" << perimeter(a, b, c) << "), "
				<< "Area (" << area(a, b, c) << ")" << endl;
		}
		else {
			cout << "Not a triangle" << endl;
		}

	} while (a > 0 && b > 0 && c > 0);

	cout << "End of task" << endl;

	return 0;
}

bool isTriangle(const int& a, const int& b, const int& c) {
	if (a + b <= c || b + c <= a || a + c <= b)
		return false;

	return true;
}