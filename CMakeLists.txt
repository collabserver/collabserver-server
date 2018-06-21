cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-server)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Various
# ------------------------------------------------------------------------------
set(DEPENDENCY_DIR "${CMAKE_SOURCE_DIR}/bin/")
set(GIT_SUBMODULE_DIR "${CMAKE_SOURCE_DIR}/gitmodules/")

include(CMake/AddCompilerFlags.cmake)


# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------
option(BUILD_TESTS "Build Tests" OFF)

if(BUILD_TESTS)
    message(STATUS "Build tests")
    include("CMake/AddTests.cmake")
else()
    message(STATUS "Doesn't build tests")
endif()


# ------------------------------------------------------------------------------
# Debug
# ------------------------------------------------------------------------------
option(BUILD_DEBUG "Build Debug" OFF)

if(BUILD_DEBUG)
    message(STATUS "Build debug")
    include("CMake/AddDebug.cmake")
else()
    message(STATUS "Doesn't build debug")
endif()


# ------------------------------------------------------------------------------
# Server executable
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/gitmodules/collab-data-crdts/include")
include_directories("${CMAKE_SOURCE_DIR}/gitmodules/collab-messaging-protocol/include")

file(GLOB_RECURSE srcFiles ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(server ${srcFiles})
add_custom_target(runServer server)

target_link_libraries(server "zmq")


