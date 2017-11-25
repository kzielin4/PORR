//
// Created by kamil on 28.10.17.
//

#ifndef UNTITLED_INTERVAL_H
#define UNTITLED_INTERVAL_H

#include "derivative.h"
#include <iostream>
#include <tuple>
#include <algorithm>

class Interval {
    double a;
    double b;
    double funValA;
    double funValB;
    bool isDericativeExist;
    double (*derivative)(double);
    double (*function)(double);

public:
    Interval(double a, double b, double (*derivative1)(double), double (*function2)(double)) {
        this->a = a;
        this->b = b;
        derivative = derivative1;
        function = function2;
        funValA = function(a);
        funValB = function(b);
    }

public:
    std::tuple<double,double> countIntervalCrossPoint() {
            isDericativeExist = true;
        double derivA = 37;
        double derivB = 37;
        double result;
//        if (derivA == derivB) {
//            isDericativeExist = false;
//            return std::make_tuple(-1, -1);
        //} else
            result = (funValA + derivA * a - funValB + derivB * b) / (derivB + derivA);
            std::cout << "A: " << a << "   B:" << b << "   X: " << result << "     Y:" << function(result) << std::endl;
//            if (result < a || result> b) {
//                isDericativeExist = false;
//                return std::make_tuple(-1, -1);
//            }
            return std::make_tuple(result, function(result));
       // }
    }

public:
    double getSmallesValue() {
        return (b > a) ? a : b;
    }

    double getBiggestValue() {
        return (b > a) ? b : a;
    }

    double getFunValA() const {
        return funValA;
    }

    double getFunValB() const {
        return funValB;
    }

    double getValuedFromArg(double val) const {
        return function(val);
    }

    bool getIsDericativeExist() {
        return isDericativeExist;
    }
};

#endif //UNTITLED_INTERVAL_H
