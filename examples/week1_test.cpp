#include <iostream>
#include "grl/math/vec3.h"
#include "grl/math/vec4.h"
#include "grl/math/mat4.h"
#include "grl/graphics/color.h"
#include "grl/graphics/framebuffer.h"
#include "grl/graphics/renderer.h"
#include "grl/utils/image_writer.h"

using namespace grl;

int main() {
    std::cout << "=== GRL Week 1 Test Program ===\n\n";

    // Test Vec3
    std::cout << "Testing Vec3...\n";
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1 + v2;
    std::cout << "  v1 + v2 = " << v3 << "\n";
    std::cout << "  dot(v1, v2) = " << v1.dot(v2) << "\n";
    std::cout << "  cross(v1, v2) = " << v1.cross(v2) << "\n";
    std::cout << "  v1.length() = " << v1.length() << "\n\n";

    // Test Vec4
    std::cout << "Testing Vec4...\n";
    Vec4 v4(1.0f, 2.0f, 3.0f, 1.0f);
    std::cout << "  v4 = " << v4 << "\n";
    std::cout << "  v4.xyz() = " << v4.xyz() << "\n\n";

    // Test Mat4
    std::cout << "Testing Mat4...\n";
    Mat4 identity = Mat4::identity();
    std::cout << "  Identity matrix created\n";

    Mat4 translation = Mat4::translation(1.0f, 2.0f, 3.0f);
    Vec3 point(0.0f, 0.0f, 0.0f);
    Vec3 translated = translation.transformPoint(point);
    std::cout << "  Translation result: " << translated << "\n";

    Mat4 scale = Mat4::scale(2.0f);
    Vec3 scaled = scale.transformPoint(Vec3(1.0f, 1.0f, 1.0f));
    std::cout << "  Scale result: " << scaled << "\n\n";

    // Test Color
    std::cout << "Testing Color...\n";
    Color red = Color::Red;
    Color blue = Color::Blue;
    std::cout << "  Red: (" << (int)red.r << ", " << (int)red.g << ", " << (int)red.b << ")\n";
    std::cout << "  Blue: (" << (int)blue.r << ", " << (int)blue.g << ", " << (int)blue.b << ")\n\n";

    // Test Framebuffer
    std::cout << "Testing Framebuffer...\n";
    Framebuffer fb(800, 600);
    std::cout << "  Created " << fb.getWidth() << "x" << fb.getHeight() << " framebuffer\n";

    fb.clear(Color::Black);
    fb.setPixel(100, 100, Color::Red);
    Color retrieved = fb.getPixel(100, 100);
    std::cout << "  Set and retrieved pixel successfully\n\n";

    // Test Renderer
    std::cout << "Testing SoftwareRenderer...\n";
    SoftwareRenderer renderer(640, 480);
    renderer.initialize();
    renderer.clearColor(Color(50, 50, 50));
    std::cout << "  Renderer initialized and cleared\n";
    renderer.shutdown();

    // Save a simple test image
    std::cout << "\nGenerating test image...\n";
    Framebuffer testFb(200, 200);
    testFb.clear(Color::Black);

    // Draw a simple pattern (once you implement setPixel properly)
    for (int y = 0; y < 200; y++) {
        for (int x = 0; x < 200; x++) {
            if ((x / 20 + y / 20) % 2 == 0) {
                testFb.setPixel(x, y, Color::White);
            }
        }
    }

    if (ImageWriter::savePPM("test_output.ppm", testFb)) {
        std::cout << "  Test image saved to test_output.ppm\n";
    } else {
        std::cout << "  Failed to save test image\n";
    }

    std::cout << "\n=== All tests completed! ===\n";
    std::cout << "\nNext steps:\n";
    std::cout << "1. Implement all the TODO methods in src/math/ and src/graphics/\n";
    std::cout << "2. Run the unit tests: cmake --build build && ctest --test-dir build\n";
    std::cout << "3. Verify this example program works correctly\n";
    std::cout << "4. Move on to Week 2: Framebuffer & Line Drawing\n";

    return 0;
}
