//
// Created by Matias Ignacio Levi Fernandez on 16/03/2021.
//

#ifndef RAYTRACER_LAMBDA_THREAD_H
#define RAYTRACER_LAMBDA_THREAD_H


#include "base_thread.h"

template<typename F>
class LambdaThread : public BaseThread {
    F function;

    LambdaThread(F &f);

    void _run() override;

};

template<typename F>
LambdaThread<F>::LambdaThread(F &f) {
    function = f;
}

template<typename F>
void LambdaThread<F>::_run() {
    f();
}


#endif //RAYTRACER_LAMBDA_THREAD_H
