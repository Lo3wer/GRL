#include "grl/utils/image_writer.h"
#include <fstream>

namespace grl {

bool ImageWriter::savePPM(const std::string& filename, const Framebuffer& framebuffer) {
    // TODO: Implement PPM file writing
    // PPM format (P3 - ASCII or P6 - binary):
    // Header: P3\n<width> <height>\n255\n
    // Then: R G B values for each pixel (row by row, top to bottom)

    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    // TODO: Write PPM header
    // TODO: Write pixel data

    file.close();
    return true;
}

bool ImageWriter::savePNG(const std::string& filename, const Framebuffer& framebuffer) {
    // TODO: Implement PNG saving (Phase 4 - requires stb_image_write.h)
    // For now, just return false
    return false;
}

} // namespace grl
