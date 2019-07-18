
add_executable(HelloWorld
  HelloWorld.swift)
target_link_libraries(HelloWorld PRIVATE
  HelloWorldCore)

install(TARGETS HelloWorld
  DESTINATION bin
  COMPONENT exe)

