#include <iostream>
#include <iomanip>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include "src/derivative.h"
#include "src/Interval.h"
#include "src/Solver.h"

int main() {
    using boost::math::constants::pi;
    using boost::multiprecision::cpp_dec_float_50;
    Interval *nowy = new Interval(0.0, 1.0);
    Solver *solver = new Solver(*nowy);
    solver->test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}