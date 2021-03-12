//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#include "painter_thread.h"
#include "../utility/Ray.h"

void PainterThread::_run() {
    for (int j = canvas->h-1; j >= 0; j-= offset){
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < canvas->w; i+= offset){
            Color pixel_color(0, 0, 0);
            for (int s = 0; s < STROKES; ++s) {
                auto u = (i + Random::NextNumber()) / (canvas->w-1);
                auto v = (j + Random::NextNumber()) / (canvas->h-1);
                Ray r = cam->GetRay(u, v);
                pixel_color += Ray2Color(r);
            }
            canvas->WriteColor(pixel_color/STROKES);
        }
    }
}

Color PainterThread::Ray2Color(const Ray& r) const {
    hit_record rec;
    if (world->hit(r, 0, INF, rec)) {
        return 0.5 * (rec.normal + Color(1, 1, 1));
    }
    Vec3 unit_direction = r.direction.unit();
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}
