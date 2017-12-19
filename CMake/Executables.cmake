include_directories("${CMAKE_SOURCE_DIR}/common/include")


# Common elt
file(GLOB_RECURSE srcCommonFiles ${CMAKE_SOURCE_DIR}/common/src/*.cpp)


# Main server
include_directories("${CMAKE_SOURCE_DIR}/server/include")
file(GLOB_RECURSE srcServerFiles ${CMAKE_SOURCE_DIR}/server/src/*.cpp)
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
include_directories("${CMAKE_SOURCE_DIR}/proxies/cpp_proxy/include")
file(GLOB_RECURSE srcCppProxy ${CMAKE_SOURCE_DIR}/proxies/cpp_proxy/*.cpp)
add_library(cpp_proxy STATIC ${srcCommonFiles} ${srcCppProxy})
target_link_libraries(cpp_proxy
    ${ELEPHANT_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")


# Message Debugger
include_directories("${CMAKE_SOURCE_DIR}/clients/msgDebugger/include")
file(GLOB_RECURSE srcDebugger ${CMAKE_SOURCE_DIR}/clients/msgDebugger/*.cpp)
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
