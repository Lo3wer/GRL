#pragma once

#include <vector>
#include <cstdint>
#include "grl/graphics/color.h"

namespace grl {

/**
 * Framebuffer class for storing rendered image data
 * Includes both color buffer and depth buffer
 */
class Framebuffer {
public:
    // Constructor
    Framebuffer(int width, int height);
    ~Framebuffer() = default;

    // Disable copying (can be expensive)
    Framebuffer(const Framebuffer&) = delete;
    Framebuffer& operator=(const Framebuffer&) = delete;

    // Enable moving
    Framebuffer(Framebuffer&&) noexcept = default;
    Framebuffer& operator=(Framebuffer&&) noexcept = default;

    // Color buffer operations
    void clear(const Color& color);
    void setPixel(int x, int y, const Color& color);
    Color getPixel(int x, int y) const;

    // Depth buffer operations
    void clearDepth(float depth = 1.0f);
    void setDepth(int x, int y, float depth);
    float getDepth(int x, int y) const;
    bool depthTest(int x, int y, float depth) const;

    // Bounds checking
    bool isInBounds(int x, int y) const;

    // Accessors
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    const uint32_t* getColorData() const { return colorBuffer_.data(); }
    const float* getDepthData() const { return depthBuffer_.data(); }

    // Direct buffer access (for advanced use)
    uint32_t* getColorDataMutable() { return colorBuffer_.data(); }
    float* getDepthDataMutable() { return depthBuffer_.data(); }

    // Resize framebuffer (clears all data)
    void resize(int width, int height);

private:
    int width_;
    int height_;
    std::vector<uint32_t> colorBuffer_;
    std::vector<float> depthBuffer_;

    // Helper to get linear index from 2D coordinates
    inline int getIndex(int x, int y) const {
        return y * width_ + x;
    }
};

} // namespace grl
