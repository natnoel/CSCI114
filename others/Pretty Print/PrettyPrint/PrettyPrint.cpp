#include <iostream>
#include <iomanip> 
#include <fstream>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	ofstream file("output");
	file << setiosflags(ios::uppercase);
	file << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
		cout << setw(0) << "0x" <<hex << nouppercase << (int)A << endl;

		/*int mantissa = B, noOfDigits = 0;
		while (mantissa > 0) {
			mantissa /= 10;
			noOfDigits++;
		}
		int spaces = noOfDigits + 3;

		cout << setprecision(2) << fixed << setw(15 - spaces) << setfill('_') << (B < 0 ? "-" : "+") << B << endl;*/
		cout << setprecision(2) << fixed << showpos << right << setw(15) << setfill('_') << B << endl;

		cout << setw(0) << setprecision(9) << scientific << noshowpos << setfill(' ') << C << endl;

		file << setw(0) << "0x" << std::hex << nouppercase << (int)A << endl;
		file << setprecision(2) << fixed << showpos << right << setw(15) << setfill('_') << B << endl;
		file << setw(0) << setprecision(9) << scientific << uppercase << noshowpos << setfill(' ') << C << endl;
	}
	return 0;

}