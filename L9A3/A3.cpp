#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool palindrome_2(vector<int>&vec, int begin, int end);

int main() {
	vector<int> bag;
	string input = "";
	string output = "";
	getline(cin, input);
	stringstream stream(input);
	vector<int> arr;
	bool isPalindrome;

	while (1) {
		int n;
		stream >> n;
		if (!stream)
			break;
		arr.push_back(n);
	}

	bool result = palindrome_2(arr, 0, arr.size() - 1);
	if (result == false) {
		cout << "no" << endl;
	}
	else if (result == true) {
		cout << "yes" << endl;
	}

	return 0;
}

bool palindrome_2(vector<int>&vec, int begin, int end) {

	if (begin >= end) {
		//cout << "returning true..."<<endl;
		return true;

	}


	if (vec[begin] != vec[end]) {
		//cout << vec[begin] << " and " << vec[end] <<endl;
		//cout << " returning false..."<<endl;
		return false;
	}

	return palindrome_2(vec, begin + 1, end - 1);
}