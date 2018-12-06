#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, b, c;
	cout << "Lab 3b" << endl;
	cout << "Enter three integers: ";
	cin >> a >> b >> c;

	cout << "(" << a << ", " << b << ", " << c << ") is ";
	if (a <= 0 || b <= 0 || c <= 0 || (!(a + b > c && b + c > a && a + c > b))) {
		cout << "not ";
	}
	else {
		if (a == b && b == c)
			cout << " an equilateral triangle" << endl << "(" << a << ", " << b << ", " << c << ") is ";
		if (a == b || b == c || a == c)
			cout << " an isosceles triangle" << endl << "(" << a << ", " << b << ", " << c << ") is ";;
	}

	cout << "a triangle" << endl;

	return 0;
}

