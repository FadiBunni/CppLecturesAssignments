#include<iostream>
#include<math.h>

using namespace std;

//int findmax(int data[], int n) {
//	int max = data[0];
//	for (int i = 0; i<n; i++)
//		if (max<data[i]) max = data[i];
//	return max;
//}

int main() {

	int n;
	int l;
	int k;
	cin >> l;
	cin >> n;
	int* interval = new int[l];
	int* data = new int[n];
	fill_n(interval, l, 0);

	int highest = 0;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
		if (highest < data[i])
			highest = data[i];
	}

	k = ceil((double)highest/(double)l);

	for (int i = 0; i < n; i++) {
		interval[data[i] / k]++;
	}

	for (int i = 0; i < l; i++) {
		cout << i*k << ": " << interval[i] << endl;
	}

	return 0;
}