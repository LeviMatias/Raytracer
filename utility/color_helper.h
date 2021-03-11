//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#ifndef RAYTRACER_COLOR3_H
#define RAYTRACER_COLOR3_H

#include "../model/Hittable.h"
#include "safe_stream.h"
#include "constants.h"

#define LIGHT_BLUE color(0.5, 0.7, 1.0)
#define WHITE color(1.0, 1.0, 1.0)

void write_color(SafeStream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

color ray_color(const ray& r, const Hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, INF, rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }
    vec3 unit_direction = r.direction().unit();
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}
#endif
