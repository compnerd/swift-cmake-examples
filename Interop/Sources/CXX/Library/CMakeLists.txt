add_library(cxx_library STATIC
  library.cc)
target_include_directories(cxx_library PUBLIC
  include)
set_target_properties(cxx_library PROPERTIES
  CXX_STANDARD 11
  OUTPUT_NAME CXXLibrary)
