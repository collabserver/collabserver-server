cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-server)


if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


include(CMake/CompilerFlags.cmake)


# Create executable
include_directories("${CMAKE_SOURCE_DIR}/include")
add_executable(collab-server src/main.cpp)
add_custom_target(run collab-server)

