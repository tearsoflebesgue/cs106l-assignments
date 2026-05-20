#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;
    ss << 3.14f << ' ' << "hello";

    float pi; 
    std::string hi;
    ss >> pi >> hi;

    std::cout << pi << '\n' << hi << '\n';
}