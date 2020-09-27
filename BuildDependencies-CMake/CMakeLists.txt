cmake_minimum_required(VERSION 3.16.0)
project(P
  LANGUAGES Swift)

if(CMAKE_VERSION VERSION_LESS 3.17)
  if(NOT CMAKE_SYSTEM_NAME STREQUAL Windows)
    set(CMAKE_EXECUTABLE_RUNTIME_Swift_FLAG "-Xlinker -rpath -Xlinker ")
    set(CMAKE_SHARED_LIBRARY_RUNTIME_Swift_FLAG "-Xlinker -rpath -Xlinker ")
    if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
      set(CMAKE_EXECUTABLE_RUNTIME_Swift_FLAG_SEP "")
      set(CMAKE_SHARED_LIBRARY_RUNTIME_Swift_FLAG_SEP "")
    else()
      set(CMAKE_EXECUTABLE_RUNTIME_Swift_FLAG_SEP ":")
      set(CMAKE_SHARED_LIBRARY_RUNTIME_Swift_FLAG_SEP ":")
    endif()
  endif()
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_Swift_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/swift)

include(ExternalProject)

function(import_module module_name build_dir build_target)
  add_library(${module_name} IMPORTED SHARED)
  if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    set_target_properties(${module_name} PROPERTIES
      IMPORTED_LOCATION ${build_dir}/bin/${CMAKE_SHARED_LIBRARY_PREFIX}${module_name}${CMAKE_SHARED_LIBRARY_SUFFIX}
      IMPORTED_IMPLIB ${build_dir}/lib/${CMAKE_IMPORT_LIBRARY_PREFIX}${module_name}${CMAKE_IMPORT_LIBRARY_SUFFIX}
      INTERFACE_INCLUDE_DIRECTORIES ${build_dir}/swift)
  else()
    set_target_properties(${module_name} PROPERTIES
      IMPORTED_LOCATION ${build_dir}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}${module_name}${CMAKE_SHARED_LIBRARY_SUFFIX}
      INTERFACE_INCLUDE_DIRECTORIES ${build_dir}/swift)
  endif()
  add_dependencies(${module_name} ${build_target})
endfunction()

ExternalProject_Add(swift-numerics
  GIT_REPOSITORY
    git://github.com/apple/swift-numerics
  GIT_TAG
    master
  CMAKE_ARGS
    -D BUILD_SHARED_LIBS=YES
    -D BUILD_TESTING=NO
    -D CMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}
    -D CMAKE_Swift_COMPILER=${CMAKE_Swift_COMPILER}
    -D CMAKE_Swift_COMPILER_TARGET=${CMAKE_Swift_COMPILER_TARGET}
    -D CMAKE_Swift_FLAGS=${CMAKE_Swift_FLAGS}
  INSTALL_COMMAND
    ""
  BUILD_BYPRODUCTS
    <BINARY_DIR>/bin/${CMAKE_SHARED_LIBRARY_PREFIX}Numerics${CMAKE_SHARED_LIBRARY_SUFFIX}
    <BINARY_DIR>/lib/${CMAKE_IMPORT_LIBRARY_PREFIX}Numerics${CMAKE_IMPORT_LIBRARY_SUFFIX}
  UPDATE_DISCONNECTED
    TRUE
  STEP_TARGETS
    build)
ExternalProject_Get_Property(swift-numerics BINARY_DIR)

file(MAKE_DIRECTORY ${BINARY_DIR}/swift)

import_module(Numerics ${BINARY_DIR} swift-numerics-build)
import_module(ComplexModule ${BINARY_DIR} swift-numerics-build)
import_module(RealModule ${BINARY_DIR} swift-numerics-build)

ExternalProject_Get_Property(swift-numerics SOURCE_DIR)

add_library(_NumericsShims IMPORTED INTERFACE)
set_target_properties(_NumericsShims PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${SOURCE_DIR}/Sources/_NumericsShims/include)
add_dependencies(_NumericsShims swift-numerics-build)

add_subdirectory(Sources)
