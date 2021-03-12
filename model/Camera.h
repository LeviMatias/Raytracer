//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "../utility/Vec3.h"
#include "../utility/Ray.h"

class Camera {
public:
    double viewport_height;
    double viewport_width;
    double focal_length;

    Point3 origin;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 lower_left_corner;

    Camera(double viewport_height, double aspect_ratio, double focal_length){
        this->viewport_height = viewport_height;
        this->focal_length = focal_length;
        this->viewport_width = aspect_ratio * viewport_height;

        this->origin = Point3();
        this->horizontal = Vec3(viewport_width, 0, 0);
        this->vertical = Vec3(0, viewport_height, 0);
        this->lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);
    }

    Ray GetRay(double x, double y) const;
};


#endif //RAYTRACER_CAMERA_H
