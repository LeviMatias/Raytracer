//
// Created by Matias Ignacio Levi Fernandez on 18/03/2021.
//

#include "stopwatch.h"

Stopwatch::Stopwatch() {
    t0 = std::chrono::steady_clock::now();
}

void Stopwatch::reset() {
    t0 = std::chrono::steady_clock::now();
}

float Stopwatch::diff() {
    auto t1 = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(t1 - t0);

    return duration.count();
}