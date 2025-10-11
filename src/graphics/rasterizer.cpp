#include "grl/graphics/rasterizer.h"
#include <algorithm>
#include <cmath>

namespace grl {

Rasterizer::Rasterizer(Framebuffer& framebuffer)
    : framebuffer_(framebuffer), wireframeMode_(false) {}

// Line drawing
void Rasterizer::drawLine(int x0, int y0, int x1, int y1, const Color& color) {
    // TODO: Implement Bresenham's line drawing algorithm
}

void Rasterizer::drawLine(const Vec3& p0, const Vec3& p1, const Color& color) {
    // Convert to integer coordinates and call the other overload
    drawLine(static_cast<int>(p0.x), static_cast<int>(p0.y),
             static_cast<int>(p1.x), static_cast<int>(p1.y), color);
}

// Triangle rasterization (basic)
void Rasterizer::drawTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2,
                              const Color& c0, const Color& c1, const Color& c2) {
    drawTriangle(v0, v1, v2, c0, c1, c2, false);
}

// Triangle rasterization (with depth testing)
void Rasterizer::drawTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2,
                              const Color& c0, const Color& c1, const Color& c2,
                              bool useDepthTest) {
    // TODO: Implement triangle rasterization using edge functions
    // Steps:
    // 1. Calculate bounding box
    // 2. For each pixel in bounding box:
    //    a. Calculate barycentric coordinates
    //    b. If inside triangle (all barycentric coords >= 0):
    //       - Interpolate color
    //       - If useDepthTest: interpolate depth and perform depth test
    //       - Set pixel color
}

// Helper: Edge function
float Rasterizer::edgeFunction(const Vec3& a, const Vec3& b, const Vec3& p) const {
    // TODO: Implement edge function
    // Returns: (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x)
    return 0.0f;
}

// Helper: Barycentric coordinates
Vec3 Rasterizer::barycentric(const Vec3& v0, const Vec3& v1, const Vec3& v2,
                             const Vec3& p) const {
    // TODO: Calculate barycentric coordinates using edge functions
    // Return Vec3(w0, w1, w2) where w0 + w1 + w2 = 1
    return Vec3();
}

// Helper: Interpolate color
Color Rasterizer::interpolateColor(const Color& c0, const Color& c1, const Color& c2,
                                   const Vec3& bary) const {
    // TODO: Interpolate color using barycentric coordinates
    // Convert colors to Vec3, interpolate, convert back
    return Color();
}

// Helper: Interpolate depth
float Rasterizer::interpolateDepth(float z0, float z1, float z2,
                                   const Vec3& bary) const {
    // TODO: Interpolate depth value using barycentric coordinates
    return 0.0f;
}

} // namespace grl
