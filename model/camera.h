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
#define CAM_V_UP Vec3(0,1.0,0)

class Camera {
public:
    double viewport_height;
    double viewport_width;

    Point3 origin;

    //cams horizontal axis
    Vec3 horizontal;

    // cams vertical axis
    Vec3 vertical;

    //lower left corner of the camera's viewport cam --> [ vp ]
    Vec3 view_port_lower_left_corner;

    Camera(Vec3 position, Vec3 lookAt,
           double vertical_field_of_view, double aspect_ratio);

    void Draw(Scene& scene, Image& canvas);

    Ray GetRay(double x, double y) const;
};


#endif //RAYTRACER_CAMERA_H
