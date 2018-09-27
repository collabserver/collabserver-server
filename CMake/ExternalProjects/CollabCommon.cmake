# ------------------------------------------------------------------------------
# Project collab-common (gitsubmodule)
# ------------------------------------------------------------------------------

include(ExternalProject)
ExternalProject_Add(collab-common
    SOURCE_DIR          "${COLLAB_GITMODULES_DIR}/collab-common/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-common-build/"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                        "-DCOLLAB_DEPENDENCIES_DOWNLOAD=${COLLAB_DEPENDENCIES_DOWNLOAD}"
                        "-DCOLLAB_DEPENDENCIES_DIR=${COLLAB_DEPENDENCIES_DIR}"
)

add_library(collabcommon STATIC IMPORTED)
ExternalProject_Get_Property(collab-common BINARY_DIR)
set_property(TARGET collabcommon
    PROPERTY IMPORTED_LOCATION "${BINARY_DIR}/libcollabcommon.a")


