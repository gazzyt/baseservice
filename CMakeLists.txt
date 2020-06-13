cmake_minimum_required( VERSION 3.4.1 )

project( "baseservice-root" VERSION 1.0.0)



#
# Configuration
#
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to be used")
set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

# Set the build type if it isn't already
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

IF( NOT DEFINED BUILD_STATIC )
   SET( BUILD_STATIC YES )
ENDIF()

enable_testing()

#
# Dependencies
#

#
# Build
#

add_subdirectory (libbaseservice)
add_subdirectory (sampleservice)

#
# Install
#
#include( "${CMAKE_SOURCE_DIR}/cmake/build_artifacts.cmake" )

#install( FILES "${INCLUDE_DIR}/${PROJECT_NAME}" DESTINATION "include" )
#install( FILES ${BUILD_ARTIFACTS} DESTINATION "include/corvusoft/${PROJECT_NAME}" )
#install( TARGETS ${PROJECT_NAME}
#         LIBRARY DESTINATION "library"
#         ARCHIVE DESTINATION "library" COMPONENT library )
