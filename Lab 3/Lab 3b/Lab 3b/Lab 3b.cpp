// Lab 3b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, b, c;
	cout << "Enter 3 integers: ";
	cin >> a >> b >> c;

	enum type {tri, equi, isos, notTri} triType;

	if (a <= 0 || b <= 0 || c <= 0 || a+b<=c || b+c<=a || a+c<=b) {
		triType = notTri;
	}
	else if (a == b || b == c || a == c) {
		triType = isos;

		if (a == b && b == c)
			triType = equi;
	}
	else {
		triType = tri;
	}

	switch (triType) {
	case equi:
		cout << "(" << a << ", " << b << ", " << c << ") " << "is an equilateral triangle" << endl;
	case isos:
		cout << "(" << a << ", " << b << ", " << c << ") " << "is an isosceles triangle" << endl;
	case tri:
		cout << "(" << a << ", " << b << ", " << c << ") " << "is a triangle" << endl;
		break;
	default:
		cout << "(" << a << ", " << b << ", " << c << ") " << "is not a triangle" << endl;
	}


    return 0;
}

