#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k) {
	//Write your code here.
	int maxIdx = -1;
	for (int i = 0; i <= n - k; i++) {  //For each subarray
		if (i <= maxIdx && maxIdx < i + k) {  //Previous max idx still within range
			if (arr[maxIdx] < arr[i + k - 1])   //Compare only the new element
				maxIdx = i + k - 1;
		}
		else {
			//Find the new max
			maxIdx = i;
			for (int j = i + 1; j < i + k; j++) {
				if (arr[j] > arr[maxIdx])
					maxIdx = j;
			}
		}
		cout << arr[maxIdx] << ' ';
	}
	cout << endl;
}

int main() {

	int t;
	cin >> t;
	while (t>0) {
		int n, k;
		cin >> n >> k;
		int i;
		int *arr = new int[n];
		for (i = 0; i<n; i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}

