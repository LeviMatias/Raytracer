//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#include "sphere.h"
#include "../materials/lambertian.h"

Sphere::Sphere(Point3 center, double r) : Sphere(make_shared<DEFAULT_MATERIAL>(), center, r) {}

Sphere::Sphere(shared_ptr<Material> material, Point3 center, double r) : Hittable(material) {
    this->center = center;
    radius = r;
}

bool Sphere::Hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    // C = sphere center
    // (ray.at(t) - C) . (ray.At(t) - C) = r**2
    // (origin + t*direction - C) . (origin + t*direction - C) = r**2
    // the sphere is Hit for t values that satisfy above eq

    Vec3 oc = r.origin - center;

    // solve the quadratic to find whether there is a root(s)
    // for given ray
    // we can use half b to simplify eq
    auto a = r.direction.length_squared();
    auto half_b = oc.dot(r.direction);
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    // if discriminant is less than zero it means there are no (real) roots
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.At(rec.t);
    //normal pointing outwards from center
    Vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.hit = (Hittable *)this;

    return true;
}
