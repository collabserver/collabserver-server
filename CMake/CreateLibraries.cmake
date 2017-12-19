# Common
include_directories("${CMAKE_SOURCE_DIR}/common/include")
file(GLOB_RECURSE srcCommon ${CMAKE_SOURCE_DIR}/common/src/*.cpp)
add_library(common STATIC ${srcCommon})
target_link_libraries(common
    ${MSGPACK_C_LIBRARY}
    ${CJSON_LIBRARY}
    ${ELEPHANT_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
set(COMMON_LIBRARY common)


# CPP Proxy
include_directories("${CMAKE_SOURCE_DIR}/common/include")
include_directories("${CMAKE_SOURCE_DIR}/proxies/cpp_proxy/include")
file(GLOB_RECURSE srcCppProxy ${CMAKE_SOURCE_DIR}/proxies/cpp_proxy/*.cpp)
add_library(cpp_proxy STATIC ${srcCppProxy})
target_link_libraries(cpp_proxy
    ${COMMON_LIBRARY}
    ${MSGPACK_C_LIBRARY}
    ${CJSON_LIBRARY}
    ${ELEPHANT_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
set(PROXY_CPP_LIBRARY cpp_proxy)


