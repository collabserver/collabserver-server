# Collab Server

[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-server/blob/dev/LICENSE.txt)


## Overview
Server for realtime collaboration.
> Work in progress!


## Requirements
- C++11
- `pragma once` support
- Tested only on Linux. Not support certified for Mac and Windows


## Dependencies
> Dependencies marked with *(CMake)* are automatically downloaded by CMake
> script and placed in *bin* folder.
> Others must be installed manually (Generally system-wide install).
- [collab-common](https://github.com/CollabServer/collab-common.git) (CMake)
- [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git) (CMake)
- [ZeroMQ](http://zeromq.org/) (Must be installed system-wide)


## Build instructions

### Clone project with dependencies
```bash
git clone --recursive https://github.com/CollabServer/collab-server.git
cd collab-server
```

### Build types
- CMake build types (ex: `-DCMAKE_BUILD_TYPE=Debug`):
    - Debug
    - Release
    - RelWithDebInfo
    - MinSizeRel

### Build server and run with CMake
```cmake
# Build manually
mkdir build
cd build
cmake ..
make -j4
make runServer

# Build from shell script
./build.sh
cd build
make runServer
```

### Build and run tests with CMake
- [GoogleTest](https://github.com/google/googletest)
(Automatically downloaded by CMake and placed in project's root folder `bin`
```cmake
# Build manually
mkdir build
cd build
cmake ..
make -j4
make runServer

# Build from shell script
./build.sh
```


# Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))


