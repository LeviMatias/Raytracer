//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_DRAW_THREAD_H
#define RAYTRACER_DRAW_THREAD_H


#include "base_thread.h"
#include "../../utility/random.h"
#include "../../utility/defines.h"
#include "../image.h"
#include "../camera.h"
#include "../scene.h"

#define SAMPLES 250
#define MAX_DEPTH 20

#define LIGHT_YELLOW Color(0.9, 0.8, 0.6)
#define WHITE Color(1.0, 1.0, 1.0)


class DrawThread : public BaseThread {
public:
    Scene* world;
    Camera* cam;
    Image * canvas;
    int offset, offset_start;

    explicit DrawThread(Scene* w, Camera* c, Image* i, int start, int offset);

private:
    void _run() override;

    Color _ray2Color(const Ray& r) const;

    Color _ray2Color_rec(const Ray& r, int depth) const;
};


#endif //RAYTRACER_DRAW_THREAD_H
