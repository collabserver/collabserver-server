include_directories("${CMAKE_SOURCE_DIR}/gitmodules/collab-client-interface/include")


# ------------------------------------------------------------------------------
# Build collab-client-interface
# ------------------------------------------------------------------------------

# TODO

# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------
file(GLOB_RECURSE srcDebug ${CMAKE_SOURCE_DIR}/debug/src/*.cpp)
add_executable(debugger ${srcDebug})
add_custom_target(runDebugger debugger)
target_link_libraries(debugger "zmq")

