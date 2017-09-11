#include <iostream>
#include <string>

int main() {
std::int16_t x;
std::cin >> x;
std::int16_t y;
std::cin >> y;

if (x == y) {
std::cout << x << " is equal to " << y << std::endl;
}
else if (x > y) {
std::cout << x << " is bigger than " << y << std::endl;
}
else if (x < y) {
std::cout << x << " is smaller than " << y << std::endl;
}

return 0;
}