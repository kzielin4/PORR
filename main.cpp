#include <iostream>
#include <iomanip>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include "src/derivative.h"
int main() {
    using boost::math::constants::pi;
    using boost::multiprecision::cpp_dec_float_50;
    std::cout<<fun1(0.0)<<std::endl;
    std::cout<<fun2(0.0)<<std::endl;
    std::cout<<fun3(0.0)<<std::endl;
    std::cout<<fun4(0.0)<<std::endl;
    std::cout<<fun5(0.0)<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}