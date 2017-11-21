include_directories("${CMAKE_SOURCE_DIR}/include")


# Main server
file(GLOB_RECURSE srcFiles src/*.cpp)
add_executable(collab-server ${srcFiles})
target_link_libraries(collab-server
    ${CJSON_LIBRARY}
    ${ELEPHANT_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(run collab-server)


# Debug client (Msg Spawner)
file(GLOB_RECURSE srcSpawner debug/*.cpp)
add_executable(spawner ${srcSpawner})
target_link_libraries(spawner
    ${ELEPHANT_LIBRARY}
    "pthread"
    "stdc++fs"
    "zmq")
add_custom_target(runspawner spawner)
