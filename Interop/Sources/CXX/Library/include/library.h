#ifndef library_library_h
#define library_library_h

namespace library {
struct Version {
  int major;
  int minor;
  int patch;
};

Version version() noexcept;
}

#endif
