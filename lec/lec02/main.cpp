#include <iostream>
#include <utility>

#include <cmath>

using Zeros = std::pair<double, double>;
using Solution = std::pair<bool, Zeros>;

Solution solveQuadratic(double a, double b, double c) {
    double discrim = b * b - 4 * a * c;
    if (discrim < 0) {
        return {false, {0, 0}};
    }

    double root = sqrt(discrim);
    return {true, {(-b - root) / (2 * a), (-b + root) / (2 * a)}};
}