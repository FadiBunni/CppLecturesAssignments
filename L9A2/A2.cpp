#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int fib(int n);

int main() {
	vector<int> bag;
	string input = "";
	string output = "";
	getline(cin, input);
	stringstream stream(input);
	vector<int> arr;

	while (1) {
		int n;
		stream >> n;
		if (!stream)
			break;
		arr.push_back(n);
	}

	for (int i = 0; i < arr.size(); i++) {
		output += to_string(fib(arr[i]));
		output += " ";
	}

	cout << output << endl;
	return 0;
}

int fib(int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}