//
// Created by Matias Ignacio Levi Fernandez on 09/03/2021.
//

#include "camera.h"
#include "concurrency/draw_thread.h"
#include "concurrency/status_thread.h"

Camera::Camera(Vec3 position, Vec3 lookAt, double v_fov, double aspect_ratio) {

    auto theta = DEG2RAD(v_fov);
    auto h = tan(theta/2);

    this->viewport_height = 2 * h;
    this->viewport_width = aspect_ratio * viewport_height;

    Vec3 w = (position - lookAt).unit(); //dir to lookAt from pos
    Vec3 u = CAM_V_UP.cross(w).unit(); // horizontal axis vec
    Vec3 v = w.cross(u); // vertical axis vector

    // right hand rule
    this->origin = position;
    this->horizontal = u * viewport_width;
    this->vertical = v * viewport_height;

    //lower left corner of the camera's viewport cam --> [ vp ]
    this->view_port_lower_left_corner = origin - horizontal/2 - vertical/2 - w;
}

Ray Camera::GetRay(double x, double y) const {
    return {origin, view_port_lower_left_corner + x*horizontal + y*vertical - origin};
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
