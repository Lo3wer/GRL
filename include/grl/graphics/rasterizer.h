#pragma once

#include "grl/graphics/framebuffer.h"
#include "grl/graphics/color.h"
#include "grl/math/vec3.h"

namespace grl {

/**
 * Software rasterizer for drawing primitives to a framebuffer
 */
class Rasterizer {
public:
    explicit Rasterizer(Framebuffer& framebuffer);
    ~Rasterizer() = default;

    // Line drawing
    void drawLine(int x0, int y0, int x1, int y1, const Color& color);
    void drawLine(const Vec3& p0, const Vec3& p1, const Color& color);

    // Triangle rasterization
    // Basic version (Week 3): screen-space vertices with color interpolation
    void drawTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2,
                     const Color& c0, const Color& c1, const Color& c2);

    // Advanced version (Week 5+): with depth testing
    void drawTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2,
                     const Color& c0, const Color& c1, const Color& c2,
                     bool useDepthTest);

    // Configuration
    void setWireframeMode(bool enabled) { wireframeMode_ = enabled; }
    bool isWireframeMode() const { return wireframeMode_; }

private:
    Framebuffer& framebuffer_;
    bool wireframeMode_;

    // Helper functions

    // Edge function for triangle rasterization
    // Returns positive if point p is on the right side of edge from a to b
    float edgeFunction(const Vec3& a, const Vec3& b, const Vec3& p) const;

    // Calculate barycentric coordinates of point p relative to triangle (v0, v1, v2)
    // Returns Vec3 where x=w0, y=w1, z=w2 (weights for v0, v1, v2)
    Vec3 barycentric(const Vec3& v0, const Vec3& v1, const Vec3& v2,
                     const Vec3& p) const;

    // Interpolate color using barycentric coordinates
    Color interpolateColor(const Color& c0, const Color& c1, const Color& c2,
                          const Vec3& bary) const;

    // Interpolate depth value using barycentric coordinates
    float interpolateDepth(float z0, float z1, float z2,
                          const Vec3& bary) const;
};

} // namespace grl
