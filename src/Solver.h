//
// Created by kamil on 30.10.17.
//

#ifndef UNTITLED_SOLVER_H
#define UNTITLED_SOLVER_H

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <list>
#include <float.h>
#include "Interval.h"
#include <tuple>

class Solver {

    std::list<Interval> intervalList;
    double minValue;
    double startA;
    double startB;

    double (*derivative)(double);

    double (*function)(double);

public:
    Solver(const Interval &interval, double (*derivative1)(double), double (*function2)(double)) {
        minValue = DBL_MAX;
        intervalList.push_back(interval);
        std::list<Interval>::iterator it = intervalList.begin();
        startA = it->getSmallesValue();
        startB = it->getBiggestValue();
        derivative = derivative1;
        function = function2;

    };
public:
    void addIntervalToList(const Interval &interval) {
        intervalList.push_back(interval);
    }

public:
    void test() {
        std::list<Interval> minIntervalList;
        std::list<Interval>::iterator it = intervalList.begin();
        double x, result;
        double minx = DBL_MAX;
        double L = it->getL();
        bool isFirsLoop = false;
        bool isNOTFound=true;
        double lastCorrectX;
        double aprox;
        int counter=0;
        while(isNOTFound){
            std::tie(x, result,aprox) = it->countIntervalCrossPoint();
            if (aprox >= minValue ||(result<=minValue && std::abs(it->getSmallesValue() - it->getBiggestValue()) < 0.01)) {
                int w =1;
                if(std::abs(it->getSmallesValue() - it->getBiggestValue()) < 0.01){
                isNOTFound=false;}
                ++it;
                intervalList.pop_front();
            } else {
                if(result<minValue) {
                    minValue = result;
                    minx = x;
                }
                Interval *firstPoint = new Interval(it->getSmallesValue(), x, derivative, function,L);
                addIntervalToList(*firstPoint);
                Interval *secondPoint = new Interval(x, it->getBiggestValue(), derivative, function,L);
                addIntervalToList(*secondPoint);
                ++it;
                intervalList.pop_front();
            }
        }
        std::cout << "Solver:"<< std::endl;
        std::cout << "X: "<<minx <<"   Y: "<<minValue<<std::endl;
    };

};


#endif //UNTITLED_SOLVER_H
