
cmake_minimum_required(VERSION 3.14.20190603)

project(SwiftDemo LANGUAGES C Swift)

# place all modules into `swift` in the root of the build tree
set(CMAKE_Swift_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/swift)

# enable shard libraries by default
option(BUILD_SHARED_LIBS "Build shared libraries by default" YES)

# enable testing by default on debug mode
option(ENABLE_TESTING "build tests" $<CONFIG:Debug>)

if(ENABLE_TESTING)
  enable_testing()
endif()

add_subdirectory(Source)
if(ENABLE_TESTING)
  add_subdirectory(Tests)
endif()

