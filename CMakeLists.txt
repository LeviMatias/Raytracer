cmake_minimum_required(VERSION 3.17)
project(raytracer)
set(CMAKE_CXX_FLAGS_RELEASE "/O2")
set(CMAKE_CXX_STANDARD 17)


add_executable(raytracer main.cpp utility/safe_stream.h utility/safe_stream.cpp utility/vec3.h utility/ray.h model/camera.cpp model/camera.h model/hittable.h model/geometry/sphere.cpp model/geometry/sphere.h model/scene.cpp model/scene.h utility/defines.h utility/random.h model/image.cpp model/image.h model/concurrency/base_thread.cpp model/concurrency/base_thread.h model/concurrency/draw_thread.cpp model/concurrency/draw_thread.h model/concurrency/lambda_thread.h utility/stopwatch.cpp utility/stopwatch.h model/concurrency/status_thread.h model/materials/material.h model/hit_record.h model/materials/lambertian.cpp model/materials/lambertian.h model/materials/metal.cpp model/materials/metal.h)