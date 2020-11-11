cmake_minimum_required(VERSION 3.18.4)

add_executable(notes_executable
  main.cpp
  directoryRunner.cpp
)


set_property (TARGET notes_executable PROPERTY OUTPUT_NAME "notes")
install (TARGETS notes_executable DESTINATION ${EXECUTABLE_OUTPUT_PATH})
