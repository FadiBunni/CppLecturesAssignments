#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void erase(std::vector<double>& v, double num);
vector<string> split(const string &str, const string &delim);

int main() {
	vector<double> bag;
	string input = "";
	string output = "";
	bool isexit = false;
	getline(cin, input);
	vector<string> splitInput = split(input, " ");

	for (unsigned int i = 0; i < splitInput.size(); i++) {
		if (splitInput[i] == "add") {
			bag.push_back(atof(splitInput[i + 1].c_str()));
		}
		else if (splitInput[i] == "del") {
			for (unsigned int j = 0; j < bag.size(); j++) {
				if (atof(splitInput[i + 1].c_str()) == bag[j] && !bag.empty()) {
					erase(bag, bag[j]);
				}
			}
		}
		else if (splitInput[i] == "qry") {
			if (!bag.empty()) {
				if (find(bag.begin(), bag.end(), atof(splitInput[i + 1].c_str())) != bag.end())
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
	// This code is need here so that the printing is executed before the exit(0) sytem function.
	if (isexit)
		exit(0);
	return 0;
}

// find the first occurrence of the element ing bag and delete it.
void erase(vector<double>& v, double num) {
	auto it = find(v.begin(), v.end(), num);
	if (it != v.end()) {
		iter_swap(it, v.end() - 1);
		v.erase(v.end() - 1);
	}
}

//split input after each " "(empty space) and return a vectur of all the words as strings.
//this way the stringified words can be turned to either a int or double, 
// makes it easier to solve assignment 2 and 3, smart huh?.
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