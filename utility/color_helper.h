//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_COLOR3_H
#define RAYTRACER_COLOR3_H

#include "vec3.h"
#include "safe_stream.h"
#include "ray.h"

#define LIGHT_BLUE color(0.5, 0.7, 1.0)
#define WHITE color(1.0, 1.0, 1.0)

bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = r.dir.dot( r.dir );
    auto b = 2.0 * oc.dot(r.dir);
    auto c = oc.dot(oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}

void write_color(SafeStream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

color ray_color(const ray &r){
    if (hit_sphere(point3(0,0,-1), 0.5, r))
        return color(1, 0.25, 0.25);

    //gradient background color
    vec3 unit_direction = r.dir.unit();
    double t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*WHITE + t*LIGHT_BLUE;
}

#endif
