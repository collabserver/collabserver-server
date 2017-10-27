include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(collab-server main.cpp)
add_custom_target(run collab-server)

