add_executable(E
  E.swift)
target_compile_options(E PRIVATE
  -cxx-interoperability-mode=default)
target_link_libraries(E PRIVATE
  cxx_library)
