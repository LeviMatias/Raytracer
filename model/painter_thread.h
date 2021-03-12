//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_PAINTER_THREAD_H
#define RAYTRACER_PAINTER_THREAD_H


#include "../utility/BaseThread.h"
#include "Image.h"

class PainterThread : public BaseThread {
public:
    Image * canvas;

    // PainterThread(Image* img);

private:
    // void _run() override;
};


#endif //RAYTRACER_PAINTER_THREAD_H
