#include <iostream>
#include <string>
#include <vector>
#include "Fraction.h"

using namespace std;

vector<string> split(const string &str, const string &delim);

int main() {
	string input = "";
	while (true) {
		getline(cin, input);
		vector<string> splitInput = split(input, " ");
		Fraction F1;
		Fraction F2;
		int count = 0;
		for (int i = 0; i < splitInput.size(); i++) {
			if (count == 1 && splitInput[i] == "/") {
				F2.setNum(stoi(splitInput[i - 1]));
				F2.setDenom(stoi(splitInput[i + 1]));
			}
			if (count != 1 && splitInput[i] == "/") {
				F1.setNum(stoi(splitInput[i - 1]));
				F1.setDenom(stoi(splitInput[i + 1]));
				count++;
			}
		}
		for (int i = 0; i < splitInput.size(); i++) {
			if (splitInput[i] == "+") {
				F1.add(F2);
				F1.display();
			}
			else if (splitInput[i] == "*") {
				F1.mult(F2);
				F1.display();
			}
			else if (splitInput[i] == "div") {
				F1.div(F2);
				F1.display();
			}
		}
		if (cin.fail()) break;
	}
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