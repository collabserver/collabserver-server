
# ------------------------------------------------------------------------------
# Build collab-client-interface
# ------------------------------------------------------------------------------
set(COLLAB_CLIENT_SRC_DIR "${GITMODULE_DIR}/collab-client-interface/")
set(COLLAB_CLIENT_BUILD_DIR "${CMAKE_BINARY_DIR}/collab-client-build/")
set(COLLAB_CLIENT_LIBRARY "${COLLAB_CLIENT_BUILD_DIR}/libclient_interface.a")

file(MAKE_DIRECTORY "${COLLAB_CLIENT_BUILD_DIR}")

execute_process(
    COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" "${COLLAB_CLIENT_SRC_DIR}"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/collab-client-build"
    RESULT_VARIABLE error)
if(error)
    message(FATAL_ERROR "Unable to cmake collab-client: ${error}")
endif()

execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE error
    WORKING_DIRECTORY "${COLLAB_CLIENT_BUILD_DIR}")
if(error)
    message(FATAL_ERROR "Unable to build collab-client: ${error}")
endif()


# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/gitmodules/collab-client-interface/include")

file(GLOB_RECURSE srcDebug ${CMAKE_SOURCE_DIR}/debug/src/*.cpp)
add_executable(debugger ${srcDebug})
add_custom_target(runDebugger debugger)
target_link_libraries(debugger "zmq" "${COLLAB_CLIENT_LIBRARY}")

