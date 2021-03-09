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

double hit_sphere(const point3& center, double radius, const ray& r) {
    // C = sphere center
    // (ray.at(t) - C) . (ray.at(t) - C) = r**2
    // (orig + t*dir - C) . (orig + t*dir - C) = r**2
    // the sphere is hit for t values that satisfy above eq

    vec3 oc = r.origin() - center;

    // solve the quadratic to find whether there is a root(s)
    // for given ray
    auto a = r.dir.dot( r.dir );
    auto b = 2.0 * oc.dot(r.dir);
    auto c = oc.dot(oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0; //no (real) root
    } else {
        // minus = front outer root
        // plus = back outer root
        return (-b - sqrt(discriminant) ) / (2.0*a);
    }
}

void write_color(SafeStream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

color ray_color(const ray &r){
    auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    if (t > 0.0) {
        vec3 N = (r.at(t) - vec3(0,0,-1)).unit();
        return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
    }
    //gradient background color
    vec3 unit_direction = r.dir.unit();
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*WHITE + t*LIGHT_BLUE;
}

#endif
