#include "grl/math/vec3.h"
#include <cmath>

namespace grl {

// Constructors
Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3::Vec3(float scalar) : x(scalar), y(scalar), z(scalar) {}

// Arithmetic operators
Vec3 Vec3::operator+(const Vec3& v) const {
    // TODO: Implement addition
    return Vec3();
}

Vec3 Vec3::operator-(const Vec3& v) const {
    // TODO: Implement subtraction
    return Vec3();
}

Vec3 Vec3::operator*(float scalar) const {
    // TODO: Implement scalar multiplication
    return Vec3();
}

Vec3 Vec3::operator/(float scalar) const {
    // TODO: Implement scalar division
    return Vec3();
}

Vec3 Vec3::operator-() const {
    // TODO: Implement negation
    return Vec3();
}

Vec3& Vec3::operator+=(const Vec3& v) {
    // TODO: Implement compound addition
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    // TODO: Implement compound subtraction
    return *this;
}

Vec3& Vec3::operator*=(float scalar) {
    // TODO: Implement compound scalar multiplication
    return *this;
}

Vec3& Vec3::operator/=(float scalar) {
    // TODO: Implement compound scalar division
    return *this;
}

// Comparison operators
bool Vec3::operator==(const Vec3& v) const {
    // TODO: Implement equality (consider using floatEqual for robustness)
    return false;
}

bool Vec3::operator!=(const Vec3& v) const {
    return !(*this == v);
}

// Vector operations
float Vec3::dot(const Vec3& v) const {
    // TODO: Implement dot product
    return 0.0f;
}

Vec3 Vec3::cross(const Vec3& v) const {
    // TODO: Implement cross product
    return Vec3();
}

float Vec3::length() const {
    // TODO: Implement length (magnitude)
    return 0.0f;
}

float Vec3::lengthSquared() const {
    // TODO: Implement squared length (more efficient, no sqrt)
    return 0.0f;
}

Vec3 Vec3::normalized() const {
    // TODO: Implement normalization (return normalized copy)
    return Vec3();
}

void Vec3::normalize() {
    // TODO: Implement in-place normalization
}

// Component access
float Vec3::operator[](int i) const {
    // TODO: Implement const array-style access
    return 0.0f;
}

float& Vec3::operator[](int i) {
    // TODO: Implement mutable array-style access
    static float dummy = 0.0f;
    return dummy;
}

// Static utility methods
Vec3 Vec3::zero() {
    return Vec3(0.0f, 0.0f, 0.0f);
}

Vec3 Vec3::one() {
    return Vec3(1.0f, 1.0f, 1.0f);
}

Vec3 Vec3::unitX() {
    return Vec3(1.0f, 0.0f, 0.0f);
}

Vec3 Vec3::unitY() {
    return Vec3(0.0f, 1.0f, 0.0f);
}

Vec3 Vec3::unitZ() {
    return Vec3(0.0f, 0.0f, 1.0f);
}

// Non-member functions
Vec3 operator*(float scalar, const Vec3& v) {
    return v * scalar;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "Vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

// Utility functions
float dot(const Vec3& a, const Vec3& b) {
    return a.dot(b);
}

Vec3 cross(const Vec3& a, const Vec3& b) {
    return a.cross(b);
}

Vec3 normalize(const Vec3& v) {
    return v.normalized();
}

Vec3 lerp(const Vec3& a, const Vec3& b, float t) {
    // TODO: Implement linear interpolation
    return Vec3();
}

Vec3 reflect(const Vec3& incident, const Vec3& normal) {
    // TODO: Implement reflection: incident - 2 * dot(incident, normal) * normal
    return Vec3();
}

} // namespace grl
