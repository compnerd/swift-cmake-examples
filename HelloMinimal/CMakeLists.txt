cmake_minimum_required(VERSION 3.15.1)

project(hello LANGUAGES Swift)

if(CMAKE_SYSTEM_NAME STREQUAL Windows OR CMAKE_SYSTEM_NAME STREQUAL Darwin)
  option(BUILD_SHARED_LIBS "Build shared libraries by default" YES)
endif()

add_library(HiKit hikit.swift)
set_target_properties(HiKit PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR})

add_executable(hello hello.swift)
target_link_libraries(hello PRIVATE HiKit)
