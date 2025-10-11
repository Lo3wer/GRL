#pragma once

#include <cstdint>
#include <cmath>

namespace grl {

// Common constants
constexpr float PI = 3.14159265358979323846f;
constexpr float TWO_PI = 2.0f * PI;
constexpr float HALF_PI = 0.5f * PI;
constexpr float DEG_TO_RAD = PI / 180.0f;
constexpr float RAD_TO_DEG = 180.0f / PI;
constexpr float EPSILON = 1e-6f;

// Common functions
inline float toRadians(float degrees) {
    return degrees * DEG_TO_RAD;
}

inline float toDegrees(float radians) {
    return radians * RAD_TO_DEG;
}

inline float clamp(float value, float min, float max) {
    return value < min ? min : (value > max ? max : value);
}

inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

inline bool floatEqual(float a, float b, float epsilon = EPSILON) {
    return std::fabs(a - b) < epsilon;
}

} // namespace grl
