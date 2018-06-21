# ------------------------------------------------------------------------------
# Project collab-client-interface (gitsubmodule)
# ------------------------------------------------------------------------------
include(ExternalProject)
ExternalProject_Add(collab-client-interface
    SOURCE_DIR          "${GIT_SUBMODULE_DIR}/collab-client-interface/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-client-interface-build"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
)

ExternalProject_Get_Property(collab-client-interface binary_dir)
add_library(client_interface STATIC IMPORTED)
set_property(TARGET client_interface PROPERTY IMPORTED_LOCATION
    "${binary_dir}/libclient_interface.a")


# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/gitmodules/collab-client-interface/include")

file(GLOB_RECURSE srcDebug ${CMAKE_SOURCE_DIR}/debug/src/*.cpp)

add_executable(debugger ${srcDebug})
add_dependencies(debugger collab-client-interface)
add_custom_target(runDebugger debugger)

target_link_libraries(debugger "zmq" client_interface)


