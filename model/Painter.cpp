//
// Created by Matias Ignacio Levi Fernandez on 16/03/2021.
//

#include <vector>
#include "Painter.h"

Painter::Painter(Scene* scene, Camera* cam) {
    this->cam = cam;
    this->scene = scene;
}

void Painter::Paint(Image *canvas) {
    std::vector<PainterThread> t;

    for (int i=0; i < N_PENCIL_THREADS; i++){
        t.emplace_back(scene, cam, canvas, i + 1);
        t[i].run();
    }

    for (int i=0; i < N_PENCIL_THREADS; i++){
        t[i].join();
    }
}

Painter::~Painter() {}
