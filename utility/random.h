//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_RANDOM_H
#define RAYTRACER_RANDOM_H

#include <random>
#include "perlin.h"

class Random {
public:
    inline static double NextNumber();

    inline static double NextNumber(double a, double b);

    inline static int NextInteger(int a, int b);

    inline static double PerlinNoise(double a, double b);
};

double Random::NextNumber() {
    static thread_local std::uniform_real_distribution<double> distribution(0.0, 1.0);
    //seed = (int)std::chrono::system_clock::now().time_since_epoch().count()
    static thread_local std::mt19937 generator;
    return distribution(generator);
}

double Random::NextNumber(double a, double b) {
    return Random::NextNumber() * (b - a) + a;
}

int Random::NextInteger(int a, int b){
    // for a >= 0
    return (int)NextNumber(a, b + 1);
}

double Random::PerlinNoise(double a, double b) {
    auto x  = perlin::noise(a, 0.0, b);
    return (double)x;
}


#endif //RAYTRACER_RANDOM_H
