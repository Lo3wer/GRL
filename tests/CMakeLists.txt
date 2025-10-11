# Testing setup
# Using a simple approach without external dependencies for now
# You can switch to Catch2 or Google Test later if desired

# Math tests
add_executable(test_vec3 math/test_vec3.cpp)
target_link_libraries(test_vec3 grl)

add_executable(test_vec4 math/test_vec4.cpp)
target_link_libraries(test_vec4 grl)

add_executable(test_mat4 math/test_mat4.cpp)
target_link_libraries(test_mat4 grl)

# Graphics tests
add_executable(test_framebuffer graphics/test_framebuffer.cpp)
target_link_libraries(test_framebuffer grl)

# Register tests
add_test(NAME Vec3Tests COMMAND test_vec3)
add_test(NAME Vec4Tests COMMAND test_vec4)
add_test(NAME Mat4Tests COMMAND test_mat4)
add_test(NAME FramebufferTests COMMAND test_framebuffer)
