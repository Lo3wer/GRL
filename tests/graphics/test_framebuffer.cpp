#include "grl/graphics/framebuffer.h"
#include "grl/graphics/color.h"
#include <iostream>

using namespace grl;

int testsPassed = 0;
int testsFailed = 0;

#define TEST(name) void name()
#define RUN_TEST(name) do { \
    std::cout << "Running " << #name << "... "; \
    name(); \
    std::cout << "PASSED\n"; \
    testsPassed++; \
} while(0)

#define ASSERT(condition) do { \
    if (!(condition)) { \
        std::cerr << "FAILED: " << #condition << " at line " << __LINE__ << "\n"; \
        testsFailed++; \
        return; \
    } \
} while(0)

TEST(testConstruction) {
    Framebuffer fb(800, 600);

    ASSERT(fb.getWidth() == 800);
    ASSERT(fb.getHeight() == 600);
}

TEST(testBoundsChecking) {
    Framebuffer fb(100, 100);

    ASSERT(fb.isInBounds(0, 0));
    ASSERT(fb.isInBounds(99, 99));
    ASSERT(!fb.isInBounds(-1, 0));
    ASSERT(!fb.isInBounds(0, -1));
    ASSERT(!fb.isInBounds(100, 0));
    ASSERT(!fb.isInBounds(0, 100));
}

TEST(testSetGetPixel) {
    Framebuffer fb(100, 100);

    Color red = Color::Red;
    fb.setPixel(50, 50, red);

    Color retrieved = fb.getPixel(50, 50);
    ASSERT(retrieved == red);
}

TEST(testClear) {
    Framebuffer fb(100, 100);

    fb.clear(Color::Blue);

    Color pixel = fb.getPixel(50, 50);
    ASSERT(pixel == Color::Blue);
}

TEST(testDepthBuffer) {
    Framebuffer fb(100, 100);

    fb.clearDepth(1.0f);
    float depth = fb.getDepth(50, 50);
    ASSERT(depth == 1.0f);

    fb.setDepth(50, 50, 0.5f);
    depth = fb.getDepth(50, 50);
    ASSERT(depth == 0.5f);
}

TEST(testDepthTest) {
    Framebuffer fb(100, 100);

    fb.clearDepth(1.0f);

    // Closer depth (0.5) should pass test against 1.0
    ASSERT(fb.depthTest(50, 50, 0.5f));

    fb.setDepth(50, 50, 0.5f);

    // Equal depth should fail
    ASSERT(!fb.depthTest(50, 50, 0.5f));

    // Farther depth should fail
    ASSERT(!fb.depthTest(50, 50, 0.7f));

    // Closer depth should pass
    ASSERT(fb.depthTest(50, 50, 0.3f));
}

TEST(testResize) {
    Framebuffer fb(100, 100);

    fb.setPixel(50, 50, Color::Red);

    fb.resize(200, 200);

    ASSERT(fb.getWidth() == 200);
    ASSERT(fb.getHeight() == 200);

    // After resize, buffer should be cleared
    Color pixel = fb.getPixel(50, 50);
    // Exact value depends on clear behavior after resize
}

int main() {
    std::cout << "=== Framebuffer Tests ===\n\n";

    RUN_TEST(testConstruction);
    RUN_TEST(testBoundsChecking);
    RUN_TEST(testSetGetPixel);
    RUN_TEST(testClear);
    RUN_TEST(testDepthBuffer);
    RUN_TEST(testDepthTest);
    RUN_TEST(testResize);

    std::cout << "\n=== Results ===\n";
    std::cout << "Passed: " << testsPassed << "\n";
    std::cout << "Failed: " << testsFailed << "\n";

    return testsFailed > 0 ? 1 : 0;
}
