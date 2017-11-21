#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

	using namespace std;

int editDist(string str1, string str2, int m, int n);
int min(int x, int y, int z);

int main() {
	vector<int> bag;
	string input = "";
	string output = "";
	getline(cin, input);
	stringstream stream(input);
	vector<string> arr;

	while (1) {
		string n;
		stream >> n;
		if (!stream)
			break;
		arr.push_back(n);
	}
	string str1 = arr[0];
	string str2 = arr[1];
	cout << editDist(str1, str2, str1.length(), str2.length());

	return 0;
}

int editDist(string str1, string str2, int m, int n)
{
	// If first string is empty, the only option is to
	// insert all characters of second string into first
	if (m == 0) return n;

	// If second string is empty, the only option is to
	// remove all characters of first string
	if (n == 0) return m;

	// If last characters of two strings are same, nothing
	// much to do. Ignore last characters and get count for
	// remaining strings.
	if (str1[m - 1] == str2[n - 1])
		return editDist(str1, str2, m - 1, n - 1);

	// If last characters are not same, consider all three
	// operations on last character of first string, recursively
	// compute minimum cost for all three operations and take
	// minimum of three values.
	return 1 + min(editDist(str1, str2, m, n - 1),    // Insert
		editDist(str1, str2, m - 1, n),   // Remove
		editDist(str1, str2, m - 1, n - 1) // Replace
	);
}

int min(int x, int y, int z) {
	return min(min(x, y), z);
}