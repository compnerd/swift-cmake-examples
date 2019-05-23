
add_library(HelloWorldCore
  _HelloWorldCore.swift
  HelloWorldCore.swift)
target_compile_options(HelloWorldCore PRIVATE
  $<$<BOOL:ENABLE_TESTING>:-enable-testing>)
set_target_properties(HelloWorldCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_Swift_MODULE_DIRECTORY})

