//
// Created by Matias Ignacio Levi Fernandez on 18/03/2021.
//

#include "stopwatch.h"

Stopwatch::Stopwatch() {
    this->reset();
}

void Stopwatch::reset() {
    t1 = clock();
    current_t = 0;
}

float Stopwatch::diff() {
    clock_t t2 = clock();
    float t = float(t2-t1)/CLOCKS_PER_SEC;
    current_t = t;
    return t;
}