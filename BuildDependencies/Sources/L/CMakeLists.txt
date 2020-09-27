add_library(L SHARED
  L.swift)
target_link_libraries(L PUBLIC
  Numerics
  _NumericsShims)
