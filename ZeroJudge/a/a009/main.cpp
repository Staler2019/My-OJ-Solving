#include <iostream>
#include <string>

int main() {
    std::string in;
    std::cin >> in;
    for(auto &i:in)
        std::cout << (char)(i - 7);
}