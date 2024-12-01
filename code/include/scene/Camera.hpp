#pragma once
#ifndef __NR_CAMERA_HPP__
#define __NR_CAMERA_HPP__


#include <memory>

#include "geometry/vec.hpp"

namespace NRenderer
{
    using namespace std;
    struct Camera
    {
        Vec3 position;
        Vec3 up;
        Vec3 lookAt;
        float fov;
        float aperture;
        float focusDistance;
        float aspect;
        Camera() noexcept
            : position      (0.f, 0.f, -3.f)
            , up            (0.f, 1.f, 0.f)
            , lookAt        (0.f, 0.f, 0.f)
            , fov           (40)
            , aperture      (0.f)
            , focusDistance (0.1f)
            , aspect        (1.f)
        {}
        Camera(
            const Vec3& position,
            const Vec3& up,
            const Vec3& lookAt,
            float fov,
            float aperture,
            float focusDistance,
            float aspect
        )
            : position      (position)
            , up            (up)
            , lookAt        (lookAt)
            , fov           (fov)
            , aperture      (aperture)
            , focusDistance (focusDistance)
            , aspect        (aspect)
        {}
    };
    using SharedCamera = shared_ptr<Camera>;
    
}

#endif
