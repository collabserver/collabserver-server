set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Packages")


# cJSON
set(cjsonDir "$ENV{COLLABSERVER_DEPENDENCIES}/cJSON")
set(CJSON_LIBRARY "${cjsonDir}/lib/libcjson.a")
include_directories("${cjsonDir}/include")


# Elephant Logger
set(elephantDir "$ENV{COLLABSERVER_DEPENDENCIES}/ElephantLogger")
set(ELEPHANT_LIBRARY "${elephantDir}/lib/libelephantlogger.a")
include_directories("${elephantDir}/include")
