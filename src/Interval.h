//
// Created by kamil on 28.10.17.
//

#ifndef UNTITLED_INTERVAL_H
#define UNTITLED_INTERVAL_H

#include "derivative.h"
#include <iostream>

class Interval {
    double a;
    double b;
    bool isDericativeExist;
public:
    Interval(double a, double b){
        this->a=a;
        this->b=b;
    }
public:
    double countIntervalCrossPoint(double (*derivative)(double), double (*function)(double)) {
        isDericativeExist = true;
        double derivA = derivative(a);
        double derivB = derivative(b);
        double funValA = function(a);
        double funValB = function(b);
        std::cout<<"dA"<<derivA<<"  FUN: "<<funValA<<std::endl;
        std::cout<<"dB"<<derivB<<"  FUN: "<<funValB<<std::endl;
        double result;
        if (derivA == derivB) {
            isDericativeExist = false;
            return -1;
        } else {
            result = (funValA - derivA * a - funValB + derivB * b) / (derivB - derivA);
            return function(result);
        }
    }
};


#endif //UNTITLED_INTERVAL_H
