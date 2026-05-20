#include <iostream>
#include <math.h>

#define WITH_REF 0

#if WITH_REF 
void squareN(int& n)
#else 
void squareN(int n)
#endif
{
    n = std::pow(n, 2);
}

int main() {
    int num {5};
    std::cout << "(1) num is: " << num << "\n";
    squareN(num);
    std::cout << "(2) num is: " << num << "\n";
    return 0;
}