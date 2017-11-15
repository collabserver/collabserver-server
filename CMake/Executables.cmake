# The main server executable

set(TARGET_EXEC_NAME collab-server)

file(GLOB_RECURSE srcFiles src/*.cpp)
include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(${TARGET_EXEC_NAME} ${srcFiles})
add_custom_target(run ${TARGET_EXEC_NAME})

