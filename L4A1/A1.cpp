#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void erase(std::vector<int>& v, int num);
vector<string> split(const string &str, const string &delim);

int main() {
	vector<int> bag;

	string input = "";
	string output = "";
	bool isexit = false;
	getline(cin, input);
	vector<string> splitInput = split(input, " ");

	for (unsigned int i = 0; i < splitInput.size(); i++) {
		if (splitInput[i] == "add") {
			bag.push_back(stoi(splitInput[i + 1]));

		}
		else if (splitInput[i] == "del") {
			for (unsigned int j = 0; j < bag.size(); j++) {
				if (stoi(splitInput[i + 1]) == bag[j] && !bag.empty()) {
					erase(bag, bag[j]);
				}
			}
		}
		else if (splitInput[i] == "qry") {
			if (!bag.empty()) {
				if (find(bag.begin(), bag.end(), stoi(splitInput[i + 1])) != bag.end())
					output += "T";
				else
					output += "F";
			}
			else {
				output += "F";
			}
		}
		else if (splitInput[i] == "quit") {
			isexit = true;
		}
	}
	cout << output << endl;
	if (isexit)
		exit(0);
	return 0;
}

void erase(std::vector<int>& v, int num) {
	vector<int>::iterator it = remove(v.begin(), v.end(), num);
	v.erase(it, v.end());
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