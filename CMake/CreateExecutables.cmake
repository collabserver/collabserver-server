#
# Create the executables
# Author: Constantin Masson
#


# ------------------------------------------------------------------------------
# Server executable
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/server/include")
include_directories("${CMAKE_SOURCE_DIR}/common/include")

file(GLOB_RECURSE srcServer ${CMAKE_SOURCE_DIR}/server/src/*.cpp)
add_executable(collab-server ${srcServer})

target_link_libraries(collab-server
    ${COMMON_LIBRARY}
    ${CJSON_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    ${ELEPHANT_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(run collab-server)


#-------------------------------------------------------------------------------
# Message Debugger
#-------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/client/msgDebugger/include")
include_directories("${CMAKE_SOURCE_DIR}/common/include")
include_directories("${CMAKE_SOURCE_DIR}/proxy/include")

file(GLOB_RECURSE srcDebugger ${CMAKE_SOURCE_DIR}/client/msgDebugger/src/*.cpp)
add_executable(debugger ${srcDebugger})

target_link_libraries(debugger
    ${PROXY_CPP_LIBRARY}
    ${CJSON_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    ${ELEPHANT_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(rundebugger debugger)
