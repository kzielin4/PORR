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
    double (*derivative)(double)= &dfun4;
    double (*function)(double)=&fun4;
    double L = 0.25162;
    std::cout << "L: " << L << std::endl;
    Interval *nowy = new Interval(intervalA, intervalB, derivative, function, L);
    Solver *solver = new Solver(*nowy, derivative, function);
    solver->test();

    int duration = clock() - startTime;
    std::cout << "Czas trwania: " << duration << "[ms] " << std::endl;
    return 0;
}

