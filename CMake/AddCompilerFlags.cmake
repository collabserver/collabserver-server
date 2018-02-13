#
# Setup all compiler flags depending on current build type (Debug, Release etc...)
# Author: Constantin Masson
#

message(STATUS "Detected Operating System: ${CMAKE_SYSTEM_NAME}")


# ------------------------------------------------------------------------------
# WINDOWS (32, 64)
# ------------------------------------------------------------------------------
if(WIN32)
    message(FATAL_ERROR "Windows System not supported, use Visual Studio instead")


# ------------------------------------------------------------------------------
# MAC
# ------------------------------------------------------------------------------
elseif("${CMAKE_SYSTEM_NAME}" MATCHES "Darwin")
    message(FATAL_ERROR "Apple System not supported")


# ------------------------------------------------------------------------------
# LINUX
# ------------------------------------------------------------------------------
elseif("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
    message(STATUS "Set flags and variables for Build '${CMAKE_BUILD_TYPE}'")

    if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Winline")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11")

    elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")

    elseif("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -g")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -Wall")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -std=c++11")

    elseif("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
        set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -std=c++11")

    elseif("${CMAKE_BUILD_TYPE}" STREQUAL "")
        message(AUTHOR_WARNING "No Build Type set. You may want to use option -DCMAKE_BUILD_TYPE=Debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    else()
        message(FATAL_ERROR "Invalid Build Type. You may want to use option -DCMAKE_BUILD_TYPE=Debug")

    endif()


# ------------------------------------------------------------------------------
# UNKNOWN
# ------------------------------------------------------------------------------
else()
    # Unknown OS
    message(FATAL_ERROR "Unsupported operating system")
endif()

