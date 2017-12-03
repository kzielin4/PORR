#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include "src/Interval.h"
#include "src/Solver.h"


int main() {
    using boost::math::constants::pi;
    using boost::multiprecision::cpp_dec_float_50;
    int startTime = clock();

    int intervalA = -10;
    int intervalB = 15;

    int L = ceil(dfun4(intervalB));
    std::cout << "L: " << L << std::endl;
    Interval *nowy = new Interval(intervalA, intervalB, &dfun4, &fun4, 3.04);
    Solver *solver = new Solver(*nowy, &dfun4, &fun4);
    solver->test();

    int duration = clock() - startTime;
    std::cout << "Czas trwania: " << duration << "[ms] " << std::endl;
    return 0;
}