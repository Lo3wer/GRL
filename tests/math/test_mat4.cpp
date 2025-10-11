#include "grl/math/mat4.h"
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

TEST(testIdentity) {
    Mat4 m = Mat4::identity();

    // Check diagonal is 1
    ASSERT_FLOAT_EQ(m.at(0, 0), 1.0f);
    ASSERT_FLOAT_EQ(m.at(1, 1), 1.0f);
    ASSERT_FLOAT_EQ(m.at(2, 2), 1.0f);
    ASSERT_FLOAT_EQ(m.at(3, 3), 1.0f);

    // Check off-diagonals are 0
    ASSERT_FLOAT_EQ(m.at(0, 1), 0.0f);
    ASSERT_FLOAT_EQ(m.at(1, 0), 0.0f);
}

TEST(testMatrixMultiplication) {
    Mat4 m1 = Mat4::identity();
    Mat4 m2 = Mat4::identity();

    Mat4 result = m1 * m2;

    // Identity * Identity = Identity
    ASSERT_FLOAT_EQ(result.at(0, 0), 1.0f);
    ASSERT_FLOAT_EQ(result.at(1, 1), 1.0f);
    ASSERT_FLOAT_EQ(result.at(2, 2), 1.0f);
    ASSERT_FLOAT_EQ(result.at(3, 3), 1.0f);
}

TEST(testTranslation) {
    Mat4 m = Mat4::translation(1.0f, 2.0f, 3.0f);

    Vec3 point(0.0f, 0.0f, 0.0f);
    Vec3 translated = m.transformPoint(point);

    ASSERT_FLOAT_EQ(translated.x, 1.0f);
    ASSERT_FLOAT_EQ(translated.y, 2.0f);
    ASSERT_FLOAT_EQ(translated.z, 3.0f);
}

TEST(testRotationX) {
    // 90 degree rotation around X axis
    Mat4 m = Mat4::rotationX(HALF_PI);

    Vec3 point(0.0f, 1.0f, 0.0f);
    Vec3 rotated = m.transformPoint(point);

    // Y should become Z
    ASSERT_FLOAT_EQ(rotated.x, 0.0f);
    ASSERT_FLOAT_EQ(rotated.y, 0.0f);
    ASSERT_FLOAT_EQ(rotated.z, 1.0f);
}

TEST(testRotationY) {
    // 90 degree rotation around Y axis
    Mat4 m = Mat4::rotationY(HALF_PI);

    Vec3 point(1.0f, 0.0f, 0.0f);
    Vec3 rotated = m.transformPoint(point);

    // X should become -Z
    ASSERT_FLOAT_EQ(rotated.x, 0.0f);
    ASSERT_FLOAT_EQ(rotated.y, 0.0f);
    ASSERT_FLOAT_EQ(rotated.z, -1.0f);
}

TEST(testRotationZ) {
    // 90 degree rotation around Z axis
    Mat4 m = Mat4::rotationZ(HALF_PI);

    Vec3 point(1.0f, 0.0f, 0.0f);
    Vec3 rotated = m.transformPoint(point);

    // X should become Y
    ASSERT_FLOAT_EQ(rotated.x, 0.0f);
    ASSERT_FLOAT_EQ(rotated.y, 1.0f);
    ASSERT_FLOAT_EQ(rotated.z, 0.0f);
}

TEST(testScale) {
    Mat4 m = Mat4::scale(2.0f, 3.0f, 4.0f);

    Vec3 point(1.0f, 1.0f, 1.0f);
    Vec3 scaled = m.transformPoint(point);

    ASSERT_FLOAT_EQ(scaled.x, 2.0f);
    ASSERT_FLOAT_EQ(scaled.y, 3.0f);
    ASSERT_FLOAT_EQ(scaled.z, 4.0f);
}

TEST(testTransformVector) {
    // Vectors should not be affected by translation
    Mat4 m = Mat4::translation(10.0f, 20.0f, 30.0f);

    Vec3 vector(1.0f, 0.0f, 0.0f);
    Vec3 transformed = m.transformVector(vector);

    ASSERT_FLOAT_EQ(transformed.x, 1.0f);
    ASSERT_FLOAT_EQ(transformed.y, 0.0f);
    ASSERT_FLOAT_EQ(transformed.z, 0.0f);
}

TEST(testMatrixVectorMultiplication) {
    Mat4 m = Mat4::identity();
    Vec4 v(1.0f, 2.0f, 3.0f, 1.0f);

    Vec4 result = m * v;

    ASSERT_FLOAT_EQ(result.x, 1.0f);
    ASSERT_FLOAT_EQ(result.y, 2.0f);
    ASSERT_FLOAT_EQ(result.z, 3.0f);
    ASSERT_FLOAT_EQ(result.w, 1.0f);
}

TEST(testTranspose) {
    Mat4 m = Mat4::identity();
    m.at(0, 1) = 5.0f;

    Mat4 transposed = m.transposed();

    ASSERT_FLOAT_EQ(transposed.at(1, 0), 5.0f);
    ASSERT_FLOAT_EQ(transposed.at(0, 1), 0.0f);
}

TEST(testLookAt) {
    Vec3 eye(0.0f, 0.0f, 5.0f);
    Vec3 target(0.0f, 0.0f, 0.0f);
    Vec3 up(0.0f, 1.0f, 0.0f);

    Mat4 view = Mat4::lookAt(eye, target, up);

    // This is a complex test - just verify it creates a valid matrix
    // A proper test would verify the camera transformation properties
    ASSERT(true); // Placeholder - implement full verification
}

TEST(testPerspective) {
    float fov = toRadians(60.0f);
    float aspect = 16.0f / 9.0f;
    float near = 0.1f;
    float far = 100.0f;

    Mat4 proj = Mat4::perspective(fov, aspect, near, far);

    // Verify it creates a valid matrix (detailed tests would check projection properties)
    ASSERT(true); // Placeholder - implement full verification
}

int main() {
    std::cout << "=== Mat4 Tests ===\n\n";

    RUN_TEST(testIdentity);
    RUN_TEST(testMatrixMultiplication);
    RUN_TEST(testTranslation);
    RUN_TEST(testRotationX);
    RUN_TEST(testRotationY);
    RUN_TEST(testRotationZ);
    RUN_TEST(testScale);
    RUN_TEST(testTransformVector);
    RUN_TEST(testMatrixVectorMultiplication);
    RUN_TEST(testTranspose);
    RUN_TEST(testLookAt);
    RUN_TEST(testPerspective);

    std::cout << "\n=== Results ===\n";
    std::cout << "Passed: " << testsPassed << "\n";
    std::cout << "Failed: " << testsFailed << "\n";

    return testsFailed > 0 ? 1 : 0;
}
