cmake_minimum_required(VERSION 3.8)
project(reversi)

set(CMAKE_CXX_STANDARD 14)

set(include_dir "include")
set(src_dir "src")

file(GLOB_RECURSE include_files "${include_dir}/*.h")
file(GLOB_RECURSE source_files "${src_dir}/*.cpp")

set(SOURCE_FILES
        ${include_files}
        ${source_files}
        )

message("${include_files}")
message("${source_files}")

include_directories(${include_dir})

add_executable(reversi ${SOURCE_FILES})