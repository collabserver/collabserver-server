set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Packages")


# cJSON
include_directories("$ENV{DEPENDENCIES_DEVEL}/collab-server/cJSON/include")
target_link_libraries(${TARGET_EXEC_NAME} "$ENV{DEPENDENCIES_DEVEL}/collab-server/cJSON/lib/libcjson.a")

# ZeroMQ
target_link_libraries(${TARGET_EXEC_NAME} "-lzmq")
