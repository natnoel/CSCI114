// Lab 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const int NUM_OF_ASSIGNMENTS = 3;

int main()
{
	cout << "Welcome to UOW Assessment System" << endl << endl;

	char amend;

	do {

		// Setting marks and weights
		float assn[NUM_OF_ASSIGNMENTS] = {}, wt[NUM_OF_ASSIGNMENTS] = {};
		for (int i = 1; i <= 3; i++) {
			cout << "Enter Assignment " << i << " and its weight (%): ";
			//cout << endl <<setprecision(0)<< a[i - 1] << '\t' << b[i - 1] << endl;
			cin >> assn[i - 1];
			cin >> wt[i - 1];
			//cin.clear();
			cin.ignore(256, '\n');
			//cout << endl <<fixed<<setprecision(2)<< a[i - 1] << '\t' << b[i - 1] << endl;
		}

		// Table header
		cout << endl << left// or setiosflags(ios::left)
			<< "Your Performance" << endl
			<< "================" << endl << endl
			<< setw(15) << "Title" << setw(7) << "Marks" << setw(8) << "Weight" << "Result" << endl
			<< setfill('-') << setw(37) << "" << endl;

		cout << setfill(' ');

		// Table details
		float final = 0;

		for (int i = 0; i < NUM_OF_ASSIGNMENTS; i++) {
			string assnName("Assignment ");
			assnName.append(to_string(i + 1));

			stringstream ss;
			ss << "Assignment " << i + 1;

			float result;

			cout << setw(15) << ss.str()//<< "Assignment 1" //<< i + 1
				<< fixed << setprecision(2)
				<< setw(7) << assn[i]
				<< setw(8) << setprecision(0) << wt[i]
				<< setprecision(2) << (result = assn[i] / 100 * wt[i]) << endl;

			final += result;
		}

		// Final result
		cout << setfill('-') << setw(37) << "" << endl
			<< setfill(' ')
			<< setw(15) << "Final"
			<< setw(7) << "***"
			<< setw(8) << "***"
			<< setprecision(1) << final << endl;

		
		cout << endl << "Do you want to amend? (Yy/Nn): ";
		cin >> amend;
		amend = toupper(amend);

	} while (amend == 'Y');

	//float f = 3.45678;

	//cout << fixed<<setprecision(2) << f;

	//string str("a string");
	//cout << str << endl;
    return 0;
}

