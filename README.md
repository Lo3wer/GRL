# GRL (Graphics Rendering Library)

A software renderer built from scratch in C++, progressing from CPU rasterization to GPU acceleration with CUDA and Vulkan.

## Project Status

**Current Phase:** Week 1 - Foundation (Math Library & Project Setup)

This is a 20-week learning project to deeply understand graphics programming by building everything from first principles.

## Features (Planned)

### Part 1: Software Renderer (Weeks 1-16)
- ✅ Math library (Vec3, Vec4, Mat4)
- ✅ Framebuffer and basic rendering
- 🔲 Triangle rasterization with barycentric coordinates
- 🔲 3D transformation pipeline
- 🔲 Z-buffer and backface culling
- 🔲 OBJ file loading
- 🔲 Interactive viewer with camera controls
- 🔲 Phong lighting and texture mapping
- 🔲 Normal mapping
- 🔲 Ray tracing (shadows & reflections)
- 🔲 CUDA acceleration

### Part 2: Vulkan Renderer (Weeks 17-20)
- 🔲 Vulkan setup and initialization
- 🔲 3D rendering with Vulkan
- 🔲 Textures and lighting in shaders
- 🔲 Compute shaders for ray tracing

## Build Instructions

### Prerequisites

- C++17 compatible compiler (GCC, Clang, or MSVC)
- CMake 3.15 or later
- Git

### Building on Windows (MSVC)

```bash
# Clone the repository
git clone <your-repo-url>
cd GRL

# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
cmake --build . --config Release

# Run tests
ctest -C Release

# Run example
./Release/week1_test.exe
```

### Building on Linux/macOS

```bash
# Clone the repository
git clone <your-repo-url>
cd GRL

# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
make -j$(nproc)

# Run tests
ctest

# Run example
./week1_test
```

## Project Structure

```
GRL/
├── include/grl/           # Public headers
│   ├── core/             # Core types and platform definitions
│   ├── math/             # Vector and matrix math
│   ├── graphics/         # Graphics primitives (framebuffer, rasterizer, renderer)
│   └── utils/            # Utilities (image writer, etc.)
├── src/                  # Implementation files
│   ├── math/
│   ├── graphics/
│   └── utils/
├── tests/                # Unit tests
│   ├── math/
│   └── graphics/
├── examples/             # Example programs
└── CMakeLists.txt        # Build configuration
```

## Current Week Tasks (Week 1)

### Deliverables
- [x] Git repository initialized with .gitignore
- [x] CMakeLists.txt compiling successfully
- [x] Vec3, Vec4, Mat4 classes with full interface
- [ ] **YOUR TASK:** Implement all TODO methods in:
  - `src/math/vec3.cpp`
  - `src/math/vec4.cpp`
  - `src/math/mat4.cpp`
  - `src/graphics/color.cpp`
  - `src/graphics/framebuffer.cpp`
  - `src/utils/image_writer.cpp`
- [ ] Unit tests passing for all math functions
- [ ] Test image generation working (checkerboard pattern)

### Implementation Guide

All the interfaces are defined in the header files. Your task is to implement the methods marked with `// TODO:` comments in the `.cpp` files.

**Recommended implementation order:**

1. **Vec3** (`src/math/vec3.cpp`)
   - Basic arithmetic operators (+, -, *, /)
   - Dot product and cross product
   - Length and normalization
   - Run tests: `./build/test_vec3`

2. **Vec4** (`src/math/vec4.cpp`)
   - Similar to Vec3 but with 4 components
   - Run tests: `./build/test_vec4`

3. **Mat4** (`src/math/mat4.cpp`)
   - Identity matrix
   - Matrix multiplication (column-major!)
   - Transformation matrices (translation, rotation, scale)
   - Camera matrices (lookAt, perspective) - Week 4 feature, but define now
   - Run tests: `./build/test_mat4`

4. **Color** (`src/graphics/color.cpp`)
   - Conversion between normalized and byte values
   - Color arithmetic

5. **Framebuffer** (`src/graphics/framebuffer.cpp`)
   - setPixel, getPixel with bounds checking
   - clear operations

6. **ImageWriter** (`src/utils/image_writer.cpp`)
   - PPM format is very simple (see implementation hints in file)

### Resources

- **Scratchapixel** - [Geometry](https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/points-vectors-and-normals.html)
- **Column-major matrices**: Remember that in column-major storage, the translation components are at indices `[12]`, `[13]`, `[14]`
- **PPM format**: [Wikipedia](https://en.wikipedia.org/wiki/Netpbm#PPM_example)

## Testing

Unit tests are provided for all major components:

```bash
# Run all tests
cd build
ctest

# Run specific test
./test_vec3
./test_mat4
./test_framebuffer
```

## License

This is a learning project. Feel free to use it for educational purposes.

## Acknowledgments

This project follows the plan outlined in [Plan.md](Plan.md), inspired by:
- Scratchapixel.com
- "Ray Tracing in One Weekend" by Peter Shirley
- "Computer Graphics: Principles and Practice"
- Graphics programming community resources
