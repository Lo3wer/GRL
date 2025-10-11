#include "grl/math/mat4.h"
#include <cmath>
#include <cstring>

namespace grl {

// Constructors
Mat4::Mat4() {
    // TODO: Initialize as identity matrix
    for (int i = 0; i < 16; i++) {
        m[i] = 0.0f;
    }
}

Mat4::Mat4(float diagonal) {
    // TODO: Initialize as diagonal matrix
    for (int i = 0; i < 16; i++) {
        m[i] = 0.0f;
    }
}

Mat4::Mat4(const float* data) {
    // TODO: Copy from array
    std::memcpy(m, data, sizeof(float) * 16);
}

// Element access
float Mat4::operator[](int i) const {
    // TODO: Implement const access
    return m[i];
}

float& Mat4::operator[](int i) {
    // TODO: Implement mutable access
    return m[i];
}

float Mat4::at(int row, int col) const {
    // TODO: Access element at (row, col)
    // Remember: column-major storage, so index = col * 4 + row
    return 0.0f;
}

float& Mat4::at(int row, int col) {
    // TODO: Access element at (row, col)
    return m[0];
}

// Matrix operations
Mat4 Mat4::operator+(const Mat4& other) const {
    // TODO: Implement matrix addition
    return Mat4();
}

Mat4 Mat4::operator-(const Mat4& other) const {
    // TODO: Implement matrix subtraction
    return Mat4();
}

Mat4 Mat4::operator*(const Mat4& other) const {
    // TODO: Implement matrix multiplication (column-major)
    return Mat4();
}

Mat4 Mat4::operator*(float scalar) const {
    // TODO: Implement scalar multiplication
    return Mat4();
}

Mat4& Mat4::operator+=(const Mat4& other) {
    // TODO: Implement compound addition
    return *this;
}

Mat4& Mat4::operator-=(const Mat4& other) {
    // TODO: Implement compound subtraction
    return *this;
}

Mat4& Mat4::operator*=(const Mat4& other) {
    // TODO: Implement compound multiplication
    return *this;
}

Mat4& Mat4::operator*=(float scalar) {
    // TODO: Implement compound scalar multiplication
    return *this;
}

// Matrix-Vector multiplication
Vec4 Mat4::operator*(const Vec4& v) const {
    // TODO: Implement matrix * vector
    return Vec4();
}

Vec3 Mat4::transformPoint(const Vec3& p) const {
    // TODO: Transform point (w=1), then divide by w (perspective divide)
    return Vec3();
}

Vec3 Mat4::transformVector(const Vec3& v) const {
    // TODO: Transform vector (w=0), no perspective divide
    return Vec3();
}

// Matrix operations
Mat4 Mat4::transposed() const {
    // TODO: Implement transpose
    return Mat4();
}

Mat4 Mat4::inversed() const {
    // TODO: Implement matrix inversion (can use Gaussian elimination or adjugate method)
    return Mat4();
}

float Mat4::determinant() const {
    // TODO: Implement determinant calculation
    return 0.0f;
}

// Comparison
bool Mat4::operator==(const Mat4& other) const {
    // TODO: Implement equality check
    return false;
}

bool Mat4::operator!=(const Mat4& other) const {
    return !(*this == other);
}

// Static factory methods
Mat4 Mat4::identity() {
    // TODO: Return identity matrix
    return Mat4();
}

Mat4 Mat4::zero() {
    Mat4 result;
    for (int i = 0; i < 16; i++) {
        result.m[i] = 0.0f;
    }
    return result;
}

// Transformation matrices
Mat4 Mat4::translation(const Vec3& offset) {
    // TODO: Create translation matrix
    return Mat4();
}

Mat4 Mat4::translation(float x, float y, float z) {
    return translation(Vec3(x, y, z));
}

Mat4 Mat4::rotationX(float angleRad) {
    // TODO: Create rotation matrix around X axis
    return Mat4();
}

Mat4 Mat4::rotationY(float angleRad) {
    // TODO: Create rotation matrix around Y axis
    return Mat4();
}

Mat4 Mat4::rotationZ(float angleRad) {
    // TODO: Create rotation matrix around Z axis
    return Mat4();
}

Mat4 Mat4::rotation(const Vec3& axis, float angleRad) {
    // TODO: Create rotation matrix around arbitrary axis (Rodrigues' formula)
    return Mat4();
}

Mat4 Mat4::scale(const Vec3& scale) {
    // TODO: Create scale matrix
    return Mat4();
}

Mat4 Mat4::scale(float x, float y, float z) {
    return scale(Vec3(x, y, z));
}

Mat4 Mat4::scale(float uniformScale) {
    return scale(Vec3(uniformScale, uniformScale, uniformScale));
}

// Camera matrices
Mat4 Mat4::lookAt(const Vec3& eye, const Vec3& target, const Vec3& up) {
    // TODO: Create view matrix (lookAt)
    return Mat4();
}

Mat4 Mat4::perspective(float fovYRadians, float aspectRatio,
                       float nearPlane, float farPlane) {
    // TODO: Create perspective projection matrix
    return Mat4();
}

Mat4 Mat4::orthographic(float left, float right, float bottom,
                        float top, float nearPlane, float farPlane) {
    // TODO: Create orthographic projection matrix
    return Mat4();
}

// Non-member functions
Mat4 operator*(float scalar, const Mat4& mat) {
    return mat * scalar;
}

std::ostream& operator<<(std::ostream& os, const Mat4& mat) {
    os << "Mat4(\n";
    for (int row = 0; row < 4; row++) {
        os << "  ";
        for (int col = 0; col < 4; col++) {
            os << mat.at(row, col);
            if (col < 3) os << ", ";
        }
        os << "\n";
    }
    os << ")";
    return os;
}

// Utility functions
Mat4 transpose(const Mat4& mat) {
    return mat.transposed();
}

Mat4 inverse(const Mat4& mat) {
    return mat.inversed();
}

} // namespace grl
