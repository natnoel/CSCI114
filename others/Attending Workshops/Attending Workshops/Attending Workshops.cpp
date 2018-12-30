//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
#include <vector>

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
	int start, end, duration;
};

struct Available_Workshops {
	int n;
	vector<Workshop> w;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
	Available_Workshops *p = new Available_Workshops;
	p->n = n;
	for (int i = 0; i < n; i++) {
		Workshop ws;
		ws.start = start_time[i];
		ws.duration = duration[i];
		ws.end = start_time[i] + duration[i];
		p->w.push_back(ws);
	}

	return p;
}

int maxWorkShops(vector<Workshop> w, int count = 0) {
	if (w.empty())
		return count;
	else {
		int maxCount = count;
		for (vector<Workshop>::iterator it = w.begin(); it != w.end(); it++) {    //For each starting/next chosen workshop
			cout << "Choosing " << it->start << ',' << it->end << endl;
			vector<Workshop> nw;

			/*int pos = 0;
			//Removed those that cannot attend (including the current chosen one)
			for (vector<Workshop>::iterator itn = nw.begin(); itn != nw.end(); itn++) {
				cout << "Entered inner loop\n";
				cout << "Checking " << itn->start;
				cout << " with " << it->end << endl;
				if (itn != nw.end() && itn->start < it->end) {
					cout << "Erasing " << itn->start << endl;
					//vector<Workshop>::iterator itDel = itn;
					nw.erase(nw.begin() + pos);
					//cout << "Removing " << itn->start << ',' << itn->end << endl;
				}
				else
					pos++;
				cout << "checking next ws\n";
			}*/

			cout << "Next vect is now: ";
			for (int i = 0; i < w.size(); i++) {
				if (w[i].start >= it->end) {
					nw.push_back(w[i]);
					cout << w[i].start << ',' << w[i].end << ' ';
				}
			}
			cout << endl;

			int newCount = maxWorkShops(nw, count + 1);
			if (newCount > maxCount)
				maxCount = newCount;
		}
		return maxCount;
	}
	return -1;
}

int CalculateMaxWorkshops(Available_Workshops* aw) {
	/*vector<int> v = { 1,2,3,4,5,6,7,8 };
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		if (*it % 2)
			v.erase(it);
		cout << *it << ' ';
	}*/
	return maxWorkShops(aw->w, 0);
}

int main(int argc, char *argv[]) {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}
