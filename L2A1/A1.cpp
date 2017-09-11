#include <iostream>
#include <string>

int main() {
	int x;

	std::cin >> x;
	
	x = x*(x + 1) / 2;

	std::cout << x;

	return 0;
}