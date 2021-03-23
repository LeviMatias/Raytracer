//
// Created by Matias Ignacio Levi Fernandez on 18/03/2021.
//

#ifndef RAYTRACER_STATUS_THREAD_H
#define RAYTRACER_STATUS_THREAD_H


#include "base_thread.h"

class StatusThread : public BaseThread {
    void _run(){
        while (isAlive()){
            std::cerr << "\rWorking: " << std::flush;
            sleep(.5);
            for(int i =0; i < 3 && isAlive(); i++) {
                std::cerr << '.';
                sleep(.5);
            }
        }
    }
};


#endif //RAYTRACER_STATUS_THREAD_H
