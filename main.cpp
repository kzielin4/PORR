#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include "src/Interval.h"
#include "src/Solver.h"


int main() {
    using boost::math::constants::pi;
    using boost::multiprecision::cpp_dec_float_50;
    int startTime = clock();

    int intervalA = 0;
    int intervalB = 13;

    int L = ceil(dfun4(intervalB));
    std::cout << "L: " << L << std::endl;
    Interval *nowy = new Interval(intervalA, intervalB, &dfun1, &fun1, 0.4361815256016513);
    Solver *solver = new Solver(*nowy, &dfun1, &fun1);
    solver->test();

    int duration = clock() - startTime;
    std::cout << "Czas trwania: " << duration << "[ms] " << std::endl;
    return 0;
}