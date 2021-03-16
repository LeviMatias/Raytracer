//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#include "painter_thread.h"
#include "../utility/Ray.h"

PainterThread::PainterThread(Scene *w, Camera *c, Image *i, int offs) {
    canvas = i;
    cam = c;
    offset = offs;
    world = w;
}

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

    return Ray2Color_rec(r, 0);
}

Color PainterThread::Ray2Color_rec(const Ray &r, int depth) const {
    if (depth >= MAX_DEPTH ) return {};

    hit_record rec;
    if (world->hit(r, 0, INF, rec)) {
        double x = Random::NextNumber(-1,1);
        double s = cos((PI/2) * x);
        double y = Random::NextNumber(-s, s);
        double eq = sqrt(1 - x*x - y*y);
        double z = Random::NextNumber(-eq, eq);

        Point3 target = rec.p + rec.normal + Vec3(x, y, z);
        return 0.50 * Ray2Color_rec(Ray(rec.p, target - rec.p), ++depth);
    }
    Vec3 unit_direction = r.direction.unit();
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t) * WHITE + t * LIGHT_BLUE;
}
