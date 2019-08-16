cmake_minimum_required(VERSION 3.1)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_executable(leetcode main.cpp)

add_subdirectory(leetcode)
add_subdirectory(bishi)
add_subdirectory(jianzhi_offer)
add_subdirectory(data_struct)
add_subdirectory(qiuzhao)