#pragma once

#include <string>
#include "grl/graphics/framebuffer.h"

namespace grl {

/**
 * Utility class for writing images to various formats
 */
class ImageWriter {
public:
    /**
     * Save framebuffer to PPM format (Portable Pixmap)
     * PPM is a simple, uncompressed format that's easy to implement
     * and can be viewed with most image viewers
     *
     * @param filename Output file path (e.g., "output.ppm")
     * @param framebuffer The framebuffer to save
     * @return true if successful, false otherwise
     */
    static bool savePPM(const std::string& filename, const Framebuffer& framebuffer);

    /**
     * Save framebuffer to PNG format (requires stb_image_write.h)
     * To be implemented in Phase 4 when we integrate stb libraries
     *
     * @param filename Output file path (e.g., "output.png")
     * @param framebuffer The framebuffer to save
     * @return true if successful, false otherwise
     */
    static bool savePNG(const std::string& filename, const Framebuffer& framebuffer);

private:
    ImageWriter() = delete; // Static class, no instantiation
};

} // namespace grl
