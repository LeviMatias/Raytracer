//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H


#include "concurrency/safe_stream.h"
#include "../utility/vec3.h"

#define IMG_WIDTH 800
#define IMG_ASPECT_RATIO (16.0/9.0)
#define IMG_HEIGHT (static_cast<int>(IMG_WIDTH / IMG_ASPECT_RATIO))
#define IMAGE_NAME "image.ppm"

struct pixel_rgb{
    char r, g, b;
};


class Image {
public:
    double aspect_ratio;
    int h;
    int w;

    Image();

    explicit Image(const std::string& imgname);

    void WriteColorAt(Color pixel_color, int x, int y);

    void Save();

private:
    std::vector<pixel_rgb> buffer;
};


#endif //RAYTRACER_IMAGE_H
