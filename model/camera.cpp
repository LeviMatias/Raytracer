//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#include "camera.h"
#include "concurrency/draw_thread.h"
#include "concurrency/status_thread.h"

Camera::Camera(double v_fov, double aspect_ratio, double focal_length) {

    auto theta = DEG2RAD(v_fov);
    auto h = tan(theta/2);

    this->viewport_height = 2 * h;
    this->focal_length = focal_length;
    this->viewport_width = aspect_ratio * viewport_height;

    this->origin = Point3();
    this->horizontal = Vec3(viewport_width, 0, 0);
    this->vertical = Vec3(0, viewport_height, 0);
    this->lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);
}

Ray Camera::GetRay(double x, double y) const {
    return {origin, lower_left_corner + x*horizontal + y*vertical - origin};
}

void Camera::Draw(Scene &scene, Image &canvas) {
    std::vector<DrawThread> t;
    StatusThread st;
    st.run();

    for (int i=0; i < N_DRAW_THREADS; i++){
        t.emplace_back(&scene, this, &canvas, i, N_DRAW_THREADS);
    }

    //had to do it separate loop otherwise compiler bugs out by calling the method run()
    //before finishing instantiation
    for (int i=0; i < N_DRAW_THREADS; i++){
        t[i].run();
    }

    for (int i=0; i < N_DRAW_THREADS; i++){
        t[i].join();
    }

    st.close();
    st.join();
}
