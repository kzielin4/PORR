#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include "src/Interval.h"
#include "src/Solver.h"


int main() {
    using boost::math::constants::pi;
    using boost::multiprecision::cpp_dec_float_50;
    int startTime = clock();

    int intervalA = -5;
    int intervalB = 20;
    double (*derivative)(double)= &dfun2;
    double (*function)(double)=&fun2;
    double L = 20;
    std::cout << "L: " << L << std::endl;
    Interval *nowy = new Interval(intervalA, intervalB, derivative, function, L);
    Solver *solver = new Solver(*nowy, derivative, function);
    solver->test();

    int duration = clock() - startTime;
    std::cout << "Czas trwania: " << duration << "[ms] " << std::endl;
    return 0;
}

