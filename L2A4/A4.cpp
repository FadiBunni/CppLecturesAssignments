#include <iostream>
#include <string>
#include <cmath>

int main() {
	std::cout << " ";
	double pi = 0;
	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		pi +=std::pow(-1, i) / (2.0 * i + 1);
	}

	std::cout << pi*4 << std::endl;
	return 0;
}