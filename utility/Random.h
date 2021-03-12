//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_RANDOM_H
#define RAYTRACER_RANDOM_H

#include <random>

class Random {
public:
    inline static double NextNumber();

    inline static double NextNumber(double a, double b);
};

double Random::NextNumber() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

double Random::NextNumber(double a, double b) {
    return Random::NextNumber() * (b - a) + a;
}


#endif //RAYTRACER_RANDOM_H
