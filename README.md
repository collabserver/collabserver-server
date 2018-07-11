# Collab Server

[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![Build Status](https://travis-ci.org/CollabServer/collab-server.svg?branch=master)](https://travis-ci.org/CollabServer/collab-server)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-server/blob/dev/LICENSE.txt)

| master | dev |
| :-----: | :-----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-server.svg?branch=master)](https://travis-ci.org/CollabServer/collab-server) | [![Build Status](https://travis-ci.org/CollabServer/collab-server.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-server) |


## Overview
Server for realtime collaboration.
> Work in progress...


## Requirements
- C++11
- `pragma once` support
- Tested only on Linux. Not support certified for Mac and Windows


## Dependencies
> Dependencies marked with *(CMake)* are automatically downloaded by CMake
> script and placed in *dependencies* folder.
> Others must be installed manually (Generally system-wide install).
- [ZeroMQ](http://zeromq.org/) (**Must be installed system-wide**)
- [collab-common](https://github.com/CollabServer/collab-common.git) (CMake)
- [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git) (CMake)
- [GoogleTest](https://github.com/google/googletest) (CMake)


## Build instructions

### Clone project with dependencies
```bash
git clone --recursive https://github.com/CollabServer/collab-server.git
cd collab-server

# To pull, use
git pull --recurse-submodules=on
```

### Build types
- CMake build types (ex: `-DCMAKE_BUILD_TYPE=Debug`):
    - Debug
    - Release
    - RelWithDebInfo
    - MinSizeRel

### Build and run server with CMake
#### Manual build instructions
```bash
mkdir build
cd build
cmake ..
make -j4
make runCollabServer
```
#### Script build instructions
```bash
./build.sh
cd build
make runCollabServer
```

### Build and run tests with CMake
#### Manual build tests instructions
```bash
mkdir build
cd build
cmake -Dcollab_tests=ON ..
make -j4
make runAllTests
```
#### Script build tests instructions
```bash
./build.sh
# Tests should start by default.
# If not, follow the manual instructions
```


# Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))


