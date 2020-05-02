# Copyright 2013-2016, Corvusoft Ltd, All Rights Reserved.

project( "libbaseservice" )

#
# Configuration
#


#
# Dependencies
#

#
# Build
#

set( BUILD_LIBBASESERVICE_MANIFEST
    servicefactory.cpp
    servicelogger.cpp
    serviceconfig.cpp
    jsonclient.cpp
    jsonservice.cpp
    jsonresource.cpp
)

set( BUILD_LIBBASESERVICE_MANIFEST_HEADERS
    servicefactory.h
    servicelogger.h
    serviceconfig.h
    jsonclient.h
    jsonservice.h
    jsonresource.h
    exception/serviceexception.h
    exception/requestexception.h
    exception/externalserviceexception.h
)

add_library( libbaseservice ${BUILD_LIBBASESERVICE_MANIFEST} ${BUILD_LIBBASESERVICE_MANIFEST_HEADERS})

target_link_libraries( libbaseservice PUBLIC restbed nlohmann_json::nlohmann_json)
target_include_directories( libbaseservice 
	PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}"
          "${restbed_SOURCE_DIR}/source"
	)
	
target_compile_options(libbaseservice
  PRIVATE
    $<$<CXX_COMPILER_ID:Gnu>:
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
