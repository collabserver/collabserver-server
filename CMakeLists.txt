cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-server)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Various
# ------------------------------------------------------------------------------
set(collab_dependency_dir "${CMAKE_SOURCE_DIR}/bin/")
set(collab_gitmodule_dir "${CMAKE_SOURCE_DIR}/gitmodules/")

include("CMake/AddCompilerFlags.cmake")


# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------
option(collab_tests "Build Tests" OFF)

if(collab_tests)
    message(STATUS "Build tests")
    include("CMake/AddTests.cmake")
else()
    message(STATUS "Doesn't build tests")
endif()


# ------------------------------------------------------------------------------
# Server executable
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${collab_gitmodule_dir}/collab-data-crdts/include")
include_directories("${collab_gitmodule_dir}/collab-common/include")

file(GLOB_RECURSE srcFilesServer ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(collabserver ${srcFilesServer})
add_custom_target(runCollabServer collabserver)

target_link_libraries(collabserver "zmq")


