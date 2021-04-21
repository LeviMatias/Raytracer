//
// Created by Matias Ignacio Levi Fernandez on 19/04/2021.
//

#include "instance_rotate_y.h"

InstanceRotateY::InstanceRotateY(shared_ptr<Hittable> &p, double angle) : ptr(p) {
    auto radians = DEG2RAD(angle);
    sin_theta = sin(radians);
    cos_theta = cos(radians);
    bounding_box.near = ptr->bounding_box.near;
    bounding_box.far = ptr->bounding_box.far;

    Point3 min( INF,  INF,  INF);
    Point3 max(-INF, -INF, -INF);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                double x = i*bounding_box.far.x() + (1-i)*bounding_box.near.x();
                double y = j*bounding_box.far.y() + (1-j)*bounding_box.near.y();
                double z = k*bounding_box.far.z() + (1-k)*bounding_box.near.z();

                double newx =  cos_theta*x + sin_theta*z;
                double newz = -sin_theta*x + cos_theta*z;

                Vec3 tester(newx, y, newz);

                for (int c = 0; c < 3; c++) {
                    min[c] = fmin(min[c], tester[c]);
                    max[c] = fmax(max[c], tester[c]);
                }
            }
        }
    }

    bounding_box.near = min;
    bounding_box.far = max;
}

bool InstanceRotateY::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    auto origin = r.origin;
    auto direction = r.direction;

    origin[0] = cos_theta*r.origin[0] - sin_theta*r.origin[2];
    origin[2] = sin_theta*r.origin[0] + cos_theta*r.origin[2];

    direction[0] = cos_theta*r.direction[0] - sin_theta*r.direction[2];
    direction[2] = sin_theta*r.direction[0] + cos_theta*r.direction[2];

    Ray rotated_r(origin, direction);

    if (!ptr->Hit(rotated_r, t_min, t_max, rec))
        return false;

    auto p = rec.p;
    auto normal = rec.normal;

    p[0] =  cos_theta*rec.p[0] + sin_theta*rec.p[2];
    p[2] = -sin_theta*rec.p[0] + cos_theta*rec.p[2];

    normal[0] =  cos_theta*rec.normal[0] + sin_theta*rec.normal[2];
    normal[2] = -sin_theta*rec.normal[0] + cos_theta*rec.normal[2];

    rec.p = p;
    rec.set_face_normal(rotated_r, normal);

    return true;
}
