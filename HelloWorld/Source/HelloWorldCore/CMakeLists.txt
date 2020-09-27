
add_library(HelloWorldCore
  _HelloWorldCore.swift
  HelloWorldCore.swift)
target_compile_options(HelloWorldCore PRIVATE
  $<$<BOOL:BUILD_TESTING>:-enable-testing>)
target_link_libraries(HelloWorldCore PRIVATE
  CCore)
set_target_properties(HelloWorldCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_Swift_MODULE_DIRECTORY})

install(TARGETS HelloWorldCore
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  COMPONENT lib)
