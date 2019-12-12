cmake_minimum_required(VERSION 3.15.1)

project(hello LANGUAGES Swift)

add_library(HiKit hikit.swift)
set_target_properties(HiKit PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR})

add_executable(hello hello.swift)
target_link_libraries(hello PRIVATE HiKit)
