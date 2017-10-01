#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(const string &str, const string &delim);

int main() {
	vector<int> aBag;
	vector<int> bBag;
	string input = "";
	string output;
	getline(cin, input);
	vector<string> splitInput = split(input, " ");

	for (unsigned int i = 0; i < splitInput.size(); i++) {
		if (splitInput[i] == "a") {
			aBag.push_back(stoi(splitInput[i + 1]));
		}
		if (splitInput[i] == "b") {
			bBag.push_back(stoi(splitInput[i + 1]));
		}
	}

	sort(aBag.begin(), aBag.end());
	sort(bBag.begin(), bBag.end());

	for (unsigned int i = 0; i < aBag.size(); i++) {
		output += to_string(aBag[i]);
		output += " ";
	}
	for (unsigned int i = 0; i < bBag.size(); i++) {
		output += to_string(bBag[i]);
		output += " ";
	}
	
	cout << output << endl;
	return 0;
}


vector<string> split(const string &str, const string &delim)
{
	const auto delim_pos = str.find(delim);

	if (delim_pos == string::npos)
		return { str };

	vector<string> ret{ str.substr(0, delim_pos) };
	auto tail = split(str.substr(delim_pos + delim.size(), string::npos), delim);

	ret.insert(ret.end(), tail.begin(), tail.end());

	return ret;
}
