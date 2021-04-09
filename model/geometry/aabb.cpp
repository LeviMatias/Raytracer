//
// Created by Matias Ignacio Levi Fernandez on 08/04/2021.
//

#include "aabb.h"

AABB::AABB(const Point3 &near, const Point3 &far) : near(near), far(far) {}

AABB::AABB(const AABB &b0, const AABB &b1) {
    near = Vec3(fmin(b0.near.x(), b1.near.x()),
                 fmin(b0.near.y(), b1.near.y()),
                 fmin(b0.near.z(), b1.near.z()));

    far = Vec3(fmax(b0.far.x(), b1.far.x()),
               fmax(b0.far.y(), b1.far.y()),
               fmax(b0.far.z(), b1.far.z()));
}

bool AABB::Hit(Ray r, double t_min, double t_max) {

    for (int dimension = 0; dimension < 3; dimension++){
        // for each dimension, we evaluate where a hit is registered
        auto invD = 1.0f / r.direction[dimension];
        auto t0 = (near[dimension] - r.origin[dimension]) * invD;
        auto t1 = (far[dimension] - r.origin[dimension]) * invD;

        //check to catch cases where ray is traveling in negative direction (should hit "far" in entry point)
        if (invD < 0.0f) std::swap(t0, t1);

        //if there was a hit in this dimension, we update the valid ray boundaries
        //as to make sure there is an overlapping hit in other dimensions
        t_min = t0 > t_min ? t0 : t_min;
        t_max = t1 < t_max ? t1 : t_max;

        // An intersection with the volume occurs if the final t_mx value is greater than the t_mn value.
        // a ray that COMPLETELY misses the bounding boxes will either have equal t_mn tmx or t_mn > t_mx

        // X = (1 , 3), Y =(5, 6)
        // ray (0, 0) + (1, 1)*t
        // first iteration over X will yield tmin = 1, tmax = 3
        // second over Y will yield  tmin = max(tmin, 5) = 5, tmax = min(tmax, 6) = tmax = 3
        // tmax <= tmin

        if (t_max <= t_min) return false;
    }

    return true;
}


