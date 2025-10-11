cmake_minimum_required(VERSION 3.15)
project(GRL VERSION 0.1.0 LANGUAGES CXX)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Include directories
include_directories(include)

# Source files
set(GRL_SOURCES
    src/math/vec3.cpp
    src/math/vec4.cpp
    src/math/mat4.cpp
    src/graphics/color.cpp
    src/graphics/framebuffer.cpp
    src/graphics/rasterizer.cpp
    src/graphics/renderer.cpp
    src/utils/image_writer.cpp
)

# Create static library
add_library(grl STATIC ${GRL_SOURCES})
target_include_directories(grl PUBLIC include)

# Examples
add_executable(week1_test examples/week1_test.cpp)
target_link_libraries(week1_test grl)

# Testing
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Installation (optional)
install(TARGETS grl
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)
