#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(const string &str, const string &delim);
int scalar_product(vector<int> a, vector<int> b);

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
	if (aBag.size() < bBag.size()) {
		aBag.push_back(0);
	}
	if (bBag.size() < aBag.size()) {
		bBag.push_back(0);
	}

	cout << scalar_product(aBag,bBag) << endl;

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

int scalar_product(vector<int> a, vector<int> b)
{
	//In C++, you should declare every variable before you use it. So, you declare product and initialize it to 0.
	int product = 0;
	//Here you check whether the two vectors are of equal size. If they are not then the vectors cannot be multiplied for scalar product.
	if (a.size() != b.size()) {
		cout << "Vectors are not of the same size and hence the scalar product cannot be calculated" << endl;
		return -1;  //Note: This -1 is not the answer, but just a number indicating that the product is not possible. Some pair of vectors might actually have a -1, but in that case you will not see the error above.
	}

	//you loop through the vectors. As bobo also pointed you do not need two loops.
	for (int i = 0; i < a.size(); i++) {
		product = product + a[i] * b[i];
	}

	//finally you return the product
	return product;
}
