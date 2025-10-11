#pragma once

#include <cstdint>
#include "grl/math/vec3.h"
#include "grl/math/vec4.h"

namespace grl {

/**
 * Color class representing RGBA values
 * Stored as 32-bit RGBA (8 bits per channel)
 */
struct Color {
    union {
        struct { uint8_t r, g, b, a; };
        uint32_t rgba;
    };

    // Constructors
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    explicit Color(uint32_t rgba); // From packed RGBA value
    Color(float r, float g, float b, float a = 1.0f); // From normalized 0-1 values

    // Arithmetic operations (for blending)
    Color operator+(const Color& c) const;
    Color operator*(float scalar) const;
    Color& operator+=(const Color& c);
    Color& operator*=(float scalar);

    // Comparison
    bool operator==(const Color& c) const;
    bool operator!=(const Color& c) const;

    // Conversion
    static Color fromVec3(const Vec3& v); // Normalized RGB (0-1)
    static Color fromVec4(const Vec4& v); // Normalized RGBA (0-1)
    Vec3 toVec3() const; // Returns normalized RGB
    Vec4 toVec4() const; // Returns normalized RGBA

    // Utility
    static Color lerp(const Color& a, const Color& b, float t);

    // Common colors
    static const Color White;
    static const Color Black;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Cyan;
    static const Color Magenta;
    static const Color Gray;
    static const Color Transparent;
};

// Non-member functions
Color operator*(float scalar, const Color& c);

} // namespace grl
