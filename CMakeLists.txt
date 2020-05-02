cmake_minimum_required( VERSION 3.4.1 )

project( "baseservice-root" VERSION 1.0.0)



#
# Configuration
#
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to be used")
set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

enable_testing()

#
# Dependencies
#

include(DownloadProject)

# Restbed

set(BUILD_SSL OFF CACHE BOOL "Build secure socket layer support." FORCE)

download_project(PROJ                restbed
                 GIT_REPOSITORY      https://github.com/Corvusoft/restbed.git
                 GIT_TAG             4.6
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(${restbed_SOURCE_DIR} ${restbed_BINARY_DIR})

# nlohmann/json

set(JSON_BuildTests OFF CACHE BOOL "Build json tests." FORCE)

download_project(PROJ                json
                 GIT_REPOSITORY      https://github.com/nlohmann/json.git
                 GIT_TAG             v3.7.3
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR})

#
# Build
#

add_subdirectory (libbaseservice)

#
# Install
#
#include( "${CMAKE_SOURCE_DIR}/cmake/build_artifacts.cmake" )

#install( FILES "${INCLUDE_DIR}/${PROJECT_NAME}" DESTINATION "include" )
#install( FILES ${BUILD_ARTIFACTS} DESTINATION "include/corvusoft/${PROJECT_NAME}" )
#install( TARGETS ${PROJECT_NAME}
#         LIBRARY DESTINATION "library"
#         ARCHIVE DESTINATION "library" COMPONENT library )
