cmake_minimum_required(VERSION 3.25)
project(hangman)
set(CMAKE_CXX_STANDARD 17)


# Find package installed in system
find_package(OpenGL REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Freetype REQUIRED)

# Include OPENGL Header Files
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(libraries/irrKlang/include/)
include_directories(${FREETYPE_INCLUDE_DIR_ft2build})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
include_directories(include/)

#GLFW Disable Unnecessary Builds
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


add_subdirectory(libraries/glfw)

# Adding the static library .so files
add_library(irrKlang SHARED IMPORTED)
set_property(TARGET irrKlang PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libraries/irrKlang/bin/linux-gcc-64/libIrrKlang.so)
file(GLOB HANGMAN_SOURCES src/*.cpp)
# set(LAB2_SOURCE_FILES src/labs/sutherland_hodgemann.cpp)
add_executable(hangman ${HANGMAN_SOURCES} src/Shader.cpp src/Navigator.cpp include/Navigator.hpp include/Screen.hpp src/GameScreen.cpp include/GameScreen.hpp src/DataService.cpp include/DataService.hpp include/Utilities.hpp src/Utilities.cpp include/InputHandlers.hpp src/InputHandlers.cpp include/DrawHangman.hpp src/DrawHangman.cpp src/WonScreen.cpp include/WonScreen.hpp src/DeadScreen.cpp include/DeadScreen.hpp include/SoundEffectService.h src/SoundEffectService.cpp)
# add_executable(hangman ${LAB2_SOURCE_FILES})

target_link_libraries(hangman ${OPENGL_LIBRARIES} ${FREETYPE_LIBRARIES} ${GLEW_LIBRARIES} ${EIGEN3_LIBRARIES}  glfw irrKlang)
