cmake_minimum_required(VERSION 3.26)

if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif()

project(P
  LANGUAGES Swift)

set(CMAKE_Swift_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/swift)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(Numerics
  GIT_REPOSITORY https://github.com/apple/swift-numerics
  GIT_TAG main)

set(BUILD_TESTING NO)
FetchContent_MakeAvailable(Numerics)

add_executable(E
  Sources/E.swift)
target_link_libraries(E PUBLIC
  RealModule)
