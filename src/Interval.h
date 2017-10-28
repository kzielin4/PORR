//
// Created by kamil on 28.10.17.
//

#ifndef UNTITLED_INTERVAL_H
#define UNTITLED_INTERVAL_H

#include "derivative.h"

class Interval {
    double a;
    double b;
public:
    double fun11() {
        return fun1(a);
    }

public:
    double fun12() {
        return fun1(b);
    }
};


#endif //UNTITLED_INTERVAL_H
