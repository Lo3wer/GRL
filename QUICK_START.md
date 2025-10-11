# Quick Start Guide

## First Time Setup (5 minutes)

### 1. Install Prerequisites

**Windows:**
- Install Visual Studio 2019+ with C++ support
- Install CMake from https://cmake.org/download/

**Linux:**
```bash
sudo apt-get update
sudo apt-get install build-essential cmake git
```

**macOS:**
```bash
brew install cmake
xcode-select --install
```

### 2. Build the Project

```bash
# From GRL directory
mkdir build
cd build

# Windows (Visual Studio)
cmake ..
cmake --build . --config Release

# Linux/macOS
cmake ..
make -j$(nproc)
```

### 3. Verify Setup

```bash
# Run a test (it will fail until you implement the code)
./test_vec3  # Linux/Mac
.\Release\test_vec3.exe  # Windows
```

You should see test failures with messages like "FAILED: ..." - this is expected! You haven't implemented the code yet.

## Your Implementation Workflow

### Daily Routine (2-3 hour sessions)

1. **Pick a file** from the implementation order:
   - Day 1-2: `src/math/vec3.cpp`
   - Day 3: `src/math/vec4.cpp`
   - Day 4-5: `src/math/mat4.cpp`
   - Day 6: `src/graphics/color.cpp` + `framebuffer.cpp`
   - Day 7: `src/utils/image_writer.cpp` + final testing

2. **Open the file** in your editor

3. **Find TODO comments**:
   ```cpp
   Vec3 Vec3::operator+(const Vec3& v) const {
       // TODO: Implement addition
       return Vec3();
   }
   ```

4. **Implement the function**:
   ```cpp
   Vec3 Vec3::operator+(const Vec3& v) const {
       return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
   }
   ```

5. **Rebuild**:
   ```bash
   cd build
   cmake --build .  # or 'make' on Linux/Mac
   ```

6. **Run the test**:
   ```bash
   ./test_vec3
   ```

7. **Repeat** until all tests pass!

## File Overview

### Files YOU need to implement (look for // TODO: comments):

```
src/math/vec3.cpp           ← Start here! (~20 TODOs)
src/math/vec4.cpp           ← Similar to vec3 (~15 TODOs)
src/math/mat4.cpp           ← Most complex (~25 TODOs)
src/graphics/color.cpp      ← Color conversions (~6 TODOs)
src/graphics/framebuffer.cpp ← Pixel operations (~8 TODOs)
src/utils/image_writer.cpp  ← PPM export (~2 TODOs)
```

### Files already done (interfaces only):

```
include/grl/**/*.h          ← Header files (interfaces defined)
src/graphics/rasterizer.cpp ← Week 2-3 (has TODOs for later)
src/graphics/renderer.cpp   ← Mostly complete
tests/**/*                  ← Test files (complete)
```

## Quick Reference: Most Important Formulas

### Vec3 Operations

```cpp
// Addition
Vec3(this->x + v.x, this->y + v.y, this->z + v.z)

// Dot Product
this->x * v.x + this->y * v.y + this->z * v.z

// Cross Product
Vec3(
    this->y * v.z - this->z * v.y,
    this->z * v.x - this->x * v.z,
    this->x * v.y - this->y * v.x
)

// Length
sqrt(x*x + y*y + z*z)

// Normalize
Vec3(x/len, y/len, z/len)  // where len = length()
```

### Mat4 Critical Info

**Column-Major Storage!**
```cpp
// Access element at (row, col)
m[col * 4 + row]  // NOT row * 4 + col!
```

**Identity Matrix:**
```cpp
m[0]=1, m[5]=1, m[10]=1, m[15]=1  // Diagonal
all others = 0
```

**Translation Matrix:**
```cpp
Identity matrix with:
m[12] = x, m[13] = y, m[14] = z
```

## Helpful Commands

```bash
# Build everything
cmake --build build

# Run all tests
cd build && ctest

# Run specific test
./build/test_vec3

# Run example program
./build/week1_test

# Clean and rebuild
rm -rf build
mkdir build && cd build
cmake ..
make
```

## Getting Help

1. **Check IMPLEMENTATION_GUIDE.md** for detailed formulas
2. **Read the test files** to understand expected behavior
3. **Print debug info**:
   ```cpp
   std::cout << "x=" << x << " y=" << y << std::endl;
   ```
4. **Check header files** for function signatures

## Success Criteria

You're done with Week 1 when:

- ✅ All tests pass: `ctest` shows 0 failed
- ✅ Example program creates `test_output.ppm` with checkerboard
- ✅ You can open the PPM file in an image viewer
- ✅ Git repository has your implemented code committed

## Common Issues

**Test won't compile:**
- Make sure you're in the `build` directory
- Run `cmake ..` first, then `make`

**Test crashes:**
- Check for division by zero (normalize on zero-length vector)
- Check array bounds (accessing `v[5]` on Vec3)

**Test fails but doesn't crash:**
- Read the error message carefully
- Check your math formula
- Print intermediate values

**Can't open PPM file:**
- Make sure you implemented `ImageWriter::savePPM`
- Check file was created: `ls -la test_output.ppm`
- Try opening with GIMP, Photoshop, or online PPM viewer

## Next Steps After Week 1

Once all tests pass:

1. Commit your code:
   ```bash
   git add .
   git commit -m "Week 1 complete: Math library implemented"
   git push
   ```

2. Read [Plan.md](Plan.md) Week 2 section

3. Prepare for Bresenham's line drawing algorithm

4. Celebrate! You just built a math library from scratch! 🎉

---

**Estimated Time:** 12 hours total over 7 days (1.5-2 hours per day)

**Difficulty:** Medium (Mat4 is the hardest part)

**Key Takeaway:** Understanding these fundamentals is crucial for everything that follows. Take your time and get it right!
