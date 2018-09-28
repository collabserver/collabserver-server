cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-server)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Dependencies / Misc
# ------------------------------------------------------------------------------
include("CMake/AddCompilerFlags.cmake")
include("CMake/AddDependencies.cmake")

# Internal dependencies (Submodules compiled with server executable)
set(COLLAB_GITMODULES_DIR "${CMAKE_SOURCE_DIR}/gitmodules")

include("CMake/ExternalProjects/CollabCommon.cmake")
include_directories("${COLLAB_GITMODULES_DIR}/collab-data-crdts/include")
include_directories("${COLLAB_GITMODULES_DIR}/collab-common/include")


# ------------------------------------------------------------------------------
# Server executable
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/include")

file(GLOB_RECURSE srcFilesServer "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(collabserver ${srcFilesServer})
add_dependencies(collabserver collab-common)
target_link_libraries(collabserver collabcommon zmq)

add_custom_target(runCollabServer collabserver)


# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------
option(COLLAB_TESTS "Build Tests" OFF)

if(COLLAB_TESTS)
    message(STATUS "Build tests")
    include("CMake/AddTests.cmake")
endif()


