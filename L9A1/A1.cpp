#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string &str, const string &delim);
vector<int> reverse(vector<int> v);

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

	vector<int> v = reverse(arr);

	for (int i = 0; i < v.size(); i++) {
		output += to_string(v[i]);
		output += " ";
	}

	cout << output << endl;
	return 0;
}

vector<int> reverse(vector<int> v) {
	reverse(v.begin(), v.end());
	return v;
}