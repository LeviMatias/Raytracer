//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "../utility/vec3.h"
#include "../utility/ray.h"

struct image {
    double aspect_ratio;
    int h;
    int w;
};


class Camera {
public:
    double viewport_height;
    double viewport_width;
    double focal_length;

    point3 origin;
    vec3 horizontal;
    vec3 vertical;
    vec3 lower_left_corner;

    Camera(double viewport_height, double aspect_ratio, double focal_length){
        this->viewport_height = viewport_height;
        this->focal_length = focal_length;
        this->viewport_width = aspect_ratio * viewport_height;

        this->origin = point3();
        this->horizontal = vec3(viewport_width, 0, 0);
        this->vertical = vec3(0, viewport_height, 0);
        this->lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
    }

    ray GetRay(double x, double y) const;
};


#endif //RAYTRACER_CAMERA_H
