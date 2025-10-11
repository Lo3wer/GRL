#pragma once

#include <memory>
#include "grl/graphics/framebuffer.h"
#include "grl/graphics/rasterizer.h"

namespace grl {

/**
 * Abstract renderer interface
 * This allows us to swap between different rendering backends
 * (Software, Vulkan, etc.) in future phases
 */
class Renderer {
public:
    virtual ~Renderer() = default;

    // Lifecycle
    virtual void initialize() = 0;
    virtual void shutdown() = 0;

    // Frame operations
    virtual void beginFrame() = 0;
    virtual void endFrame() = 0;

    // Clear operations
    virtual void clearColor(const Color& color) = 0;
    virtual void clearDepth(float depth = 1.0f) = 0;

    // Accessors
    virtual Framebuffer& getFramebuffer() = 0;
    virtual const Framebuffer& getFramebuffer() const = 0;

    // Configuration
    virtual void resize(int width, int height) = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
};

/**
 * Software renderer implementation
 * Uses CPU-based rasterization
 */
class SoftwareRenderer : public Renderer {
public:
    SoftwareRenderer(int width, int height);
    ~SoftwareRenderer() override;

    // Renderer interface
    void initialize() override;
    void shutdown() override;
    void beginFrame() override;
    void endFrame() override;
    void clearColor(const Color& color) override;
    void clearDepth(float depth = 1.0f) override;

    Framebuffer& getFramebuffer() override { return framebuffer_; }
    const Framebuffer& getFramebuffer() const override { return framebuffer_; }

    void resize(int width, int height) override;
    int getWidth() const override { return framebuffer_.getWidth(); }
    int getHeight() const override { return framebuffer_.getHeight(); }

    // Software renderer specific
    Rasterizer& getRasterizer() { return rasterizer_; }
    const Rasterizer& getRasterizer() const { return rasterizer_; }

private:
    Framebuffer framebuffer_;
    Rasterizer rasterizer_;
    bool initialized_;
};

} // namespace grl
