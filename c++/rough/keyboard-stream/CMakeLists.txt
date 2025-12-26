cmake_minimum_required(VERSION 3.10)
project(KeyboardStream)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find evdev library
find_package(PkgConfig REQUIRED)
pkg_check_modules(EVDEV REQUIRED libevdev)

add_executable(keyboard_stream keyboard_stream.cpp)

# Link required libraries
target_link_libraries(keyboard_stream pthread ${EVDEV_LIBRARIES})

# Set include directories
target_include_directories(keyboard_stream PRIVATE ${EVDEV_INCLUDE_DIRS})

# Optimize for release
set(CMAKE_BUILD_TYPE Release)

# Add compiler flags
target_compile_options(keyboard_stream PRIVATE -Wall -Wextra -O2)