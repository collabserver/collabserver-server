#
# Include all dependencies
# Author: Constantin Masson
#

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Packages")


# To work, environment variable must point to dependency folder.
if(NOT EXISTS "$ENV{COLLABSERVER_DEPENDENCIES}")
    message(FATAL_ERROR
        "Invalid environment variabe COLLABSERVER_DEPENDENCIES."
        "Variable may be not set or use invalid path")
endif()


#-------------------------------------------------------------------------------
# cJSON
#-------------------------------------------------------------------------------
set(cjsonDir "$ENV{COLLABSERVER_DEPENDENCIES}/cJSON")
set(CJSON_LIBRARY "${cjsonDir}/lib/libcjson.a")
include_directories("${cjsonDir}/include")


#-------------------------------------------------------------------------------
# Elephant Logger
#-------------------------------------------------------------------------------
set(elephantDir "$ENV{COLLABSERVER_DEPENDENCIES}/elephant-logger")
set(ELEPHANT_LIBRARY "${elephantDir}/lib/libelephantlogger.a")
include_directories("${elephantDir}/include")


#-------------------------------------------------------------------------------
# MessagePack C/C++
#-------------------------------------------------------------------------------
set(msgpackcDir "$ENV{COLLABSERVER_DEPENDENCIES}/msgpack-c")
set(MSGPACK_C_LIBRARY "${msgpackcDir}/lib/libmsgpackc.a")
include_directories("${msgpackcDir}/include")
