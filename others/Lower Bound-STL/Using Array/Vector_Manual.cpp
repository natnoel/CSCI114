#include <iostream>
#include <vector>
using namespace std;

int getLowerBound(const vector<int> &vect, const int &val) {
	int left = 0, right = vect.size() - 1, mid = 0;

	while (left < right) {
		mid = (left + right) / 2;
		cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
		if (vect[mid] < val) {
			// All we need is on the right side (>= val)
			left = mid + 1;
		}
		else {
			// vect[mid] >= val
			right = mid;	// Inclusive of mid
		}
		cout << "new mid: " << mid << endl;
	}

	return mid;
}

int main() {
	int N;	// Number of integers
	vector<int> vect;
	cin >> N;

	while (N--) {
		int num;
		cin >> num;
		vect.push_back(num);
		//cout << num << ' ';
	}

	int Q;	// Number of queries
	cin >> Q;

	while (Q--) {
		int Y;	// Number to search for
		cin >> Y;
		cout << getLowerBound(vect, Y) << endl;
	}

	return 0;
}