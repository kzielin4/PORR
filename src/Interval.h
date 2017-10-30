//
// Created by kamil on 28.10.17.
//

#ifndef UNTITLED_INTERVAL_H
#define UNTITLED_INTERVAL_H

#include "derivative.h"
#include <iostream>
#include <tuple>

class Interval {
    double a;
    double b;
    bool isDericativeExist;
public:
    Interval(double a, double b) {
        this->a = a;
        this->b = b;
    }

public:
    std::tuple<double,double> countIntervalCrossPoint(double (*derivative)(double), double (*function)(double)) {
        isDericativeExist = true;
        double derivA = derivative(a);
        double derivB = derivative(b);
        double funValA = function(a);
        double funValB = function(b);
        double result;
        if (derivA == derivB) {
            isDericativeExist = false;
            return  std::make_tuple(-1,-1);
        } else {
            result = (funValA - derivA * a - funValB + derivB * b) / (derivB - derivA);
            std::cout<<"x: "<<result<<"     y:"<<function(result)<<std::endl;
            return std::make_tuple(result,function(result));
        }
    }

public:
    double getSmallesValue() {
        return (b > a) ? a : b;
    }

public:
    bool getIsDericativeExist(){
        return isDericativeExist;
    }
};


#endif //UNTITLED_INTERVAL_H
