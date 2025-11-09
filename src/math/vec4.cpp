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
    return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vec4 Vec4::operator-(const Vec4& v) const {
    return Vec4(x-v.x,y-v.y,z-v.z,w-v.w);
}

Vec4 Vec4::operator*(float scalar) const {
    return Vec4(x*scalar,y*scalar,z*scalar,w*scalar);
}

Vec4 Vec4::operator/(float scalar) const {
    return Vec4(x/scalar,y/scalar,z/scalar,w/scalar);
}

Vec4 Vec4::operator-() const {
    return Vec4(-x,-y,-z,-w);
}

Vec4& Vec4::operator+=(const Vec4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

Vec4& Vec4::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

Vec4& Vec4::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

// Comparison operators
bool Vec4::operator==(const Vec4& v) const {
    return (floatEqual(x,v.x) && floatEqual(y,v.y) && floatEqual(z,v.z) && floatEqual(w,v.w));
}

bool Vec4::operator!=(const Vec4& v) const {
    return !(floatEqual(x,v.x) && floatEqual(y,v.y) && floatEqual(z,v.z) && floatEqual(w,v.w));
}

// Vector operations
float Vec4::dot(const Vec4& v) const {
    return x*v.x + y*v.y + z*v.z + w*v.w;
}

float Vec4::length() const {
    return sqrt(x*x + y*y + z*z + w*w);
}

float Vec4::lengthSquared() const {
    return x*x + y*y + z*z + w*w;
}

Vec4 Vec4::normalized() const {
    float len = length();
    return Vec4(x/len, y/len, z/len, w/len);
}

void Vec4::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
    w /= len;
}

// Component access
float Vec4::operator[](int i) const {
    switch(i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            return 0.0f;
    }
}

float& Vec4::operator[](int i) {
    switch(i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            static float dummy = 0.0f;
            return dummy;
    }
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
