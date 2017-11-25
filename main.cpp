#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include "src/Interval.h"
#include "src/Solver.h"


int main() {
    using boost::math::constants::pi;
    using boost::multiprecision::cpp_dec_float_50;
    Interval *nowy = new Interval(-5.0, 20.0,&dfun2, &fun2);
    Solver *solver = new Solver(*nowy, &dfun2, &fun2);
    solver->test();
    return 0;
}