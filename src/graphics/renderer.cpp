#include "grl/graphics/renderer.h"

namespace grl {

// SoftwareRenderer implementation
SoftwareRenderer::SoftwareRenderer(int width, int height)
    : framebuffer_(width, height),
      rasterizer_(framebuffer_),
      initialized_(false) {}

SoftwareRenderer::~SoftwareRenderer() {
    if (initialized_) {
        shutdown();
    }
}

void SoftwareRenderer::initialize() {
    // TODO: Perform any initialization needed
    initialized_ = true;
}

void SoftwareRenderer::shutdown() {
    // TODO: Perform any cleanup needed
    initialized_ = false;
}

void SoftwareRenderer::beginFrame() {
    // TODO: Called at the start of each frame
    // You might want to clear buffers here, or leave that to the user
}

void SoftwareRenderer::endFrame() {
    // TODO: Called at the end of each frame
    // In software renderer, this might be a no-op
    // In windowed mode (Phase 3), this will present to screen
}

void SoftwareRenderer::clearColor(const Color& color) {
    framebuffer_.clear(color);
}

void SoftwareRenderer::clearDepth(float depth) {
    framebuffer_.clearDepth(depth);
}

void SoftwareRenderer::resize(int width, int height) {
    framebuffer_.resize(width, height);
}

} // namespace grl
