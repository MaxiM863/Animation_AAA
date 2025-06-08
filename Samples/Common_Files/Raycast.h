#include <optional>
#include <Tools.h>

using namespace VulkanCookbook;

struct triangle3 {

    Vector3 a;
    Vector3 b;
    Vector3 c;
};

std::optional<Vector3> ray_intersects_triangle( const Vector3 &ray_origin, const Vector3 &ray_vector, const triangle3* triangle, int nbrTriangles)
{
    constexpr float epsilon = std::numeric_limits<float>::epsilon();



    for(int i = 0; i < nbrTriangles; i++) {
       
        Vector3 edge1 = triangle[i].b - triangle[i].a;
        Vector3 edge2 = triangle[i].c - triangle[i].a;
        Vector3 ray_cross_e2 = Cross(ray_vector, edge2);
        float det = Dot(edge1, ray_cross_e2);

        if (det > -epsilon && det < epsilon)
            continue;    // This ray is parallel to this triangle.

        float inv_det = 1.0f / det;
        Vector3 s = ray_origin - triangle[i].a;
        float u = inv_det * Dot(s, ray_cross_e2);

        if ((u < 0 && abs(u) > epsilon) || (u > 1 && abs(u-1) > epsilon))
            continue;

        Vector3 s_cross_e1 = Cross(s, edge1);
        float v = inv_det * Dot(ray_vector, s_cross_e1);

        if ((v < 0 && abs(v) > epsilon) || (u + v > 1 && abs(u + v - 1) > epsilon))
            continue;

        // At this stage we can compute t to find out where the intersection point is on the line.
        float t = inv_det * Dot(edge2, s_cross_e1);

        if (t > epsilon) // ray intersection
        {
            return  Vector3(ray_origin + ray_vector * t);
        }
    }
        
    return {};
}