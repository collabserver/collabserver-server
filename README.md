# Collab Server

[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![license](https://img.shields.io/badge/license-GPLv3-blue.svg)](https://github.com/GeekyMoose/elephant-logger-realtime/blob/dev/LICENSE.txt://github.com/GeekyMoose/collab-server/blob/dev/LICENSE.txt)

Server for realtime collaboration.
> Work in progress!


# Dependencies and requirements
- C++11
- pragma support (pragma once)
- [Elephant Logger](https://github.com/GeekyMoose/elephant-logger-realtime)
- [ZeroMQ](http://zeromq.org/)
- [MessagePack](https://msgpack.org/)
- [cJSON](https://github.com/DaveGamble/cJSON)


# Build and run on GNU/Linux with CMake
- [CMake](https://cmake.org/)

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j4
make run
```
> DCMAKE_BUILD_TYPE options: Debug / Release / RelWithDebInfo / MinSizeRel


# Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
