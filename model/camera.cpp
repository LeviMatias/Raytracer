//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#include "camera.h"
#include "concurrency/draw_thread.h"
#include "concurrency/status_thread.h"

Camera::Camera(Vec3 position, Vec3 lookAt, double v_fov, double aspect_ratio, double aperture, double focus_dist) {

    auto theta = DEG2RAD(v_fov);
    auto h = tan(theta/2);

    this->viewport_height = 2 * h;
    this->viewport_width = aspect_ratio * viewport_height;

    // right hand rule
    w = (lookAt - position).unit(); //dir to lookAt from pos (look vector)
    u = CAM_V_UP.cross(w).unit(); // horizontal axis vec (right vector)
    v = w.cross(u); // vertical axis vector (top vector)

    this->origin = position;
    this->horizontal = u * viewport_width * focus_dist;
    this->vertical = v * viewport_height * focus_dist;

    //lower left corner of the camera's viewport cam --> [ vp ]
    this->view_port_lower_left_corner = origin - horizontal/2 - vertical/2 + w*focus_dist;
    lens_radius = aperture/2.0;
}

Ray Camera::GetRay(double x, double y) const {
    double rad = DEG2RAD(Random::NextNumber(0, 360));
    Vec3 offset = Vec3(std::cos(rad) , std::sin(rad), 0) * Random::NextNumber(0, lens_radius);
    offset = v * offset.y() + u * offset.x();

    return {origin + offset, view_port_lower_left_corner + x*horizontal + y*vertical - origin - offset};
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
