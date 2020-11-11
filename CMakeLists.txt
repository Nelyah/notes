cmake_minimum_required(VERSION 3.18.4)

project(notes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

add_subdirectory(src bin)

message(STATUS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${PROJECT_SOURCE_DIR}/ ${EXECUTABLE_OUTPUT_PATH} Compiler has filesystem support")
