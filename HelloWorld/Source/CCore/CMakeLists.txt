
add_library(CCore SHARED
  CCoreVersion.c)
target_include_directories(CCore PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS CCore
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

