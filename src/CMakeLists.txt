cmake_minimum_required(VERSION 3.18.4)

include_directories (${CMAKE_SOURCE_DIR}/src)
message (STATUS "${PROJECT_SOURCE_DIR}  ${CMAKE_SOURCE_DIR}")

add_library(notes
  directoryRunner.cpp directoryRunner.h)

add_executable(notes_executable main.cpp)

target_link_libraries (notes_executable notes)


set_property (TARGET notes_executable PROPERTY OUTPUT_NAME "notes")
install (TARGETS notes_executable DESTINATION ${EXECUTABLE_OUTPUT_PATH})
