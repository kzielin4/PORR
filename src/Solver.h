//
// Created by kamil on 30.10.17.
//

#ifndef UNTITLED_SOLVER_H
#define UNTITLED_SOLVER_H

#include <iostream>
#include <cstddef>
#include <list>
#include <float.h>
#include "Interval.h"
#include <tuple>

class Solver {

    std::list<Interval> intervalList;
    double minValue;
public:
    Solver(const Interval &interval) {
        minValue = DBL_MAX;
        intervalList.push_back(interval);
    };
public:
    void addIntervalToList(const Interval &interval) {
        intervalList.push_back(interval);
    }

public:
    void test() {
        std::list<Interval>::iterator it = intervalList.begin();
        double x, result;
        double minx = DBL_MAX;
        int i;

        for (i = 0; it != intervalList.end(); ++i) {
            std::tie(x, result) = it->countIntervalCrossPoint(&dfun2, &fun2);
            if (result > minValue || (result == -1 && it->getIsDericativeExist())) {
                ++it;
                intervalList.pop_front();
            } else {
                minValue = result;
                minx = x;
                Interval *firstPoint = new Interval(it->getSmallesValue(), x);
                addIntervalToList(*firstPoint);
                Interval *secondPoint = new Interval(x,it->getBiggestValue());
                addIntervalToList(*secondPoint);
                ++it;
                intervalList.pop_front();
            }
        }
        std::cout << "X: " << minx << "   MIN: " << minValue;
    };
};


#endif //UNTITLED_SOLVER_H
