#include <iostream>
#include <string>

int main() {
std::string name = "";

std::getline(std::cin, name);

std::cout << "Hello " << name << "!";

return 0;
}