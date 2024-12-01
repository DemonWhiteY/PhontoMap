#pragma once
#ifndef __HEMI_SPHERE_HPP__
#define __HEMI_SPHERE_HPP__

#include "Sampler3d.hpp"
#include"Sampler2d.hpp"
#include"Sampler1d.hpp"
#include <ctime>

namespace SimplePathTracer
{
    using namespace std;
    class HemiSphere : public Sampler3d
    {
    private:
        constexpr static float C_PI = 3.14159265358979323846264338327950288f;
        
        default_random_engine e;
        uniform_real_distribution<float> u;
    public:
        HemiSphere()
            : e               ((unsigned int)time(0) + insideSeed())
            , u               (0, 1)
        {}
        float sample1d() {
            float x = u(e);
           

            return x;
        }
        Vec2 sample2d(){
            float x = u(e);
            float y = u(e);

            return{x,y};
        }
        Vec3 sample3d() override {
            float epsilon1 = u(e);
            float epsilon2 = u(e);
            float r = sqrt(1 - epsilon1 * epsilon1);
            float x = cos(2*C_PI*epsilon2) * r;
            float y = sin(2*C_PI*epsilon2) * r;
            float z = epsilon1;
            return { x, y, z };
        }

        
    };
}

#endif