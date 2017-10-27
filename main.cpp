#include <iostream>
#include <iomanip>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>


template<typename value_type, typename function_type>
value_type derivative(const value_type x, const value_type dx, function_type func) {
    // Compute d/dx[func(*first)] using a three-point
    // central difference rule of O(dx^6).

    const value_type dx1 = dx;
    const value_type dx2 = dx1 * 2;
    const value_type dx3 = dx1 * 3;

    const value_type m1 = (func(x + dx1) - func(x - dx1)) / 2;
    const value_type m2 = (func(x + dx2) - func(x - dx2)) / 4;
    const value_type m3 = (func(x + dx3) - func(x - dx3)) / 6;

    const value_type fifteen_m1 = 15 * m1;
    const value_type six_m2 = 6 * m2;
    const value_type ten_dx1 = 10 * dx1;

    return ((fifteen_m1 - six_m2) + m3) / ten_dx1;
}


int main() {
    using boost::math::constants::pi;
    using boost::multiprecision::cpp_dec_float_50;
    const float d_f = derivative(
            pi<float>() / 3,
            0.01F,
            static_cast<float (*)(float)>(std::sin)
    );

    float d_f2 = derivative(5.00F, 0.01F,
                            [](const float &x) -> float {
                                return float(x);
                            }
    );
    std::cout << d_f2;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}