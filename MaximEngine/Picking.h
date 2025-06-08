#include <optional>
#include <limits>
#include <Tools.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>

struct TriangleGLM {

    glm::vec4 a;
    glm::vec4 b;
    glm::vec4 c;


};

struct Triangle {

    VulkanCookbook::Vector3 a;
    VulkanCookbook::Vector3 b;
    VulkanCookbook::Vector3 c;


};

using namespace VulkanCookbook;

std::optional<VulkanCookbook::Vector3> ray_intersects_triangle( const VulkanCookbook::Vector3 &ray_origin,
    const VulkanCookbook::Vector3 &ray_vector,
    const float* mesh, int nbrFloat, glm::mat4 world)
{
    constexpr float epsilon = std::numeric_limits<float>::epsilon();
    
    int nbrVertices = nbrFloat / 14;

    int nbrTriangles = nbrVertices/3;

    for(int i = 0; i < nbrTriangles; i++)
    {
        TriangleGLM triangle2;

        triangle2.a[0] = mesh[42*i+0];
        triangle2.a[1] = mesh[42*i+1];
        triangle2.a[2] = mesh[42*i+2];
        triangle2.a[3] = 1.0f;
        
        triangle2.b[0] = mesh[42*i+14];
        triangle2.b[1] = mesh[42*i+15];
        triangle2.b[2] = mesh[42*i+16];
        triangle2.b[3] = 1.0f;

        triangle2.c[0] = mesh[42*i+28];
        triangle2.c[1] = mesh[42*i+29];
        triangle2.c[2] = mesh[42*i+30];
        triangle2.c[3] = 1.0f;

        triangle2.a = world * triangle2.a;
        triangle2.b = world * triangle2.b;
        triangle2.c = world * triangle2.c;

        Triangle triangle;

        triangle.a = Vector3{triangle2.a[0], triangle2.a[1], triangle2.a[2]};
        triangle.b = Vector3{triangle2.b[0], triangle2.b[1], triangle2.b[2]};
        triangle.c = Vector3{triangle2.c[0], triangle2.c[1], triangle2.c[2]};
        
        VulkanCookbook::Vector3 edge1 = triangle.b - triangle.a;
        VulkanCookbook::Vector3 edge2 = triangle.c - triangle.a;
        VulkanCookbook::Vector3 ray_cross_e2 = VulkanCookbook::Cross(ray_vector, edge2);
        float det = VulkanCookbook::Dot(edge1, ray_cross_e2);

        if (det > -epsilon && det < epsilon)
            continue;    // This ray is parallel to this triangle.

        float inv_det = 1.0 / det;
        VulkanCookbook::Vector3 s = ray_origin - triangle.a;
        float u = inv_det * VulkanCookbook::Dot(s, ray_cross_e2);

        if ((u < 0 && abs(u) > epsilon) || (u > 1 && abs(u-1) > epsilon))
            continue;

            VulkanCookbook::Vector3 s_cross_e1 = VulkanCookbook::Cross(s, edge1);
        float v = inv_det * VulkanCookbook::Dot(ray_vector, s_cross_e1);

        if ((v < 0 && abs(v) > epsilon) || (u + v > 1 && abs(u + v - 1) > epsilon))
            continue;

        // At this stage we can compute t to find out where the intersection point is on the line.
        float t = inv_det * VulkanCookbook::Dot(edge2, s_cross_e1);

        if (t > epsilon) // ray intersection
        {
            return  VulkanCookbook::Vector3(ray_origin + ray_vector * t);
        }
        else // This means that there is a line intersection but not a ray intersection.
            return {};
    }

    return {};
}