#pragma once

#include <iostream>
#include "grl/core/types.h"

namespace grl {

class Vec3 {
public:
    float x, y, z;

    // Constructors
    Vec3();
    Vec3(float x, float y, float z);
    explicit Vec3(float scalar); // All components set to scalar

    // Arithmetic operators
    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;
    Vec3 operator-() const; // Negation

    Vec3& operator+=(const Vec3& v);
    Vec3& operator-=(const Vec3& v);
    Vec3& operator*=(float scalar);
    Vec3& operator/=(float scalar);

    // Comparison operators
    bool operator==(const Vec3& v) const;
    bool operator!=(const Vec3& v) const;

    // Vector operations
    float dot(const Vec3& v) const;
    Vec3 cross(const Vec3& v) const;
    float length() const;
    float lengthSquared() const;
    Vec3 normalized() const;
    void normalize();

    // Component access
    float operator[](int i) const;
    float& operator[](int i);

    // Utility
    static Vec3 zero();
    static Vec3 one();
    static Vec3 unitX();
    static Vec3 unitY();
    static Vec3 unitZ();

    // Friend functions for scalar * vec3
    friend Vec3 operator*(float scalar, const Vec3& v);
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v);
};

// Non-member functions
Vec3 operator*(float scalar, const Vec3& v);
std::ostream& operator<<(std::ostream& os, const Vec3& v);

// Utility functions
float dot(const Vec3& a, const Vec3& b);
Vec3 cross(const Vec3& a, const Vec3& b);
Vec3 normalize(const Vec3& v);
Vec3 lerp(const Vec3& a, const Vec3& b, float t);
Vec3 reflect(const Vec3& incident, const Vec3& normal);

} // namespace grl
