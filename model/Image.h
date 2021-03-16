//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H


#include "../utility/safe_stream.h"
#include "../utility/Vec3.h"

#define IMAGE_NAME "image.ppm"

struct pixel_rgb{
    int r, g, b;

    pixel_rgb(int r, int g, int b)
    : r(r), g(g), b(b) {};

    pixel_rgb()
    : r(0), g(0), b(0) {};
};


class Image {
public:
    double aspect_ratio;
    int h;
    int w;

    Image(const std::string& imgname, double aspect_ratio, int w);

    Image(double aspect_ratio, int w);

    void WriteColor(Color pixel_color);

    void WriteColorAt(Color pixel_color, int x, int y);

    void Flush();

private:
    SafeStream out;
    std::vector<pixel_rgb> buffer;
};


#endif //RAYTRACER_IMAGE_H
