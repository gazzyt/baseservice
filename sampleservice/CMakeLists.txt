project( "sampleservice" )

#
# Configuration
#

#
# Dependencies
#


#
# Build
#

set( BUILD_SAMPLESERVICE_MANIFEST
	main.cpp
  sampleresource.cpp
)

set( BUILD_SAMPLESERVICE_MANIFEST_HEADERS
  sampleresource.h
)

add_executable( sampleservice ${BUILD_SAMPLESERVICE_MANIFEST} ${BUILD_SAMPLESERVICE_MANIFEST_HEADERS})

target_link_libraries( sampleservice PRIVATE libbaseservice )
target_link_libraries( sampleservice
  PRIVATE
    "$<$<CXX_COMPILER_ID:GNU>:-static-libgcc -static-libstdc++ -static -no-pie>"
#    $<$<CXX_COMPILER_ID:Clang>:
#      # clang warning flags
 #   >
#    $<$<CXX_COMPILER_ID:MSVC>:
#      # MSVC warning flags
#    >
)

target_compile_options( sampleservice
  PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:
      -Weffc++
    >
    $<$<CXX_COMPILER_ID:Clang>:
      # clang warning flags
    >
    $<$<CXX_COMPILER_ID:MSVC>:
      # MSVC warning flags
    >
)


#
# Install
#
#include( "${CMAKE_SOURCE_DIR}/cmake/build_artifacts.cmake" )

#install( FILES "${INCLUDE_DIR}/${PROJECT_NAME}" DESTINATION "include" )
#install( FILES ${BUILD_ARTIFACTS} DESTINATION "include/corvusoft/${PROJECT_NAME}" )
#install( TARGETS ${PROJECT_NAME}
#         LIBRARY DESTINATION "library"
#         ARCHIVE DESTINATION "library" COMPONENT library )
