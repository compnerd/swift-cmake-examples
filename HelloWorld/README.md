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
CMake option `BUILD_TESTING` is used to enable tests.  This builds tests and is
used in the `HelloWorldCore` library to enable testable exports.

## What is supported

This project builds on Linux, macOS, and Windows!

- `CMAKE_BUILD_TYPE`
  * `Debug` (no optimizations, debug info)
  * `Release` (all optimizations, no debug info)
  * `RelWithDebInfo` (all optimizations, debug info)
  * `MinSizeRel` (optimized for size)

- `MSVC_RUNTIME_LIBRARY`
  * `MultiThreadedDebugDLL` (`MDd`)
  * `MultiThreadedDLL` (`MD`)
