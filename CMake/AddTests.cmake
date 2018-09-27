enable_testing()

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------

include_directories("${CMAKE_SOURCE_DIR}/include/")

file(GLOB_RECURSE srcFilesTests "${CMAKE_SOURCE_DIR}/test/*.cpp")
file(GLOB_RECURSE srcFilesCore "${CMAKE_SOURCE_DIR}/src/core/*.cpp")

add_executable(tests ${srcFilesTests} ${srcFilesCore})
target_link_libraries(tests gtest)
add_test(NAME googletests COMMAND tests)
add_custom_target(runAllTests tests)


