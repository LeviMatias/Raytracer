//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "../utility/vec3.h"
#include "../utility/ray.h"
#include "scene.h"
#include "image.h"

#define N_DRAW_THREADS 8

class Camera {
public:
    double viewport_height;
    double viewport_width;
    double focal_length;

    Point3 origin;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 lower_left_corner;

    Camera(double vertical_field_of_view, double aspect_ratio, double focal_length);

    void Draw(Scene& scene, Image& canvas);

    Ray GetRay(double x, double y) const;
};


#endif //RAYTRACER_CAMERA_H
