# CMake Examples for Swift

This repository contains example projects demonstrating how to setup a Swift project with CMake.  Make sure to use the CMake Ninja generator and Ninja build tool. These hopefully cover a wide variety of use cases.  Patches to add examples of missing use cases are welcome.

## Projects
- Hello Minimal
  * Simple project with a pure Swift library and executable
- Build Dependencies
  * Simple project with a library that depends on an external package which is built as part of the build
- Hello World
  * Multi-library project with C and Swift code

# Why Use This

CMake is a meta-build system that allows you to generate the build rules using different build tools. It also makes it possible to setup the build in a way which supports cross-compiling for various targets (including Linux, Windows, and android).

# How to build with CMake

If `swiftc` is not in your path, you will need to add `-DCMAKE_Swift_COMPILER=`
with the path to swiftc.

<details>
  <summary>Linux or macOS</summary>


```bash
cmake -B build -D CMAKE_BUILD_TYPE=RelWithDebInfo -D BUILD_TESTING=YES -G Ninja -S .
ninja -C build
ninja -C build test
```
</details>

<details>
  <summary>Windows</summary>

> **NOTE:** we must build with the Release configuration on Windows as the Swift runtime
> in debug configuration is not distributed with the standard toolchain.  MSVCRT cannot
> be used in different configurations in the same process, and will result in runtime
> failures.

```cmd
set SWIFTFLAGS=-sdk %SDKROOT%
cmake -B build -D CMAKE_BUILD_TYPE=Release -D BUILD_TESTING=YES -G Ninja -S .
ninja -C build
ninja -C build test
```
</details>

This invocation builds the project in release mode with debug information.  This
enables optimized builds with debug information.  Additionally, the standard
CMake option `BUILD_TESTING` is used to enable tests.

## What is supported

These project build on Linux, macOS, and Windows!

- `CMAKE_BUILD_TYPE`
  * `Debug` (no optimizations, debug info)
  * `Release` (all optimizations, no debug info)
  * `RelWithDebInfo` (all optimizations, debug info)
  * `MinSizeRel` (optimized for size)

- `MSVC_RUNTIME_LIBRARY` (*Windows Only*)
  * `MultiThreadedDebugDLL` (`MDd`)
  * `MultiThreadedDLL` (`MD`)
