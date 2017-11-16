# The main server executable

include_directories("${CMAKE_SOURCE_DIR}/include")

file(GLOB_RECURSE srcFiles src/*.cpp)

add_executable(collab-server ${srcFiles})

target_link_libraries(collab-server
    ${CJSON_LIBRARY}
    "-lzmq")

add_custom_target(run collab-server)

