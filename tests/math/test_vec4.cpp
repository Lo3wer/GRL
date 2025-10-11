#include "grl/math/vec4.h"
#include "grl/core/types.h"
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

#define ASSERT_FLOAT_EQ(a, b) ASSERT(floatEqual(a, b))

TEST(testConstructors) {
    Vec4 v1;
    ASSERT_FLOAT_EQ(v1.x, 0.0f);
    ASSERT_FLOAT_EQ(v1.y, 0.0f);
    ASSERT_FLOAT_EQ(v1.z, 0.0f);
    ASSERT_FLOAT_EQ(v1.w, 0.0f);

    Vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
    ASSERT_FLOAT_EQ(v2.x, 1.0f);
    ASSERT_FLOAT_EQ(v2.y, 2.0f);
    ASSERT_FLOAT_EQ(v2.z, 3.0f);
    ASSERT_FLOAT_EQ(v2.w, 4.0f);

    Vec4 v3(5.0f);
    ASSERT_FLOAT_EQ(v3.x, 5.0f);
    ASSERT_FLOAT_EQ(v3.y, 5.0f);
    ASSERT_FLOAT_EQ(v3.z, 5.0f);
    ASSERT_FLOAT_EQ(v3.w, 5.0f);

    Vec3 v3d(1.0f, 2.0f, 3.0f);
    Vec4 v4(v3d, 1.0f);
    ASSERT_FLOAT_EQ(v4.x, 1.0f);
    ASSERT_FLOAT_EQ(v4.y, 2.0f);
    ASSERT_FLOAT_EQ(v4.z, 3.0f);
    ASSERT_FLOAT_EQ(v4.w, 1.0f);
}

TEST(testArithmetic) {
    Vec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v2(5.0f, 6.0f, 7.0f, 8.0f);

    Vec4 sum = v1 + v2;
    ASSERT_FLOAT_EQ(sum.x, 6.0f);
    ASSERT_FLOAT_EQ(sum.y, 8.0f);
    ASSERT_FLOAT_EQ(sum.z, 10.0f);
    ASSERT_FLOAT_EQ(sum.w, 12.0f);

    Vec4 diff = v2 - v1;
    ASSERT_FLOAT_EQ(diff.x, 4.0f);
    ASSERT_FLOAT_EQ(diff.y, 4.0f);
    ASSERT_FLOAT_EQ(diff.z, 4.0f);
    ASSERT_FLOAT_EQ(diff.w, 4.0f);
}

TEST(testDotProduct) {
    Vec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v2(5.0f, 6.0f, 7.0f, 8.0f);

    float result = v1.dot(v2);
    // 1*5 + 2*6 + 3*7 + 4*8 = 5 + 12 + 21 + 32 = 70
    ASSERT_FLOAT_EQ(result, 70.0f);
}

TEST(testLength) {
    Vec4 v(2.0f, 0.0f, 0.0f, 0.0f);
    ASSERT_FLOAT_EQ(v.length(), 2.0f);
    ASSERT_FLOAT_EQ(v.lengthSquared(), 4.0f);
}

TEST(testNormalize) {
    Vec4 v(3.0f, 4.0f, 0.0f, 0.0f);
    Vec4 normalized = v.normalized();

    ASSERT_FLOAT_EQ(normalized.length(), 1.0f);

    v.normalize();
    ASSERT_FLOAT_EQ(v.length(), 1.0f);
}

TEST(testXYZ) {
    Vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    Vec3 xyz = v.xyz();

    ASSERT_FLOAT_EQ(xyz.x, 1.0f);
    ASSERT_FLOAT_EQ(xyz.y, 2.0f);
    ASSERT_FLOAT_EQ(xyz.z, 3.0f);
}

TEST(testArrayAccess) {
    Vec4 v(1.0f, 2.0f, 3.0f, 4.0f);

    ASSERT_FLOAT_EQ(v[0], 1.0f);
    ASSERT_FLOAT_EQ(v[1], 2.0f);
    ASSERT_FLOAT_EQ(v[2], 3.0f);
    ASSERT_FLOAT_EQ(v[3], 4.0f);

    v[0] = 10.0f;
    ASSERT_FLOAT_EQ(v.x, 10.0f);
}

int main() {
    std::cout << "=== Vec4 Tests ===\n\n";

    RUN_TEST(testConstructors);
    RUN_TEST(testArithmetic);
    RUN_TEST(testDotProduct);
    RUN_TEST(testLength);
    RUN_TEST(testNormalize);
    RUN_TEST(testXYZ);
    RUN_TEST(testArrayAccess);

    std::cout << "\n=== Results ===\n";
    std::cout << "Passed: " << testsPassed << "\n";
    std::cout << "Failed: " << testsFailed << "\n";

    return testsFailed > 0 ? 1 : 0;
}
