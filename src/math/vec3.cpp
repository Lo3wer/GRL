#include "grl/math/vec3.h"
#include <cmath>

namespace grl {

// Constructors
Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3::Vec3(float scalar) : x(scalar), y(scalar), z(scalar) {}

// Arithmetic operators
Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(x-v.x,y-v.y,z-v.z);
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(x*scalar,y*scalar,z*scalar);
}

Vec3 Vec3::operator/(float scalar) const {
    return Vec3(x/scalar,y/scalar,z/scalar);
}

Vec3 Vec3::operator-() const {
    return Vec3(-x,-y,-z);
}

Vec3& Vec3::operator+=(const Vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec3& Vec3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vec3& Vec3::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

// Comparison operators
bool Vec3::operator==(const Vec3& v) const {
    return (floatEqual(x,v.x) && floatEqual(y,v.y) && floatEqual(z,v.z));
}

bool Vec3::operator!=(const Vec3& v) const {
    return !(floatEqual(x,v.x) && floatEqual(y,v.y) && floatEqual(z,v.z));
}

// Vector operations
float Vec3::dot(const Vec3& v) const {
    return x*v.x + y*v.y + z*v.z;
}

Vec3 Vec3::cross(const Vec3& v) const {
    Vec3 result = Vec3();
    result.x = this->y * v.z - this->z * v.y;
    result.y = this->z * v.x - this->x * v.z;
    result.z = this->x * v.y - this->y * v.x;
    return result;
}

float Vec3::length() const {
    return sqrt(x*x + y*y + z*z);
}

float Vec3::lengthSquared() const {
    return x*x + y*y + z*z;
}

Vec3 Vec3::normalized() const {
    float len = length();
    return Vec3(x/len, y/len, z/len);
}

void Vec3::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
}

// Component access
float Vec3::operator[](int i) const {
    switch(i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            return 0.0f;
    }
}

float& Vec3::operator[](int i) {
    switch(i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            static float dummy = 0.0f;
            return dummy;
    }
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
    return Vec3(
        a.x + t * (b.x - a.x),
        a.y + t * (b.y - a.y),
        a.z + t * (b.z - a.z)
    );
}

Vec3 reflect(const Vec3& incident, const Vec3& normal) {
    return incident - 2.0f * dot(incident, normal) * normal;
}

} // namespace grl
