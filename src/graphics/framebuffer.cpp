#include "grl/graphics/framebuffer.h"
#include <algorithm>

namespace grl {

// Constructor
Framebuffer::Framebuffer(int width, int height)
    : width_(width), height_(height) {
    // TODO: Initialize color and depth buffers with correct size
    colorBuffer_.resize(width * height, 0);
    depthBuffer_.resize(width * height, 1.0f);
}

// Color buffer operations
void Framebuffer::clear(const Color& color) {
    // TODO: Fill entire color buffer with given color
}

void Framebuffer::setPixel(int x, int y, const Color& color) {
    // TODO: Set pixel at (x, y) to given color (with bounds check)
}

Color Framebuffer::getPixel(int x, int y) const {
    // TODO: Get pixel color at (x, y) (with bounds check)
    return Color::Black;
}

// Depth buffer operations
void Framebuffer::clearDepth(float depth) {
    // TODO: Fill entire depth buffer with given value
}

void Framebuffer::setDepth(int x, int y, float depth) {
    // TODO: Set depth at (x, y) (with bounds check)
}

float Framebuffer::getDepth(int x, int y) const {
    // TODO: Get depth at (x, y) (with bounds check)
    return 1.0f;
}

bool Framebuffer::depthTest(int x, int y, float depth) const {
    // TODO: Return true if depth < current depth at (x, y)
    return false;
}

// Bounds checking
bool Framebuffer::isInBounds(int x, int y) const {
    // TODO: Check if (x, y) is within framebuffer bounds
    return false;
}

// Resize framebuffer
void Framebuffer::resize(int width, int height) {
    // TODO: Resize buffers and clear them
    width_ = width;
    height_ = height;
    colorBuffer_.resize(width * height, 0);
    depthBuffer_.resize(width * height, 1.0f);
}

} // namespace grl
