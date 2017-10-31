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
            std::cout<<"A: "<<a <<"   B:"<<b<<"   X: "<<result<<"     Y:"<<function(result)<<std::endl;
            double www = std::max(funValA - derivA * a + derivA*result,funValB - derivB * b + derivB*result);
            return std::make_tuple(result,function(result));
        }
    }

public:
    double getSmallesValue() {
        return (b > a) ? a : b;
    }

public:
    double getBiggestValue() {
        return (b > a) ? b : a;
    }

public:
    bool getIsDericativeExist(){
        return isDericativeExist;
    }
};


#endif //UNTITLED_INTERVAL_H
