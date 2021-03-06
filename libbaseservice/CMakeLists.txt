# Copyright 2013-2016, Corvusoft Ltd, All Rights Reserved.

project( "libbaseservice" )

#
# Configuration
#


#
# Dependencies
#

# Restbed

find_path(restbed_INCLUDE_DIR restbed)
find_library(restbed_LIBRARY NAMES librestbed.a restbed.lib)
find_package(Threads REQUIRED)

# nlohmann/json

find_path(json_INCLUDE_DIR nlohmann/json.hpp)


#
# Build
#

set( BUILD_LIBBASESERVICE_MANIFEST
    servicefactory.cpp
    servicelogger.cpp
    jsonclient.cpp
    jsonservice.cpp
    basicjsonresource.cpp
)

set( BUILD_LIBBASESERVICE_MANIFEST_HEADERS
    servicefactory.h
    servicelogger.h
    jsonclient.h
    jsonservice.h
    basicjsonresource.h
    jsonresource.h
    exception/serviceexception.h
    exception/requestexception.h
    exception/externalserviceexception.h
    exception/validationexception.h
)

add_library( libbaseservice ${BUILD_LIBBASESERVICE_MANIFEST} ${BUILD_LIBBASESERVICE_MANIFEST_HEADERS})

target_link_libraries( libbaseservice PUBLIC ${restbed_LIBRARY} Threads::Threads )
target_include_directories( libbaseservice 
	PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}"
          "${restbed_INCLUDE_DIR}"
          ${json_INCLUDE_DIR}
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
