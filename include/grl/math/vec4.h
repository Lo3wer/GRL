#pragma once

#include <iostream>
#include "grl/core/types.h"
#include "grl/math/vec3.h"

namespace grl {

class Vec4 {
public:
    float x, y, z, w;

    // Constructors
    Vec4();
    Vec4(float x, float y, float z, float w);
    explicit Vec4(float scalar); // All components set to scalar
    Vec4(const Vec3& v, float w); // Construct from Vec3 + w component

    // Arithmetic operators
    Vec4 operator+(const Vec4& v) const;
    Vec4 operator-(const Vec4& v) const;
    Vec4 operator*(float scalar) const;
    Vec4 operator/(float scalar) const;
    Vec4 operator-() const;

    Vec4& operator+=(const Vec4& v);
    Vec4& operator-=(const Vec4& v);
    Vec4& operator*=(float scalar);
    Vec4& operator/=(float scalar);

    // Comparison operators
    bool operator==(const Vec4& v) const;
    bool operator!=(const Vec4& v) const;

    // Vector operations
    float dot(const Vec4& v) const;
    float length() const;
    float lengthSquared() const;
    Vec4 normalized() const;
    void normalize();

    // Component access
    float operator[](int i) const;
    float& operator[](int i);

    // Conversion
    Vec3 xyz() const; // Return xyz components as Vec3

    // Utility
    static Vec4 zero();
    static Vec4 one();

    // Friend functions
    friend Vec4 operator*(float scalar, const Vec4& v);
    friend std::ostream& operator<<(std::ostream& os, const Vec4& v);
};

// Non-member functions
Vec4 operator*(float scalar, const Vec4& v);
std::ostream& operator<<(std::ostream& os, const Vec4& v);

// Utility functions
float dot(const Vec4& a, const Vec4& b);
Vec4 normalize(const Vec4& v);

} // namespace grl
