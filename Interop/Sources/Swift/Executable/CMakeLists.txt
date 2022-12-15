add_executable(E
  E.swift)
target_compile_options(E PRIVATE
  -enable-experimental-cxx-interop)
target_link_libraries(E PRIVATE
  cxx_library)
