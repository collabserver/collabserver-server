include_directories("${CMAKE_SOURCE_DIR}/common/include")


# Common elt
file(GLOB_RECURSE srcCommonFiles common/src/*.cpp)


# Main server
include_directories("${CMAKE_SOURCE_DIR}/server/include")
file(GLOB_RECURSE srcServerFiles server/src/*.cpp)
add_executable(collab-server ${srcCommonFiles} ${srcServerFiles})
target_link_libraries(collab-server
    ${CJSON_LIBRARY}
    ${ELEPHANT_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(run collab-server)


# CPP Proxy
include_directories("${CMAKE_SOURCE_DIR}/clients/cpp_proxy/include")
file(GLOB_RECURSE srcCppProxy clients/cpp_proxy/*.cpp)
add_library(cpp_proxy STATIC ${srcCommonFiles} ${srcCppProxy})
target_link_libraries(cpp_proxy
    ${ELEPHANT_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")


# Debug client (Msg Spawner)
include_directories("${CMAKE_SOURCE_DIR}/clients/debugger/include")
file(GLOB_RECURSE srcDebugger clients/debugger/*.cpp)
add_executable(debugger ${srcCommonFiles} ${srcDebugger})
target_link_libraries(debugger
    ${CJSON_LIBRARY}
    ${ELEPHANT_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    cpp_proxy
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(rundebugger debugger)
