cmake_minimum_required(VERSION 3.8)
project(reversi)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-sign-compare")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(include_dir "include")
set(src_dir "src")

file(GLOB_RECURSE include_files "${include_dir}/*.h")
file(GLOB_RECURSE source_files "${src_dir}/*.cc")

set(SOURCE_FILES
        ${include_files}
        ${source_files}
        )

message("${include_files}")
message("${source_files}")

include_directories(${include_dir})

add_executable(reversi ${SOURCE_FILES})