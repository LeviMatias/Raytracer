//
// Created by Matias Ignacio Levi Fernandez on 16/03/2021.
//

#ifndef RAYTRACER_PAINTER_H
#define RAYTRACER_PAINTER_H

#define N_PENCIL_THREADS 1
#include "Camera.h"
#include "Scene.h"
#include "Image.h"
#include "painter_thread.h"

class Painter {
public:
    Camera* cam;
    Scene* scene;

    Painter(Scene* scene, Camera* cam);

    void Paint(Image* canvas);

    ~Painter();
};


#endif //RAYTRACER_PAINTER_H
