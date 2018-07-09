# ------------------------------------------------------------------------------
# Project collab-common (gitsubmodule)
# ------------------------------------------------------------------------------
include(ExternalProject)
ExternalProject_Add(collab-common
    SOURCE_DIR      "${collab_gitmodule_dir}/collab-common/"
    BINARY_DIR      "${CMAKE_BINARY_DIR}/collab-common-build/"
    INSTALL_COMMAND ""
    TEST_COMMAND    ""
)

add_library(collabcommon STATIC IMPORTED)
ExternalProject_Get_Property(collab-common BINARY_DIR)
set_property(TARGET collabcommon
    PROPERTY IMPORTED_LOCATION "${BINARY_DIR}/libcollabcommon.a")
