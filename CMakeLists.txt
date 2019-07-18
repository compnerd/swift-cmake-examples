
cmake_minimum_required(VERSION 3.15.20190717)

project(SwiftDemo LANGUAGES C Swift)

# place all modules into `swift` in the root of the build tree
set(CMAKE_Swift_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/swift)

# enable shard libraries by default
option(BUILD_SHARED_LIBS "Build shared libraries by default" YES)
# enable testing by default on debug mode
option(BUILD_TESTING "Build tests" $<CONFIG:Debug>)

include(CTest)

add_subdirectory(Source)
if(BUILD_TESTING)
  add_subdirectory(Tests)
endif()

