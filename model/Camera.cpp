//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#include "Camera.h"

ray Camera::ray_to(double x, double y) const {
    return {origin, lower_left_corner + x*horizontal + y*vertical - origin};
}
