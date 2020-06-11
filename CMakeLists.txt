cmake_minimum_required(VERSION 3.16)
project(cppServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppServer main.cpp Server/Server.cpp Server/Server.h Server/Log/Log.cpp Server/Log/Log.h)

# Tell CMake to add support for pkg-config, then use it to find the library...
include(FindPkgConfig)
pkg_search_module(PISTACHE REQUIRED libpistache>=0.0.2)

include_directories(${PISTACHE_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${PISTACHE_LIBRARIES})
#set(RAPIDJSON_ROOT_DIR PATH "${PROJECT_SOURCE_DIR}/third-party/rapidjson")
#
#find_package(RapidJSON)
#if (RAPIDJSON_FOUND)
#    include_directories(${RAPIDJSON_INCLUDES})
##    pistache_example(rest_description)
#else()
#    message(FATAL_ERROR "RapidJSON not found. Could not build rest_description example.")
#endif()
