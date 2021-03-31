cmake_minimum_required( VERSION 3.7.0 )

find_package(Dobby)

string( TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE )

# Set the 'AI' build type defines for removing some of the code on release builds
add_definitions( -DAI_DEBUG=1 -DAI_RELEASE=2 )
if( BUILD_TYPE STREQUAL "RELEASE" )
    add_definitions( -DAI_BUILD_TYPE=AI_RELEASE )
elseif( BUILD_TYPE STREQUAL "DEBUG" )
    add_definitions( -DAI_BUILD_TYPE=AI_DEBUG )
else()
    message( FATAL_ERROR "BUILD_TYPE '${BUILD_TYPE}' not supported" )
endif()

# Add Plugins
add_subdirectory(SuperAwesomePlugin)