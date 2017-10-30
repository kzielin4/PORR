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
        Interval *nowy = new Interval(1.0, 2.0);
        addIntervalToList(*nowy);
        std::cout << "Size: " << intervalList.size() << std::endl;
        for (int i = 0; i < intervalList.size(); ++i) {
            std::cout << "Wynik:" << it->countIntervalCrossPoint(&dfun1, &fun1) << std::endl;
            ++it;
        }
    };
};


#endif //UNTITLED_SOLVER_H
