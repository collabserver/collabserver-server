# Collab Server

[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-server/blob/dev/LICENSE.txt)
[![Build Status](https://travis-ci.org/CollabServer/collab-server.svg?branch=master)](https://travis-ci.org/CollabServer/collab-server)

| master | dev |
| :-----: | :-----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-server.svg?branch=master)](https://travis-ci.org/CollabServer/collab-server) | [![Build Status](https://travis-ci.org/CollabServer/collab-server.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-server) |


## Overview
Server for realtime collaboration on any `CollabData`.


## Features
- Users
    - Connect user to the server
    - Disconnect user from the server
- Room (Collaborative Room)
    - Enter: user enter the collab room.
    - Leave: user leave the collab room and doesn't receive updates anymore.
    - Create: create a new room of collaboration.
    - Delete: remove room of collaboration from server.

**Collaborative Room (User point of view)**:
A Collaborative room is a current instance of collaboration where several users
are working on the same Data. The data itself is any implementation of
`CollabData` interface with a set of `Operation` implemented (See `collab-data-crdts`).

**Collaborative Room (In server)**:
The server doesn't know anything about the concrete data implementation.
A room only store the list of operations applied since the beginning.
The server deals with the broadcasting system and ensure that all users in a
room receive each operations.


## Build instructions (CMake)

### Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. Not support certified for Mac and Windows

### Dependencies
All dependencies are automatically downloaded by CMake and placed in a folder
named `dependencies`.
You may move this folder in another place later and request CMake not to
download dependencies anymore (**See CMake options**).

If you are using a custom permanent location for your dependencies, a convenient
solution is to set the environment variable `COLLAB_DEPENDENCIES_DIR` with this path.
CMake will use this one as the default location (Except if a custom path is
given as CMake parameter).

- [GoogleTest](https://github.com/google/googletest) (Only required for tests)

### Manual dependencies (System Wide)
These dependencies must be installed system-wide and are not downloaded by CMake.
Check the instruction specific to your operating system for further information.
(Ex: `pacman -S zeromq` on ArchLinux)

- [ZeroMQ](http://zeromq.org/) (**Must be installed system-wide**)

### Git submodules
These are used internally by collab-server and are compiled along with collab-server.
You may work on the submodules from this project.

- [collab-common](https://github.com/CollabServer/collab-common.git) (CMake)
- [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git) (CMake)

```bash
# To clone project with submodules
git clone --recursive https://github.com/CollabServer/collab-server.git
cd collab-server

# To pull also submodules
git pull --recurse-submodules=on
```

### CMake options
| Name | Description |
| --- | --- |
| COLLAB_DEPENDENCIES_DIR | (STRING) Path to a directory where to find all dependencies (By default, uses current cmake build) |
| COLLAB_DEPENDENCIES_DOWNLOAD | (ON/OFF) Set ON to also download dependencies at cmake time. This is useful the first time you setup the project. Dependencies are placed in COLLAB_DEPENDENCIES_DIR. (By default: OFF).|
| COLLAB_TESTS | (ON/OFF) Set ON to build unit tests |
| CMAKE_BUILD_TYPE | Debug, Release, RelWithDebInfo, MinSizeRel |


### Build and run server with CMake
```bash
# Manual
mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON ..
make -j2
make runCollabServer

# Using script
./build.sh
cd build
make runCollabServer
```

### Build and run tests with CMake
```bash
# Manual
mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON -DCOLLAB_TESTS=ON ..
make -j2
make runAllTests

# Using script
./build.sh
# Tests should start by default. If not, follow the manual instructions
```


## Contribution
Feel free to ask me any question, share your ideas or open an issue.
I created this project during my master thesis at University of Montreal.
I generally try to follow the [Google C++ Coding Style](https://google.github.io/styleguide/cppguide.html)
with some exceptions (For instance, I use 4 space indentation).


# Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))


