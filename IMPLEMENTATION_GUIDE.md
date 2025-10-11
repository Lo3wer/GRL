# Week 1 Implementation Guide

This guide will help you implement all the TODO methods in the correct order with hints and formulas.

## Overview

You have **12 hours** this week to complete the math library implementation. All the interfaces are already defined - you just need to fill in the implementations marked with `// TODO:`.

## Implementation Order

### 1. Vec3 (Estimated: 2-3 hours)

**File:** `src/math/vec3.cpp`

**Key formulas:**

```cpp
// Addition
result.x = this->x + v.x
result.y = this->y + v.y
result.z = this->z + v.z

// Scalar multiplication
result.x = this->x * scalar
result.y = this->y * scalar
result.z = this->z * scalar

// Dot product
return this->x * v.x + this->y * v.y + this->z * v.z

// Cross product
result.x = this->y * v.z - this->z * v.y
result.y = this->z * v.x - this->x * v.z
result.z = this->x * v.y - this->y * v.x

// Length
return sqrt(x*x + y*y + z*z)

// Normalize
float len = length()
return Vec3(x/len, y/len, z/len)

// Array access
if (i == 0) return x;
if (i == 1) return y;
if (i == 2) return z;

// Equality (use floatEqual from types.h)
return floatEqual(x, v.x) && floatEqual(y, v.y) && floatEqual(z, v.z)

// Lerp
return Vec3(
    a.x + t * (b.x - a.x),
    a.y + t * (b.y - a.y),
    a.z + t * (b.z - a.z)
)

// Reflect
return incident - 2.0f * dot(incident, normal) * normal
```

**Test:** Run `./build/test_vec3` after implementation

---

### 2. Vec4 (Estimated: 1 hour)

**File:** `src/math/vec4.cpp`

Very similar to Vec3, but with 4 components (x, y, z, w).

**Key differences:**
- Dot product includes w: `x*v.x + y*v.y + z*v.z + w*v.w`
- No cross product (cross product is only defined for 3D vectors)
- `xyz()` method: just return `Vec3(x, y, z)`

**Test:** Run `./build/test_vec4` after implementation

---

### 3. Mat4 (Estimated: 4-5 hours) - **MOST IMPORTANT**

**File:** `src/math/mat4.cpp`

**CRITICAL: Column-Major Storage**

Matrices are stored in column-major order (like OpenGL/Vulkan):

```
Matrix:           Storage in m[]:
[m0  m4  m8  m12] m[0]  m[4]  m[8]  m[12]
[m1  m5  m9  m13] m[1]  m[5]  m[9]  m[13]
[m2  m6  m10 m14] m[2]  m[6]  m[10] m[14]
[m3  m7  m11 m15] m[3]  m[7]  m[11] m[15]
```

**at(row, col) conversion:**
```cpp
return m[col * 4 + row];  // NOT row * 4 + col!
```

#### Identity Matrix
```cpp
Mat4::Mat4() {
    for (int i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = m[5] = m[10] = m[15] = 1.0f;  // Diagonal = 1
}
```

#### Matrix Multiplication
```cpp
Mat4 Mat4::operator*(const Mat4& other) const {
    Mat4 result;
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            float sum = 0.0f;
            for (int k = 0; k < 4; k++) {
                sum += at(row, k) * other.at(k, col);
            }
            result.at(row, col) = sum;
        }
    }
    return result;
}
```

#### Translation Matrix
```cpp
Mat4 Mat4::translation(const Vec3& offset) {
    Mat4 result = identity();
    result.m[12] = offset.x;  // Column 3, row 0
    result.m[13] = offset.y;  // Column 3, row 1
    result.m[14] = offset.z;  // Column 3, row 2
    return result;
}
```

#### Scale Matrix
```cpp
Mat4 Mat4::scale(const Vec3& scale) {
    Mat4 result;
    for (int i = 0; i < 16; i++) result.m[i] = 0.0f;
    result.m[0]  = scale.x;
    result.m[5]  = scale.y;
    result.m[10] = scale.z;
    result.m[15] = 1.0f;
    return result;
}
```

#### Rotation X (around X axis)
```cpp
Mat4 Mat4::rotationX(float angleRad) {
    Mat4 result = identity();
    float c = cos(angleRad);
    float s = sin(angleRad);

    result.m[5]  =  c;  // [1][1]
    result.m[6]  =  s;  // [2][1]
    result.m[9]  = -s;  // [1][2]
    result.m[10] =  c;  // [2][2]

    return result;
}
```

#### Rotation Y (around Y axis)
```cpp
Mat4 Mat4::rotationY(float angleRad) {
    Mat4 result = identity();
    float c = cos(angleRad);
    float s = sin(angleRad);

    result.m[0]  =  c;  // [0][0]
    result.m[2]  = -s;  // [2][0]
    result.m[8]  =  s;  // [0][2]
    result.m[10] =  c;  // [2][2]

    return result;
}
```

#### Rotation Z (around Z axis)
```cpp
Mat4 Mat4::rotationZ(float angleRad) {
    Mat4 result = identity();
    float c = cos(angleRad);
    float s = sin(angleRad);

    result.m[0] =  c;  // [0][0]
    result.m[1] =  s;  // [1][0]
    result.m[4] = -s;  // [0][1]
    result.m[5] =  c;  // [1][1]

    return result;
}
```

#### Transform Point (w=1)
```cpp
Vec3 Mat4::transformPoint(const Vec3& p) const {
    Vec4 v4(p, 1.0f);
    Vec4 result = (*this) * v4;

    // Perspective divide (if w != 1)
    if (result.w != 0.0f && result.w != 1.0f) {
        result.x /= result.w;
        result.y /= result.w;
        result.z /= result.w;
    }

    return result.xyz();
}
```

#### Transform Vector (w=0)
```cpp
Vec3 Mat4::transformVector(const Vec3& v) const {
    Vec4 v4(v, 0.0f);
    Vec4 result = (*this) * v4;
    return result.xyz();
}
```

#### Transpose
```cpp
Mat4 Mat4::transposed() const {
    Mat4 result;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            result.at(row, col) = this->at(col, row);
        }
    }
    return result;
}
```

#### LookAt (Camera View Matrix) - **Week 4, but define now**
```cpp
Mat4 Mat4::lookAt(const Vec3& eye, const Vec3& target, const Vec3& up) {
    Vec3 zAxis = normalize(eye - target);  // Forward
    Vec3 xAxis = normalize(cross(up, zAxis));  // Right
    Vec3 yAxis = cross(zAxis, xAxis);  // Up

    Mat4 result = identity();

    // Set rotation part
    result.m[0] = xAxis.x;
    result.m[4] = xAxis.y;
    result.m[8] = xAxis.z;

    result.m[1] = yAxis.x;
    result.m[5] = yAxis.y;
    result.m[9] = yAxis.z;

    result.m[2] = zAxis.x;
    result.m[6] = zAxis.y;
    result.m[10] = zAxis.z;

    // Set translation part
    result.m[12] = -dot(xAxis, eye);
    result.m[13] = -dot(yAxis, eye);
    result.m[14] = -dot(zAxis, eye);

    return result;
}
```

#### Perspective (Projection Matrix) - **Week 4, but define now**
```cpp
Mat4 Mat4::perspective(float fovYRadians, float aspectRatio,
                       float nearPlane, float farPlane) {
    Mat4 result;
    for (int i = 0; i < 16; i++) result.m[i] = 0.0f;

    float tanHalfFovy = tan(fovYRadians / 2.0f);

    result.m[0] = 1.0f / (aspectRatio * tanHalfFovy);
    result.m[5] = 1.0f / tanHalfFovy;
    result.m[10] = -(farPlane + nearPlane) / (farPlane - nearPlane);
    result.m[11] = -1.0f;
    result.m[14] = -(2.0f * farPlane * nearPlane) / (farPlane - nearPlane);

    return result;
}
```

**Test:** Run `./build/test_mat4` after implementation

---

### 4. Color (Estimated: 1 hour)

**File:** `src/graphics/color.cpp`

```cpp
// Constructor from floats [0,1] to bytes [0,255]
Color::Color(float r, float g, float b, float a) {
    this->r = static_cast<uint8_t>(clamp(r, 0.0f, 1.0f) * 255.0f);
    this->g = static_cast<uint8_t>(clamp(g, 0.0f, 1.0f) * 255.0f);
    this->b = static_cast<uint8_t>(clamp(b, 0.0f, 1.0f) * 255.0f);
    this->a = static_cast<uint8_t>(clamp(a, 0.0f, 1.0f) * 255.0f);
}

// Color addition (clamp to 255)
Color Color::operator+(const Color& c) const {
    return Color(
        std::min(255, (int)r + (int)c.r),
        std::min(255, (int)g + (int)c.g),
        std::min(255, (int)b + (int)c.b),
        std::min(255, (int)a + (int)c.a)
    );
}

// fromVec3
Color Color::fromVec3(const Vec3& v) {
    return Color(v.x, v.y, v.z, 1.0f);
}

// toVec3
Vec3 Color::toVec3() const {
    return Vec3(r / 255.0f, g / 255.0f, b / 255.0f);
}
```

---

### 5. Framebuffer (Estimated: 2 hours)

**File:** `src/graphics/framebuffer.cpp`

```cpp
void Framebuffer::clear(const Color& color) {
    std::fill(colorBuffer_.begin(), colorBuffer_.end(), color.rgba);
}

void Framebuffer::setPixel(int x, int y, const Color& color) {
    if (!isInBounds(x, y)) return;
    colorBuffer_[getIndex(x, y)] = color.rgba;
}

Color Framebuffer::getPixel(int x, int y) const {
    if (!isInBounds(x, y)) return Color::Black;
    return Color(colorBuffer_[getIndex(x, y)]);
}

bool Framebuffer::isInBounds(int x, int y) const {
    return x >= 0 && x < width_ && y >= 0 && y < height_;
}

float Framebuffer::getDepth(int x, int y) const {
    if (!isInBounds(x, y)) return 1.0f;
    return depthBuffer_[getIndex(x, y)];
}

void Framebuffer::setDepth(int x, int y, float depth) {
    if (!isInBounds(x, y)) return;
    depthBuffer_[getIndex(x, y)] = depth;
}

bool Framebuffer::depthTest(int x, int y, float depth) const {
    return depth < getDepth(x, y);
}
```

**Test:** Run `./build/test_framebuffer` after implementation

---

### 6. ImageWriter (Estimated: 1 hour)

**File:** `src/utils/image_writer.cpp`

PPM P3 format (ASCII):
```
P3
<width> <height>
255
<R> <G> <B>  <R> <G> <B> ...
```

```cpp
bool ImageWriter::savePPM(const std::string& filename, const Framebuffer& framebuffer) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    int width = framebuffer.getWidth();
    int height = framebuffer.getHeight();

    // Write header
    file << "P3\n";
    file << width << " " << height << "\n";
    file << "255\n";

    // Write pixel data (row by row, top to bottom)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color c = framebuffer.getPixel(x, y);
            file << (int)c.r << " " << (int)c.g << " " << (int)c.b << " ";
        }
        file << "\n";
    }

    file.close();
    return true;
}
```

---

## Testing Strategy

1. **Implement one file at a time**
2. **Test immediately after each implementation**
3. **Don't move on until tests pass**

```bash
# After implementing Vec3
cd build
cmake --build .
./test_vec3

# After implementing Mat4
cmake --build .
./test_mat4

# After implementing everything
ctest  # Run all tests

# Run the example program
./week1_test
```

## Common Mistakes to Avoid

1. **Column-major vs Row-major**: Always use `col * 4 + row` for indexing
2. **Rotation matrices**: Make sure to use `cos()` and `sin()` correctly
3. **Normalization**: Check for division by zero (length == 0)
4. **Array bounds**: Always check `isInBounds()` before accessing framebuffer
5. **Float comparison**: Use `floatEqual()` instead of `==` for floats

## Debugging Tips

1. Print intermediate results using `std::cout`
2. Use the test programs - they'll tell you exactly what's failing
3. For matrices, print them out to verify structure
4. Verify your math formulas with pen and paper first

## Week 1 Completion Checklist

- [ ] Vec3 fully implemented and tested
- [ ] Vec4 fully implemented and tested
- [ ] Mat4 fully implemented and tested (at least basic operations)
- [ ] Color conversion working
- [ ] Framebuffer set/get pixel working
- [ ] PPM image writer working
- [ ] All unit tests passing
- [ ] Example program generates checkerboard image
- [ ] Committed and pushed to GitHub

## Time Budget

- Vec3: 2-3 hours
- Vec4: 1 hour
- Mat4: 4-5 hours (this is the big one!)
- Color: 1 hour
- Framebuffer: 2 hours
- ImageWriter: 1 hour
- Testing and debugging: 1-2 hours

**Total: ~12 hours**

## Next Week Preview

Week 2 will focus on:
- Bresenham's line drawing algorithm
- Drawing patterns and shapes
- Preparing for triangle rasterization

Good luck! Take your time with Mat4 - getting the matrix operations right is crucial for everything that follows.
