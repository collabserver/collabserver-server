cmake_minimum_required(VERSION 3.14)
project(collabserver-server)
message(STATUS "[${PROJECT_NAME}] Building project")

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# Compiler Flags
message(STATUS "Detected Operating System: ${CMAKE_SYSTEM_NAME}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    message(WARNING "No BUILD_TYPE set for ${PROJECT_NAME}: uses default Release")
    message(WARNING "Available build types: Debug Release RelWithDebInfo MinSizeRel")
    set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "BUILD_TYPE for ${PROJECT_NAME}: ${CMAKE_BUILD_TYPE}")


# Dependencies
message(STATUS "Adding dependencies for ${PROJECT_NAME}")
include_directories("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-datatypes/include")
include_directories("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-network/include")
add_subdirectory("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-datatypes")
add_subdirectory("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-network")


# Server executable
include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE srcFilesServer "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${srcFilesServer})
target_link_libraries(${PROJECT_NAME} collabserver-network-lib)
add_custom_target(run collabserver-server)


# TODO googletests to re-integrate
## Tests
#option(COLLABSERVER_TESTS "Build Tests" OFF)
#if(COLLABSERVER_TESTS)
#    message(STATUS "Build tests for ${PROJECT_NAME}")
#    enable_testing()
#
#    include_directories("${PROJECT_SOURCE_DIR}/include/")
#    file(GLOB_RECURSE srcFilesTests "${PROJECT_SOURCE_DIR}/test/*.cpp")
#    file(GLOB_RECURSE srcFilesCore "${PROJECT_SOURCE_DIR}/src/core/*.cpp")
#    add_executable(${PROJECT_NAME}-tests ${srcFilesTests} ${srcFilesCore})
#
#    # Googletest dependency
#    include_directories("${PROJECT_SOURCE_DIR}/extern/googletest/googletest/include/")
#    add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest-1.10.0")
#    target_link_libraries(${PROJECT_NAME}-tests gtest)
#
#    add_test(NAME googletests COMMAND ${PROJECT_NAME}-tests)
#    add_custom_target(runAllTests ${PROJECT_NAME}-tests)
#endif()

