#
# Generate internal libraries (Generally compile them as static libs)
# Author: Constantin Masson
#


# ------------------------------------------------------------------------------
# Common (Used by both server and proxy)
# ------------------------------------------------------------------------------
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


# ------------------------------------------------------------------------------
# Proxy (End user front end proxy)
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/common/include")
include_directories("${CMAKE_SOURCE_DIR}/proxie/include")
file(GLOB_RECURSE srcCppProxy ${CMAKE_SOURCE_DIR}/proxie/*.cpp)

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


