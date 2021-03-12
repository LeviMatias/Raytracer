//
// Created by Matias Ignacio Levi Fernandez on 12/03/2021.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H


#include "../utility/safe_stream.h"
#include "../utility/vec3.h"

#define IMAGE_NAME "image.ppm"

class Image {
public:
    double aspect_ratio;
    int h;
    int w;

    Image(const std::string& imgname, double aspect_ratio, int w);

    Image(double aspect_ratio, int w);

    void WriteColor(color pixel_color);

    //will probably have to write to a buffer instead of directly
    //if wanted to implement
    void WriteColorAt(color pixel_color, int i);

private:
    SafeStream out;
};


#endif //RAYTRACER_IMAGE_H
