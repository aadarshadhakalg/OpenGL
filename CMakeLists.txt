cmake_minimum_required(VERSION 3.25)
project(flag)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
#GLFW Disable Unnecessary Builds
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


add_subdirectory(libraries/glfw)

set(SOURCE_FILES legacy.cpp)
add_executable(flag ${SOURCE_FILES})

target_link_libraries(flag ${OPENGL_LIBRARIES} glfw)