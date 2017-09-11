#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sum += i;
		}
		
	}

	std::cout << "EvenSum = " << sum << std::endl;

	return 0;
}