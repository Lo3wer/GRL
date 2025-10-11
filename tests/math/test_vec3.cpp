#include "grl/math/vec3.h"
#include "grl/core/types.h"
#include <iostream>
#include <cmath>

using namespace grl;

// Simple test framework
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
#define ASSERT_VEC3_EQ(v1, v2) do { \
    ASSERT_FLOAT_EQ(v1.x, v2.x); \
    ASSERT_FLOAT_EQ(v1.y, v2.y); \
    ASSERT_FLOAT_EQ(v1.z, v2.z); \
} while(0)

// Test cases

TEST(testConstructors) {
    Vec3 v1;
    ASSERT_FLOAT_EQ(v1.x, 0.0f);
    ASSERT_FLOAT_EQ(v1.y, 0.0f);
    ASSERT_FLOAT_EQ(v1.z, 0.0f);

    Vec3 v2(1.0f, 2.0f, 3.0f);
    ASSERT_FLOAT_EQ(v2.x, 1.0f);
    ASSERT_FLOAT_EQ(v2.y, 2.0f);
    ASSERT_FLOAT_EQ(v2.z, 3.0f);

    Vec3 v3(5.0f);
    ASSERT_FLOAT_EQ(v3.x, 5.0f);
    ASSERT_FLOAT_EQ(v3.y, 5.0f);
    ASSERT_FLOAT_EQ(v3.z, 5.0f);
}

TEST(testAddition) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 result = v1 + v2;

    ASSERT_FLOAT_EQ(result.x, 5.0f);
    ASSERT_FLOAT_EQ(result.y, 7.0f);
    ASSERT_FLOAT_EQ(result.z, 9.0f);
}

TEST(testSubtraction) {
    Vec3 v1(5.0f, 7.0f, 9.0f);
    Vec3 v2(1.0f, 2.0f, 3.0f);
    Vec3 result = v1 - v2;

    ASSERT_FLOAT_EQ(result.x, 4.0f);
    ASSERT_FLOAT_EQ(result.y, 5.0f);
    ASSERT_FLOAT_EQ(result.z, 6.0f);
}

TEST(testScalarMultiplication) {
    Vec3 v(1.0f, 2.0f, 3.0f);
    Vec3 result = v * 2.0f;

    ASSERT_FLOAT_EQ(result.x, 2.0f);
    ASSERT_FLOAT_EQ(result.y, 4.0f);
    ASSERT_FLOAT_EQ(result.z, 6.0f);

    // Test commutative property
    Vec3 result2 = 2.0f * v;
    ASSERT_VEC3_EQ(result, result2);
}

TEST(testScalarDivision) {
    Vec3 v(2.0f, 4.0f, 6.0f);
    Vec3 result = v / 2.0f;

    ASSERT_FLOAT_EQ(result.x, 1.0f);
    ASSERT_FLOAT_EQ(result.y, 2.0f);
    ASSERT_FLOAT_EQ(result.z, 3.0f);
}

TEST(testNegation) {
    Vec3 v(1.0f, -2.0f, 3.0f);
    Vec3 result = -v;

    ASSERT_FLOAT_EQ(result.x, -1.0f);
    ASSERT_FLOAT_EQ(result.y, 2.0f);
    ASSERT_FLOAT_EQ(result.z, -3.0f);
}

TEST(testCompoundOperators) {
    Vec3 v(1.0f, 2.0f, 3.0f);

    v += Vec3(1.0f, 1.0f, 1.0f);
    ASSERT_FLOAT_EQ(v.x, 2.0f);
    ASSERT_FLOAT_EQ(v.y, 3.0f);
    ASSERT_FLOAT_EQ(v.z, 4.0f);

    v -= Vec3(1.0f, 1.0f, 1.0f);
    ASSERT_FLOAT_EQ(v.x, 1.0f);
    ASSERT_FLOAT_EQ(v.y, 2.0f);
    ASSERT_FLOAT_EQ(v.z, 3.0f);

    v *= 2.0f;
    ASSERT_FLOAT_EQ(v.x, 2.0f);
    ASSERT_FLOAT_EQ(v.y, 4.0f);
    ASSERT_FLOAT_EQ(v.z, 6.0f);

    v /= 2.0f;
    ASSERT_FLOAT_EQ(v.x, 1.0f);
    ASSERT_FLOAT_EQ(v.y, 2.0f);
    ASSERT_FLOAT_EQ(v.z, 3.0f);
}

TEST(testDotProduct) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    float result = v1.dot(v2);

    // 1*4 + 2*5 + 3*6 = 4 + 10 + 18 = 32
    ASSERT_FLOAT_EQ(result, 32.0f);

    // Test with free function
    ASSERT_FLOAT_EQ(dot(v1, v2), result);
}

TEST(testCrossProduct) {
    Vec3 v1(1.0f, 0.0f, 0.0f);
    Vec3 v2(0.0f, 1.0f, 0.0f);
    Vec3 result = v1.cross(v2);

    // i × j = k
    ASSERT_FLOAT_EQ(result.x, 0.0f);
    ASSERT_FLOAT_EQ(result.y, 0.0f);
    ASSERT_FLOAT_EQ(result.z, 1.0f);

    // Test with free function
    Vec3 result2 = cross(v1, v2);
    ASSERT_VEC3_EQ(result, result2);
}

TEST(testLength) {
    Vec3 v(3.0f, 4.0f, 0.0f);
    float len = v.length();

    // 3-4-5 triangle
    ASSERT_FLOAT_EQ(len, 5.0f);

    float lenSq = v.lengthSquared();
    ASSERT_FLOAT_EQ(lenSq, 25.0f);
}

TEST(testNormalize) {
    Vec3 v(3.0f, 4.0f, 0.0f);
    Vec3 normalized = v.normalized();

    ASSERT_FLOAT_EQ(normalized.length(), 1.0f);
    ASSERT_FLOAT_EQ(normalized.x, 0.6f);
    ASSERT_FLOAT_EQ(normalized.y, 0.8f);
    ASSERT_FLOAT_EQ(normalized.z, 0.0f);

    // Original should be unchanged
    ASSERT_FLOAT_EQ(v.length(), 5.0f);

    // Test in-place normalization
    v.normalize();
    ASSERT_FLOAT_EQ(v.length(), 1.0f);
}

TEST(testArrayAccess) {
    Vec3 v(1.0f, 2.0f, 3.0f);

    ASSERT_FLOAT_EQ(v[0], 1.0f);
    ASSERT_FLOAT_EQ(v[1], 2.0f);
    ASSERT_FLOAT_EQ(v[2], 3.0f);

    v[0] = 10.0f;
    ASSERT_FLOAT_EQ(v.x, 10.0f);
}

TEST(testStaticMethods) {
    Vec3 zero = Vec3::zero();
    ASSERT_FLOAT_EQ(zero.x, 0.0f);
    ASSERT_FLOAT_EQ(zero.y, 0.0f);
    ASSERT_FLOAT_EQ(zero.z, 0.0f);

    Vec3 one = Vec3::one();
    ASSERT_FLOAT_EQ(one.x, 1.0f);
    ASSERT_FLOAT_EQ(one.y, 1.0f);
    ASSERT_FLOAT_EQ(one.z, 1.0f);

    Vec3 unitX = Vec3::unitX();
    ASSERT_FLOAT_EQ(unitX.x, 1.0f);
    ASSERT_FLOAT_EQ(unitX.y, 0.0f);
    ASSERT_FLOAT_EQ(unitX.z, 0.0f);
}

TEST(testEquality) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(1.0f, 2.0f, 3.0f);
    Vec3 v3(1.0f, 2.0f, 4.0f);

    ASSERT(v1 == v2);
    ASSERT(v1 != v3);
}

TEST(testLerp) {
    Vec3 a(0.0f, 0.0f, 0.0f);
    Vec3 b(10.0f, 10.0f, 10.0f);

    Vec3 result = lerp(a, b, 0.5f);
    ASSERT_FLOAT_EQ(result.x, 5.0f);
    ASSERT_FLOAT_EQ(result.y, 5.0f);
    ASSERT_FLOAT_EQ(result.z, 5.0f);
}

TEST(testReflect) {
    Vec3 incident(1.0f, -1.0f, 0.0f);
    incident.normalize();
    Vec3 normal(0.0f, 1.0f, 0.0f);

    Vec3 reflected = reflect(incident, normal);

    // Should reflect upward
    ASSERT(reflected.y > 0.0f);
}

// Main
int main() {
    std::cout << "=== Vec3 Tests ===\n\n";

    RUN_TEST(testConstructors);
    RUN_TEST(testAddition);
    RUN_TEST(testSubtraction);
    RUN_TEST(testScalarMultiplication);
    RUN_TEST(testScalarDivision);
    RUN_TEST(testNegation);
    RUN_TEST(testCompoundOperators);
    RUN_TEST(testDotProduct);
    RUN_TEST(testCrossProduct);
    RUN_TEST(testLength);
    RUN_TEST(testNormalize);
    RUN_TEST(testArrayAccess);
    RUN_TEST(testStaticMethods);
    RUN_TEST(testEquality);
    RUN_TEST(testLerp);
    RUN_TEST(testReflect);

    std::cout << "\n=== Results ===\n";
    std::cout << "Passed: " << testsPassed << "\n";
    std::cout << "Failed: " << testsFailed << "\n";

    return testsFailed > 0 ? 1 : 0;
}
