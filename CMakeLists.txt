cmake_minimum_required(VERSION 3.25)
project(flag)
set(CMAKE_CXX_STANDARD 17)


# Find package installed in system
find_package(OpenGL REQUIRED)
find_package(Eigen3 REQUIRED)

# Include OPENGL Header Files
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(libraries/glew/include/)
include_directories(${EIGEN3_INCLUDE_DIRS})

#GLFW Disable Unnecessary Builds
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


add_subdirectory(libraries/glfw)

set(LAB2_SOURCE_FILES cohen_sutherland.cpp)
add_executable(flag ${LAB2_SOURCE_FILES})

target_link_libraries(flag ${OPENGL_LIBRARIES} ${EIGEN3_LIBRARIES} ${CMAKE_SOURCE_DIR}/libraries/glew/lib/Release/x64/glew32s.lib glfw)
