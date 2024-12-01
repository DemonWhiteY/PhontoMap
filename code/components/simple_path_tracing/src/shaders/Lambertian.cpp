#include "shaders/Lambertian.hpp"
#include "samplers/SamplerInstance.hpp"

#include "Onb.hpp"

namespace SimplePathTracer
{
    Lambertian::Lambertian(Material& material, vector<Texture>& textures)
        : Shader                (material, textures)
    {
        auto diffuseColor = material.getProperty<Property::Wrapper::RGBType>("diffuseColor");
        if (diffuseColor) albedo = (*diffuseColor).value;
        else albedo = {1, 1, 1};
    }
    Scattered Lambertian::shade(const Ray& ray, const Vec3& hitPoint, const Vec3& normal) const {
        Vec3 origin = hitPoint;
        Vec3 random = defaultSamplerInstance<HemiSphere>().sample3d();
        Onb onb{normal};
        Vec3 direction = glm::normalize(onb.local(random));

        float pdf = 1/(2*PI);

        auto attenuation = albedo / PI;

        return {
            Ray{origin, direction},
            attenuation,
            Vec3{0},
            pdf
        };
    }
    Direct Lambertian::shade(const AreaLight a,const Vec3& hitPoint, const Vec3& normal) const {
        Vec3 origin = hitPoint;
        Vec2 random = defaultSamplerInstance<HemiSphere>().sample2d();
        Vec3 SampleLight = a.position + a.u * random.x + a.v * random.y;
        auto pdf_light = 1 / (glm::length(a.u) * glm::length(a.v));
        Vec3 direction = glm::normalize(origin - SampleLight);
        auto attenuation = albedo / PI;
        Vec3 Light_normal = glm::normalize(glm::cross(a.u, a.v));
        float distance = glm::dot(origin - SampleLight, origin - SampleLight);
        return {
            Ray{SampleLight, direction},
            attenuation,
            Vec3{0},
            pdf_light,
            Light_normal,
            distance

        };
    }
    
}