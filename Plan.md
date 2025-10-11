# GRL (Graphics Rendering Library)

## Project Overview

**Duration:** 20 weeks (5 months)  
**Time Commitment:** 12 hours/week  
**Target:** Build software renderer from scratch, then rebuild in Vulkan  

---

## Technology Stack

### Core Development

- **Language:** C++ (C++17 or later)
- **Build System:** CMake or Makefile
- **Version Control:** Git + GitHub
- **IDE:** VS Code, CLion, or Visual Studio

### Libraries (Minimal)

- **Window/Input:** SDL2 or GLFW (Phase 3+)
- **Image Loading:** stb_image.h (single header, Phase 4)
- **Testing:** Catch2 or Google Test (optional but recommended)

### GPU Programming

- **CUDA:** CUDA Toolkit 11.0+ (Phase 6)
- **Vulkan:** Vulkan SDK 1.3+ (Part 2)

### Tools

- **Debugging:** GDB/LLDB, Valgrind
- **Profiling:** perf, gprof, NVIDIA NSight (CUDA), RenderDoc (Vulkan)
- **Assets:** Stanford 3D models, free textures from learnopengl.com

---

## PART 1: SOFTWARE RENDERER (Weeks 1-16)

---

## Phase 1: Foundation (Weeks 1-3)

### Week 1: Project Setup & Vector Math

**Time:** 12 hours

**Goals:**

- Set up project structure and build system
- Implement core math library (Vec3, Vec4, Mat4)
- Write unit tests for math operations

**Key Components:**

- Vector operations: add, subtract, multiply, divide, dot, cross, normalize
- Matrix operations: multiplication, transpose
- Transformation matrices: translation, rotation (X/Y/Z), scale
- Camera matrices: perspective projection, lookAt
- Unit tests for all math functions

**Deliverables:**

- [ ] Git repository initialized with .gitignore
- [ ] CMakeLists.txt or Makefile compiling successfully
- [ ] Vec3, Vec4, Mat4 classes with full operations
- [ ] Unit tests passing for all math functions
- [ ] README.md with build instructions

---

### Week 2: Framebuffer & Line Drawing

**Time:** 12 hours

**Goals:**

- Create framebuffer class to store pixel data
- Implement PPM file export
- Draw pixels and lines

**Key Components:**

- Framebuffer class: width, height, RGB pixel storage
- setPixel(), clear(), saveToPPM() functions
- Color struct (RGB or RGBA)
- Bresenham's line drawing algorithm
- Coordinate system handling

**Deliverables:**

- [ ] Framebuffer class implemented
- [ ] PPM file writer working
- [ ] Bresenham line algorithm implemented
- [ ] Test image: colored lines forming a pattern/shape
- [ ] Can open output image in any image viewer

---

### Week 3: Triangle Rasterization

**Time:** 12 hours

**Goals:**

- Implement triangle rasterization using edge functions
- Calculate barycentric coordinates
- Interpolate vertex colors across triangles

**Key Components:**

- Edge function for inside/outside triangle test
- Barycentric coordinate calculation
- Bounding box for efficient rasterization
- Per-pixel color interpolation
- Handle multiple overlapping triangles

**Deliverables:**

- [ ] Triangle rasterization function implemented
- [ ] Barycentric coordinate system working
- [ ] Color interpolation across triangles
- [ ] Test image: multiple colored triangles (some overlapping)
- [ ] Edge cases handled (degenerate triangles, off-screen)

---

## Phase 2: 3D Rendering (Weeks 4-6)

### Week 4: 3D Pipeline & Camera

**Time:** 12 hours

**Goals:**

- Implement complete vertex transformation pipeline
- Create camera system
- Render hardcoded 3D cube

**Key Components:**

- Transformation pipeline: Model → World → View → Projection
- Clip space to NDC conversion
- NDC to screen space conversion
- Camera class: position, rotation, FOV, aspect ratio
- Hardcoded cube vertices and faces
- Perspective division (w-divide)

**Deliverables:**

- [ ] Full transformation pipeline implemented
- [ ] Camera class with view and projection matrices
- [ ] Hardcoded cube rendering correctly
- [ ] Test image: 3D cube from camera perspective
- [ ] Can rotate camera to see different angles

---

### Week 5: Z-Buffer & Culling

**Time:** 12 hours

**Goals:**

- Add depth testing with z-buffer
- Implement backface culling
- Correctly render multiple overlapping objects

**Key Components:**

- Z-buffer: depth value per pixel
- Depth interpolation using barycentric coordinates
- Depth test during rasterization
- Backface culling using triangle normal and view direction
- Multiple objects at different depths

**Deliverables:**

- [ ] Z-buffer implemented
- [ ] Depth testing working correctly
- [ ] Backface culling implemented
- [ ] Test image: multiple 3D cubes with correct occlusion
- [ ] No z-fighting or depth artifacts

---

### Week 6: OBJ File Loading

**Time:** 12 hours

**Goals:**

- Parse OBJ file format
- Build mesh data structures
- Render loaded 3D models

**Key Components:**

- OBJ parser: vertices (v), normals (vn), faces (f), texture coords (vt)
- Mesh class: store vertices, indices, normals
- Handle triangulated faces (f v1/vt1/vn1 format)
- Download test models (Stanford bunny, teapot)
- Index buffer support

**Deliverables:**

- [ ] OBJ file parser implemented
- [ ] Mesh data structure created
- [ ] Can load and store OBJ models
- [ ] Test image: Stanford bunny or teapot rendering
- [ ] Handle models with 1000+ triangles

---

## Phase 3: Interactive Viewer (Weeks 7-9)

### Week 7: Window System Integration

**Time:** 12 hours

**Goals:**

- Integrate SDL2 or GLFW for windowing
- Display framebuffer in real-time
- Implement basic render loop

**Key Components:**

- Window creation and initialization
- Event loop and input polling
- Copy framebuffer to window texture/surface
- Render loop: clear → draw → present
- Frame timing (delta time calculation)
- Target 30+ FPS initially

**Deliverables:**

- [ ] Window opens and displays content
- [ ] Framebuffer updates in real-time
- [ ] Render loop running smoothly
- [ ] FPS counter displayed
- [ ] Can see 3D model rotating or static in window

---

### Week 8: Camera Controls

**Time:** 12 hours

**Goals:**

- Implement FPS-style camera controls
- WASD movement and mouse look
- Smooth camera motion

**Key Components:**

- Keyboard input handling (WASD, QE for vertical)
- Mouse input for camera rotation (yaw/pitch)
- Camera movement in view direction
- Movement speed scaled by delta time
- Mouse sensitivity adjustment
- Optional: camera momentum/smoothing

**Deliverables:**

- [ ] WASD keys move camera forward/back/left/right
- [ ] QE keys move camera up/down
- [ ] Mouse controls camera rotation
- [ ] Movement speed feels natural
- [ ] Can navigate freely around 3D scene
- [ ] No gimbal lock or camera flipping

---

### Week 9: Performance Optimization

**Time:** 12 hours

**Goals:**

- Profile renderer to identify bottlenecks
- Implement frustum culling
- Optimize critical paths
- Target 60 FPS

**Key Components:**

- Simple profiling (time each render stage)
- Frustum culling: skip triangles outside view
- Bounding volume tests (AABB)
- Memory access optimization
- Optional: multithreaded rasterization
- Optional: SIMD optimizations

**Deliverables:**

- [ ] Profiling data showing bottlenecks
- [ ] Frustum culling implemented
- [ ] Performance measurements before/after optimization
- [ ] Achieves 60 FPS with 5,000-10,000 triangle models
- [ ] Document optimization techniques used

---

## Phase 4: Lighting & Materials (Weeks 10-12)

### Week 10: Phong Lighting

**Time:** 12 hours

**Goals:**

- Implement Phong lighting model
- Add point lights to scene
- Per-pixel lighting calculations

**Key Components:**

- Light class: position, color, intensity
- Phong model: ambient + diffuse + specular components
- Per-pixel lighting (not per-vertex)
- Normal interpolation across triangles
- Material properties: Ka, Kd, Ks, shininess
- Multiple lights support

**Deliverables:**

- [ ] Phong lighting model implemented
- [ ] Point light working
- [ ] Per-pixel shading calculations
- [ ] Materials with different properties
- [ ] Test scene: lit sphere or bunny showing specular highlights
- [ ] Ambient, diffuse, specular visible

---

### Week 11: Texture Mapping

**Time:** 12 hours

**Goals:**

- Add UV coordinate support
- Implement texture sampling
- Load and apply textures

**Key Components:**

- UV coordinates in mesh data (from OBJ vt)
- UV interpolation using barycentric coordinates
- Texture class: load images with stb_image.h
- Texture sampling (nearest neighbor, then bilinear)
- Texture wrapping modes (repeat, clamp)
- Combine texture with lighting

**Deliverables:**

- [ ] UV coordinate system working
- [ ] stb_image.h integrated
- [ ] Texture loading from PNG/JPG
- [ ] Bilinear filtering implemented
- [ ] Test scene: textured cube or sphere
- [ ] Texture coordinates mapping correctly (no distortion)

---

### Week 12: Normal Mapping

**Time:** 12 hours

**Goals:**

- Implement normal mapping for surface detail
- Calculate tangent space per-triangle
- Transform normals correctly

**Key Components:**

- Tangent and bitangent calculation
- TBN (Tangent-Bitangent-Normal) matrix
- Load normal maps (RGB → XYZ)
- Transform normals from tangent to world space
- Use perturbed normals in lighting
- Combine with diffuse texture

**Deliverables:**

- [ ] Tangent space calculation working
- [ ] Normal maps loading and sampling
- [ ] TBN matrix constructed correctly
- [ ] Test scene: flat surface with normal map showing detail
- [ ] Normal mapping enhances lighting realism
- [ ] Compare with/without normal mapping

---

## Phase 5: Ray Tracing Foundation (Weeks 13-14)

### Week 13: Basic Ray Tracer

**Time:** 12 hours

**Goals:**

- Build separate ray tracing renderer
- Implement ray-geometry intersection
- Render simple ray traced scenes

**Key Components:**

- Ray class: origin, direction, at(t) function
- Ray-sphere intersection (quadratic formula)
- Ray-triangle intersection (Möller-Trumbore algorithm)
- Camera ray generation (one ray per pixel)
- Scene with primitives (spheres, triangles)
- Basic diffuse shading

**Deliverables:**

- [ ] Ray class implemented
- [ ] Ray-sphere intersection working
- [ ] Ray-triangle intersection working (Möller-Trumbore)
- [ ] Can render scene with spheres
- [ ] Output to separate image file
- [ ] Test image: 3-5 spheres with basic shading

---

### Week 14: Shadows & Reflections

**Time:** 12 hours

**Goals:**

- Add shadow rays for realistic shadows
- Implement recursive reflections
- Basic material system (diffuse, reflective)

**Key Components:**

- Shadow rays: hit point → light source
- Shadow intersection test (any hit, not closest)
- Reflection ray calculation (mirror formula)
- Recursive ray tracing (limit depth: 5-10 bounces)
- Material types: diffuse, mirror, glass (optional)
- Combine direct lighting with shadows

**Deliverables:**

- [ ] Shadow rays implemented
- [ ] Shadows rendering correctly
- [ ] Reflection rays working
- [ ] Recursive ray tracing with depth limit
- [ ] Test scene: reflective spheres with shadows
- [ ] Compare render times (document performance)

---

## Phase 6: CUDA Acceleration (Weeks 15-16)

### Week 15: CUDA Setup & First Kernel

**Time:** 12 hours

**Goals:**

- Install and set up CUDA toolkit
- Write first CUDA kernel
- Port ray-triangle intersection to GPU

**Key Components:**

- CUDA project setup (.cu files, nvcc compiler)
- Understand kernel launch: <<<blocks, threads>>>
- GPU memory management: cudaMalloc, cudaMemcpy, cudaFree
- Thread index calculation: blockIdx, threadIdx
- Simple parallel kernel: ray-triangle intersection tests
- Error checking and synchronization
- Benchmark CPU vs GPU

**Deliverables:**

- [ ] CUDA toolkit installed and configured
- [ ] First CUDA kernel compiling and running
- [ ] Ray-triangle intersection on GPU
- [ ] Memory transfers working correctly
- [ ] Performance comparison: CPU vs GPU
- [ ] Document speedup achieved (10x+ expected)

---

### Week 16: Hybrid Rendering System

**Time:** 12 hours

**Goals:**

- Combine rasterizer (CPU) with ray tracing (GPU)
- Implement hybrid rendering effects
- Final integration and optimization

**Key Components:**

- Rasterize primary geometry on CPU
- Identify pixels needing ray tracing (reflections, shadows)
- Launch CUDA kernels for secondary rays
- Pass scene data to GPU efficiently
- Shadow ray kernel: test occlusion for each pixel
- Reflection ray kernel: compute reflected color
- Merge results back into framebuffer
- Performance profiling and optimization

**Deliverables:**

- [ ] Hybrid renderer working (raster + ray trace)
- [ ] CPU rasterization outputs to framebuffer
- [ ] GPU ray tracing for shadows/reflections
- [ ] Results combined correctly
- [ ] Performance metrics documented
- [ ] Test scene: rasterized geometry with ray-traced effects
- [ ] Comparison: pure raster vs hybrid rendering

---

## PART 2: VULKAN RENDERER (Weeks 17-20)

---

### Week 17: Vulkan Setup & Triangle

**Time:** 12 hours

**Goals:**

- Set up Vulkan development environment
- Understand Vulkan initialization
- Render first triangle

**Key Components:**

- Vulkan SDK installation
- Instance and physical device selection
- Logical device creation
- Surface and swapchain setup
- Render pass configuration
- Graphics pipeline: vertex/fragment shaders (GLSL)
- Command buffers and command pools
- Draw single hardcoded triangle

**Deliverables:**

- [ ] Vulkan SDK installed and configured
- [ ] Vulkan instance created
- [ ] Window with Vulkan surface
- [ ] Graphics pipeline created
- [ ] Triangle rendering on screen
- [ ] Understand Vulkan verbosity vs your software renderer

---

### Week 18: Vulkan 3D Rendering

**Time:** 12 hours

**Goals:**

- Port 3D rendering to Vulkan
- Use vertex/index buffers
- Implement MVP matrices with uniform buffers

**Key Components:**

- Vertex Buffer Object (VBO) creation
- Index Buffer Object (IBO)
- Staging buffers for GPU uploads
- Uniform buffers for MVP matrices
- Descriptor sets and layouts
- Update uniforms per frame
- Load OBJ models into Vulkan buffers
- Camera controls (reuse existing camera class)

**Deliverables:**

- [ ] 3D models rendering in Vulkan
- [ ] Vertex and index buffers working
- [ ] MVP matrices updating correctly
- [ ] Camera controls functional
- [ ] Can navigate around 3D scene
- [ ] Compare performance: software vs Vulkan (100x+ faster expected)

---

### Week 19: Vulkan Textures & Lighting

**Time:** 12 hours

**Goals:**

- Add texture support to Vulkan renderer
- Implement lighting in shaders
- Match software renderer visual quality

**Key Components:**

- Vulkan image creation and staging
- Sampler objects for texture filtering
- Descriptor sets for textures
- Fragment shader with Phong lighting (GLSL)
- Uniform buffer for light data
- Normal mapping in shaders
- Compare with software renderer output

**Deliverables:**

- [ ] Textures loading and displaying
- [ ] Texture sampling in fragment shader
- [ ] Phong lighting in shaders
- [ ] Normal mapping working
- [ ] Visual quality matches software renderer
- [ ] Performance analysis: frame time comparisons

---

### Week 20: Vulkan Compute & Comparison

**Time:** 12 hours

**Goals:**

- Use Vulkan compute shaders for ray tracing
- Compare all three approaches
- Final documentation and portfolio

**Key Components:**

- Compute pipeline setup
- Compute shader for ray tracing (GLSL)
- Storage buffers for scene data
- Dispatch compute work
- Image output from compute shader
- Optional: Vulkan ray tracing extension (if hardware supports)
- Compare: software CPU, CUDA, Vulkan compute

**Deliverables:**

- [ ] Vulkan compute shader ray tracing working
- [ ] Performance comparison: CPU vs CUDA vs Vulkan
- [ ] Documentation complete
- [ ] Final demo video or screenshots
- [ ] Blog post or writeup of journey
- [ ] GitHub README with all features listed

---

## Post-Project: Portfolio & Documentation

### Documentation Checklist

- [ ] Comprehensive README.md on GitHub
- [ ] Architecture diagram of renderer
- [ ] Performance benchmarks with graphs
- [ ] Code comments and documentation
- [ ] Build instructions for all platforms

### Portfolio Content

- [ ] Demo video (2-5 minutes) showing features
- [ ] Blog series (3-5 posts) documenting journey
- [ ] Technical writeup: "Building a Graphics Renderer from Scratch"
- [ ] Before/after comparisons (images/videos)
- [ ] LinkedIn post announcing project completion

### Resume/Interview Prep

- [ ] Resume bullet: "Built hybrid CPU/GPU renderer with CUDA acceleration"
- [ ] Prepare to explain key technical decisions
- [ ] Practice explaining graphics pipeline from memory
- [ ] Prepare performance optimization examples
- [ ] Document lessons learned

---

## Key Milestones Summary

|Week|Phase|Major Deliverable|Interview Value|
|---|---|---|---|
|1|Foundation|Math library|Vector/matrix operations|
|3|Foundation|Triangle rasterization|Edge functions, barycentric coords|
|6|3D Rendering|OBJ model rendering|3D pipeline, transformations|
|9|Interactive|60 FPS viewer|Optimization, real-time systems|
|12|Materials|PBR rendering|Lighting models, textures|
|14|Ray Tracing|Shadows/reflections|Ray-geometry intersection|
|16|CUDA|Hybrid renderer|Parallel programming, GPU arch|
|18|Vulkan|3D in Vulkan|Modern graphics APIs|
|20|Complete|Full comparison|Deep graphics knowledge|

---

## Success Criteria

By week 20 you will have:

- ✅ Software renderer: rasterization, lighting, textures
- ✅ Ray tracer: shadows, reflections, materials
- ✅ CUDA acceleration with documented speedups
- ✅ Vulkan renderer matching software quality
- ✅ Performance comparisons across all approaches

---

## Resources

### Books

- **Computer Graphics: Principles and Practice** (Foley et al.) - Reference
- **Real-Time Rendering** (Akenine-Möller et al.) - Advanced topics
- **Ray Tracing in One Weekend** (Shirley) - Free online, excellent intro

### Online Resources

- **scratchapixel.com** - Best graphics fundamentals website
- **learnopengl.com** - Concepts apply even without OpenGL
- **vulkan-tutorial.com** - Step-by-step Vulkan guide
- **pbr-book.org** - Advanced rendering (for later)
- **CUDA C++ Programming Guide** - Official NVIDIA docs

### Tools

- **Debugging:** GDB/LLDB, Visual Studio debugger
- **Memory:** Valgrind, Address Sanitizer
- **Profiling:** perf, gprof, Visual Studio profiler
- **CUDA:** NVIDIA NSight Compute, NSight Systems
- **Vulkan:** RenderDoc, Vulkan Configurator
- **Version Control:** Git, GitHub Desktop

### Assets

- **Stanford 3D Scanning Repository** - Free models (bunny, dragon)
- **learnopengl.com/resources** - Textures and models
- **Free PBR textures** - ambientCG.com, polyhaven.com
- **HDRI maps** - polyhaven.com (for environment lighting)

---

## Risk Mitigation

### If Falling Behind

- **Skip Week 12** (normal mapping) - nice but not critical
- **Simplify Week 14** - basic ray tracer without recursion OK
- **Lighter Week 9** - basic optimization only
- **Extend timeline** - add 2-4 weeks buffer if needed

### If Ahead of Schedule

- **Add path tracing** (global illumination)
- **Implement BVH** (acceleration structure for ray tracing)
- **Try compute shaders** instead of CUDA in Week 16
- **Add PBR materials** (physically-based rendering)
- **Implement deferred rendering**
- **Add post-processing** (bloom, tone mapping)

### Common Pitfalls

- **Math errors:** Test math library thoroughly in Week 1
- **Coordinate system confusion:** Document your conventions early
- **Performance expectations:** Don't optimize prematurely
- **Scope creep:** Stick to plan, add features only if ahead
- **Vulkan verbosity:** Don't get discouraged, it's normal
- **CUDA debugging:** Can be tricky, use printf debugging

---

## Why This Plan Works for NVIDIA/AMD

### Technical Depth You'll Gain

1. **GPU Architecture:** Memory bandwidth, coalescing, occupancy, thread divergence
2. **Graphics Pipeline:** Every stage from vertex to pixel, deeply understood
3. **Parallel Programming:** Practical CUDA/compute shader experience
4. **Performance:** Concrete optimization examples with measurements
5. **Modern APIs:** Vulkan shows ability to learn complex systems
6. **Problem-Solving:** Self-directed learning and debugging

### Interview Questions You'll Master

- ✅ "How does texture sampling work?" - You implemented it
- ✅ "Explain the graphics pipeline" - You built every stage
- ✅ "What's rasterization vs ray tracing?" - You've done both
- ✅ "How would you optimize a GPU kernel?" - You have examples
- ✅ "What's the difference between Vulkan and OpenGL?" - You understand the abstractions
- ✅ "How does z-buffering work?" - You coded it from scratch
- ✅ "What's barycentric interpolation?" - Used it extensively


---

## Next Steps

### Before Starting Week 1

- [ ] Install C++ compiler (GCC/Clang/MSVC)
- [ ] Install CMake
- [x] Set up Git and create GitHub account
- [ ] Choose IDE and configure
- [ ] Read "Ray Tracing in One Weekend" intro
- [ ] Browse scratchapixel.com rasterization articles
- [ ] Download test OBJ models
- [ ] Set up project tracking (Trello/Notion/GitHub Projects)

### Week 1 Day 1 Action Items

- [x] Create GitHub repository
- [ ] Initialize project structure
- [ ] Write CMakeLists.txt
- [ ] Create Vec3 class header
- [ ] Implement first vector operation
- [ ] Commit and push to GitHub
- [ ] Update project tracker

---

**Ready to start? Begin with Week 1, Day 1 and commit to the 12 hours/week. You've got this!**