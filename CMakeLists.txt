
cmake_minimum_required(VERSION 3.15.20190717)

project(SwiftDemo LANGUAGES C Swift)

# place all modules into `swift` in the root of the build tree
set(CMAKE_Swift_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/swift)

# enable shared libraries by default (Windows, Darwin)
#
# Windows does not yet support static libraries in Swift, Darwin no longer
# supports static libraries after ABI stability.
if(CMAKE_SYSTEM_NAME MATCHES "Windows|Darwin")
  set(DEFAULT_VALUE_BUILD_SHARED_LIBS YES)
else()
  set(DEFAULT_VALUE_BUILD_SHARED_LIBS YES)
endif()
option(BUILD_SHARED_LIBS "Build shared libraries by default"
 ${DEFAULT_VALUE_BUILD_SHARED_LIBS})

option(BUILD_TESTING "Build tests" $<CONFIG:Debug>)

include(CTest)

add_subdirectory(Source)
if(BUILD_TESTING)
  add_subdirectory(Tests)
endif()

