
add_executable(TestHelloWorldCore
  TestHelloWorldCore.swift)
target_link_libraries(TestHelloWorldCore PRIVATE
  HelloWorldCore)

add_test(NAME TestHelloWorldCore
  COMMAND TestHelloWorldCore)

