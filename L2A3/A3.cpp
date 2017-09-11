#include <iostream>
#include <string>

int main() {
	std::cout << " ";
	int num;
	std::cin >> num;

	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			num /= i;
			std::cout << i;
			if (num >= i) {
				std::cout << " * ";
			}
		}
	}
	std::cout << std::endl;
	return 0;
}