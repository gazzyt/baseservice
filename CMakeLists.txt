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

#include(DownloadProject)

# Restbed

find_path(restbed_INCLUDE_DIR restbed)
find_library(restbed_LIBRARY NAMES librestbed.a)

# nlohmann/json

find_path(json_INCLUDE_DIR nlohmann/json.hpp)

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
