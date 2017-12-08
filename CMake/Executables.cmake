include_directories("${CMAKE_SOURCE_DIR}/common/include")
include_directories("${CMAKE_SOURCE_DIR}/server/include")
include_directories("${CMAKE_SOURCE_DIR}/clients/debugger/include")


# Main server
file(GLOB_RECURSE srcServerFiles server/src/*.cpp)
file(GLOB_RECURSE srcCommonFiles common/src/*.cpp)
add_executable(collab-server ${srcCommonFiles} ${srcServerFiles})
target_link_libraries(collab-server
    ${CJSON_LIBRARY}
    ${ELEPHANT_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(run collab-server)


# Debug client (Msg Spawner)
file(GLOB_RECURSE srcDebugger clients/debugger/*.cpp)
file(GLOB_RECURSE srcCommonFiles common/src/*.cpp)
add_executable(debugger ${srcCommonFiles} ${srcDebugger})
target_link_libraries(debugger
    ${CJSON_LIBRARY}
    ${ELEPHANT_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(rundebugger debugger)
