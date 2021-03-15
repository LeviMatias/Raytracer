//
// Created by Matias Ignacio Levi Fernandez on 11/03/2021.
//

#ifndef RAYTRACER_UTILITY_H
#define RAYTRACER_UTILITY_H

#include <cmath>
#include <limits>
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;
using std::sin;
using std::cos;

// Constants

#define INF std::numeric_limits<double>::infinity()
#define PI 3.1415926535897932385

// Utility macros
#define CLAMP (x, min, max) (if (x > max) return max; if (x < min) return min; return x)

#define DEG2RAD (deg) (deg * PI / 180.0)

// Common Headers

#include "Ray.h"
#include "Vec3.h"

#endif //RAYTRACER_UTILITY_H
