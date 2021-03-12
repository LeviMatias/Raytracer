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
#define LIGHT_BLUE color(0.5, 0.7, 1.0)
#define WHITE color(1.0, 1.0, 1.0)

class PainterThread : public BaseThread {
public:
    Hittable* world;
    Camera* cam;
    Image * canvas;
    int offset;

    // PainterThread(Image* img);

private:
    void _run() override;

    Color Ray2Color(const Ray& r) const;
};


#endif //RAYTRACER_PAINTER_THREAD_H
