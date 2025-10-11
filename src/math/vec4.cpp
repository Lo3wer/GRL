#include "grl/math/vec4.h"
#include <cmath>

namespace grl {

// Constructors
Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vec4::Vec4(float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}

Vec4::Vec4(const Vec3& v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}

// Arithmetic operators
Vec4 Vec4::operator+(const Vec4& v) const {
    // TODO: Implement addition
    return Vec4();
}

Vec4 Vec4::operator-(const Vec4& v) const {
    // TODO: Implement subtraction
    return Vec4();
}

Vec4 Vec4::operator*(float scalar) const {
    // TODO: Implement scalar multiplication
    return Vec4();
}

Vec4 Vec4::operator/(float scalar) const {
    // TODO: Implement scalar division
    return Vec4();
}

Vec4 Vec4::operator-() const {
    // TODO: Implement negation
    return Vec4();
}

Vec4& Vec4::operator+=(const Vec4& v) {
    // TODO: Implement compound addition
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& v) {
    // TODO: Implement compound subtraction
    return *this;
}

Vec4& Vec4::operator*=(float scalar) {
    // TODO: Implement compound scalar multiplication
    return *this;
}

Vec4& Vec4::operator/=(float scalar) {
    // TODO: Implement compound scalar division
    return *this;
}

// Comparison operators
bool Vec4::operator==(const Vec4& v) const {
    // TODO: Implement equality
    return false;
}

bool Vec4::operator!=(const Vec4& v) const {
    return !(*this == v);
}

// Vector operations
float Vec4::dot(const Vec4& v) const {
    // TODO: Implement dot product
    return 0.0f;
}

float Vec4::length() const {
    // TODO: Implement length
    return 0.0f;
}

float Vec4::lengthSquared() const {
    // TODO: Implement squared length
    return 0.0f;
}

Vec4 Vec4::normalized() const {
    // TODO: Implement normalization
    return Vec4();
}

void Vec4::normalize() {
    // TODO: Implement in-place normalization
}

// Component access
float Vec4::operator[](int i) const {
    // TODO: Implement const array-style access
    return 0.0f;
}

float& Vec4::operator[](int i) {
    // TODO: Implement mutable array-style access
    static float dummy = 0.0f;
    return dummy;
}

// Conversion
Vec3 Vec4::xyz() const {
    return Vec3(x, y, z);
}

// Static utility methods
Vec4 Vec4::zero() {
    return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

Vec4 Vec4::one() {
    return Vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

// Non-member functions
Vec4 operator*(float scalar, const Vec4& v) {
    return v * scalar;
}

std::ostream& operator<<(std::ostream& os, const Vec4& v) {
    os << "Vec4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return os;
}

// Utility functions
float dot(const Vec4& a, const Vec4& b) {
    return a.dot(b);
}

Vec4 normalize(const Vec4& v) {
    return v.normalized();
}

} // namespace grl
