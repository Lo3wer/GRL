#pragma once

#include <iostream>
#include "grl/core/types.h"
#include "grl/math/vec3.h"
#include "grl/math/vec4.h"

namespace grl {

/**
 * 4x4 Matrix class using column-major storage
 * Memory layout matches Vulkan/OpenGL convention:
 * m[0..3]   = column 0
 * m[4..7]   = column 1
 * m[8..11]  = column 2
 * m[12..15] = column 3
 *
 * Matrix indexing: m[column * 4 + row]
 */
class Mat4 {
public:
    float m[16]; // Column-major storage

    // Constructors
    Mat4(); // Identity matrix
    explicit Mat4(float diagonal); // Diagonal matrix
    Mat4(const float* data); // From array (16 elements, column-major)

    // Element access
    float operator[](int i) const;
    float& operator[](int i);
    float at(int row, int col) const;
    float& at(int row, int col);

    // Matrix operations
    Mat4 operator+(const Mat4& other) const;
    Mat4 operator-(const Mat4& other) const;
    Mat4 operator*(const Mat4& other) const;
    Mat4 operator*(float scalar) const;

    Mat4& operator+=(const Mat4& other);
    Mat4& operator-=(const Mat4& other);
    Mat4& operator*=(const Mat4& other);
    Mat4& operator*=(float scalar);

    // Matrix-Vector multiplication
    Vec4 operator*(const Vec4& v) const;

    // Transform a point (w=1)
    Vec3 transformPoint(const Vec3& p) const;

    // Transform a vector/direction (w=0)
    Vec3 transformVector(const Vec3& v) const;

    // Matrix operations
    Mat4 transposed() const;
    Mat4 inversed() const;
    float determinant() const;

    // Comparison
    bool operator==(const Mat4& other) const;
    bool operator!=(const Mat4& other) const;

    // Static factory methods - Identity and basic operations
    static Mat4 identity();
    static Mat4 zero();

    // Transformation matrices
    static Mat4 translation(const Vec3& offset);
    static Mat4 translation(float x, float y, float z);

    static Mat4 rotationX(float angleRad);
    static Mat4 rotationY(float angleRad);
    static Mat4 rotationZ(float angleRad);
    static Mat4 rotation(const Vec3& axis, float angleRad); // Arbitrary axis

    static Mat4 scale(const Vec3& scale);
    static Mat4 scale(float x, float y, float z);
    static Mat4 scale(float uniformScale);

    // Camera matrices
    static Mat4 lookAt(const Vec3& eye, const Vec3& target, const Vec3& up);
    static Mat4 perspective(float fovYRadians, float aspectRatio,
                           float nearPlane, float farPlane);
    static Mat4 orthographic(float left, float right, float bottom,
                            float top, float nearPlane, float farPlane);

    // Friend functions
    friend Mat4 operator*(float scalar, const Mat4& mat);
    friend std::ostream& operator<<(std::ostream& os, const Mat4& mat);
};

// Non-member functions
Mat4 operator*(float scalar, const Mat4& mat);
std::ostream& operator<<(std::ostream& os, const Mat4& mat);

// Utility functions
Mat4 transpose(const Mat4& mat);
Mat4 inverse(const Mat4& mat);

} // namespace grl
