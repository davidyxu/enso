cmake_minimum_required(VERSION 2.8)

project(game)

set(BIN "glfw_test")

include_directories(include)
add_executable(${BIN} src/glfw_test.c)

# GLFW
# turn off extra GLFW make targets
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw)
target_link_libraries(${BIN} glfw)

# GL3W
add_library(gl3w src/gl3w.c)

if (UNIX)
  target_link_libraries(gl3w dl)
endif()

target_link_libraries(${BIN} gl3w)
