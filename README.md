# CMake Swift Example

Example project which demonstrates CMake features used to build Swift code

## What this is

This is an example project which demonstrates how to use the new Swift support
in CMake to build a project using modern CMake techniques.

## Why use this

CMake is a meta-build system that allows you to generate the build rules using
different build tools.  It also makes it possible to setup the build in a way
which supports cross-compiling for various targets (including Linux, Windows,
and android).

## How to build this demo

```sh
cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo -DENABLE_TESTING=YES
cd build
ninja
ninja test
```

This invocation builds the project in release mode with debug information.  This
enables optimized builds with debug information.  Additionally, the standard
CMake option `ENABLE_TESTING` is used to enable tests.  This builds tests and is
used in the `HelloWorldCore` library to enable testable exports.

## What is supported

- `CMAKE_BUILD_TYPE`
  * `Debug` (no optimizations, debug info)
  * `Release` (all optimizations, no debug info)
  * `RelWithDebInfo` (all optimizations, debug info)
  * `MinSizeRel` (optimized for size)

- `MSVC_RUNTIME_LIBRARY`
  * `MultiThreadedDebugDLL` (`MDd`)
  * `MultiThreadedDLL` (`MD`)

