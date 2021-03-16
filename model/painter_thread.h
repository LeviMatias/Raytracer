//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_PAINTER_THREAD_H
#define RAYTRACER_PAINTER_THREAD_H


#include "../utility/BaseThread.h"
#include "../utility/Random.h"
#include "../utility/Utility.h"
#include "Image.h"
#include "Camera.h"
#include "Scene.h"

#define STROKES 100
#define MAX_DEPTH 25
#define LIGHT_BLUE Color(0.5, 0.7, 1.0)
#define WHITE Color(1.0, 1.0, 1.0)

class PainterThread : public BaseThread {
public:
    Scene* world;
    Camera* cam;
    Image * canvas;
    int offset;

    PainterThread(Scene* w, Camera* c, Image* i, int offs);

private:
    void _run() override;

    Color Ray2Color(const Ray& r) const;

    Color Ray2Color_rec(const Ray& r, int depth) const;
};


#endif //RAYTRACER_PAINTER_THREAD_H
