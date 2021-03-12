//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_RANDOM_H
#define RAYTRACER_RANDOM_H

#include <cstdlib>
...

// Returns a random real in [0,1).
#define RAND01 rand() / (RAND_MAX + 1.0)

// Returns a random real in [min,max).
#define RAND (min, max) (min + (max-min)*RAND01)


#endif //RAYTRACER_RANDOM_H
