#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getLowerBound(const vector<int> &vect, const int &val) {
	int left = 0, right = vect.size();

	while (left < right) {
		int mid = (left + right) / 2;
		cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
		if (vect[mid] < val) {
			// All we need is on the right side (>= val)
			left = mid + 1;
			cout << "new left: " << left << endl;
		}
		else {
			// vect[mid] >= val
			right = mid;	// Inclusive of mid
			cout << "new right: " << right << endl;
		}
	}

	return left;
}

vector<int>::const_iterator getLowerBoundIterator(const vector<int> &v, const int &val) {
	vector<int>::const_iterator it = v.begin();
	int count = distance(v.begin(), v.end());

	//for (it = vect.begin(); it != vect.end(); it++)
	//	cout << *it << ' ';

	while (count > 0) {
		int step = count / 2;
		advance(it, step);

		if (*it < val) {
			//Everthing is on the right hand side (excluding middle)
			it++;
			count -= step + 1;
		}
		else
		{
			// Everthing is on the left hand side (including middle)
			count = step;
		}
	}

	return it;
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

	//cout << "Distance: " << distance(vect.begin(), vect.end()) << endl;
	//getLowerBound_IteratorMethod(vect, 0);

	int Q;	// Number of queries
	cin >> Q;

	while (Q--) {
		int Y;	// Number to search for
		cin >> Y;
		cout << "lower bound is (own method): " << getLowerBound(vect, Y) << endl;
		cout << "lower bound is: " << lower_bound(vect.begin(), vect.end(), Y) - vect.begin() << endl;
	}

	return 0;
}