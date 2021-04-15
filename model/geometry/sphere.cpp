//
// Created by Matias Ignacio Levi Fernandez on 10/03/2021.
//

#include "sphere.h"
#include "../materials/lambertian.h"

Sphere::Sphere(Point3 center, double r) : Sphere(center, r, make_shared<DEFAULT_MATERIAL>()){}

Sphere::Sphere(Point3 center, double r, shared_ptr<Material> material) : Hittable(material){
    this->center = center;
    radius = r;
    bounding_box.far = center + Vec3(r,r,r);//upper right
    bounding_box.near = center - Vec3(r,r,r);//lower left
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
    //get uv coordinates of p from outward pointing normal
    SetSphereUV(outward_normal, rec);

    rec.set_face_normal(r, outward_normal);
    rec.hit = (Hittable *)this;

    return true;
}

void Sphere::SetSphereUV(const Point3 &point_in_usphere, hit_record &rec) {
    // p: a given point on the sphere of radius one, centered at the origin.
    // u: returned value [0,1] of angle around the Y axis from X=-1.
    // v: returned value [0,1] of angle from Y=-1 to Y=+1.
    //     <1 0 0> yields <0.50 0.50>       <-1  0  0> yields <0.00 0.50>
    //     <0 1 0> yields <0.50 1.00>       < 0 -1  0> yields <0.50 0.00>
    //     <0 0 1> yields <0.25 0.50>       < 0  0 -1> yields <0.75 0.50>

    auto theta = acos(-point_in_usphere.y());
    auto phi = atan2(-point_in_usphere.z(), point_in_usphere.x()) + PI;

    rec.u = phi / (2*PI);
    rec.v = theta / PI;
}
