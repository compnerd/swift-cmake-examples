
add_executable(HelloWorld
  HelloWorld.swift)
target_link_libraries(HelloWorld PRIVATE
  HelloWorldCore)
set_target_properties(HelloWorld PROPERTIES
  Swift_LANGUAGE_VERSION 4.2)

install(TARGETS HelloWorld
  DESTINATION bin
  COMPONENT exe)

