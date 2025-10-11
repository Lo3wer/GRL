#include "grl/graphics/color.h"
#include "grl/core/types.h"

namespace grl {

// Constructors
Color::Color() : r(0), g(0), b(0), a(255) {}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

Color::Color(uint32_t rgba) : rgba(rgba) {}

Color::Color(float r, float g, float b, float a) {
    // TODO: Convert from normalized [0,1] to [0,255]
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 255;
}

// Arithmetic operations
Color Color::operator+(const Color& c) const {
    // TODO: Implement color addition (clamp to 255)
    return Color();
}

Color Color::operator*(float scalar) const {
    // TODO: Implement color scaling (clamp to [0,255])
    return Color();
}

Color& Color::operator+=(const Color& c) {
    // TODO: Implement compound addition
    return *this;
}

Color& Color::operator*=(float scalar) {
    // TODO: Implement compound scaling
    return *this;
}

// Comparison
bool Color::operator==(const Color& c) const {
    return rgba == c.rgba;
}

bool Color::operator!=(const Color& c) const {
    return rgba != c.rgba;
}

// Conversion
Color Color::fromVec3(const Vec3& v) {
    // TODO: Convert normalized RGB [0,1] to Color
    return Color();
}

Color Color::fromVec4(const Vec4& v) {
    // TODO: Convert normalized RGBA [0,1] to Color
    return Color();
}

Vec3 Color::toVec3() const {
    // TODO: Convert to normalized RGB [0,1]
    return Vec3();
}

Vec4 Color::toVec4() const {
    // TODO: Convert to normalized RGBA [0,1]
    return Vec4();
}

// Utility
Color Color::lerp(const Color& a, const Color& b, float t) {
    // TODO: Implement linear interpolation between colors
    return Color();
}

// Common colors
const Color Color::White(255, 255, 255, 255);
const Color Color::Black(0, 0, 0, 255);
const Color Color::Red(255, 0, 0, 255);
const Color Color::Green(0, 255, 0, 255);
const Color Color::Blue(0, 0, 255, 255);
const Color Color::Yellow(255, 255, 0, 255);
const Color Color::Cyan(0, 255, 255, 255);
const Color Color::Magenta(255, 0, 255, 255);
const Color Color::Gray(128, 128, 128, 255);
const Color Color::Transparent(0, 0, 0, 0);

// Non-member functions
Color operator*(float scalar, const Color& c) {
    return c * scalar;
}

} // namespace grl
