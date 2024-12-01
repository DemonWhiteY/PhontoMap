#pragma once
#ifndef __DIRECT_HPP__
#define __DIRECT_HPP__

#include "Ray.hpp"

namespace SimplePathTracer
{
    struct Direct
    {
        Ray ray = {};
        Vec3 attenuation = {};
        Vec3 emitted = {};
        float pdf = { 0.f };
        Vec3 Light_normal = {};
        float distance = { 0.f };
    };

}

#endif