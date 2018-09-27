option(COLLAB_DEPENDENCIES_DOWNLOAD "Download dependencies" OFF)


# ------------------------------------------------------------------------------
# Dependencies path
# ------------------------------------------------------------------------------

# Priority: argument > env > default
if(DEFINED COLLAB_DEPENDENCIES_DIR)
    set(_PATH "${COLLAB_DEPENDENCIES_DIR}")

elseif(IS_DIRECTORY "$ENV{COLLAB_DEPENDENCIES_DIR}")
    set(_PATH "$ENV{COLLAB_DEPENDENCIES_DIR}")

else()
    set(_PATH "${CMAKE_BINARY_DIR}/dependencies")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/dependencies")

endif()

message(STATUS "Dependencies path: ${_PATH}")
if(NOT IS_DIRECTORY "${_PATH}")
    # Here, must stop right now
    message("WARNING: Invalid dependencies folder")
    message(FATAL_ERROR "The path to dependencies is not a valid directory")
endif()

set(COLLAB_DEPENDENCIES_DIR "${_PATH}" CACHE PATH "Path to the dependencies folder")


# ------------------------------------------------------------------------------
# Add Dependencies
# ------------------------------------------------------------------------------

include("CMake/Dependencies/AddGoogleTest.cmake")


