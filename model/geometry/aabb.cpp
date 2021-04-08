//
// Created by Matias Ignacio Levi Fernandez on 08/04/2021.
//

#include "aabb.h"

AABB::AABB(const Point3 &near, const Point3 &far) : near(near), far(far) {}

bool AABB::Hit(Ray ray, double t_min, double t_max) {

    for (int dimension = 0; dimension < 3; dimension++){
        // for each dimension, we evaluate where a hit is registered
        auto ev_aabb_start = (near[dimension] - ray.origin[dimension]) / ray.direction[dimension];
        auto ev_aabb_end = (far[dimension] - ray.origin[dimension]) / ray.direction[dimension];

        //min max check to catch cases where ray is traveling in negative direction
        auto entry_p = fmin( ev_aabb_start,  ev_aabb_end);
        auto exit_p = fmax( ev_aabb_start,  ev_aabb_end);

        //if there was a hit, we update the valid ray boundaries
        //as to make sure there is an overlapping hit in other dimensions
        t_max = fmin(t_max, exit_p);
        t_min = fmax(t_min, entry_p);

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


