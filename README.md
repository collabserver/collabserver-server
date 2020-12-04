# Collab Server

[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collabserver-server/blob/dev/LICENSE.txt)
[![Build Status](https://travis-ci.org/CollabServer/collabserver-server.svg?branch=master)](https://travis-ci.org/CollabServer/collabserver-server)

| master | dev |
| :-----: | :-----: |
| [![Build Status](https://travis-ci.org/CollabServer/collabserver-server.svg?branch=master)](https://travis-ci.org/CollabServer/collabserver-server) | [![Build Status](https://travis-ci.org/CollabServer/collabserver-server.svg?branch=dev)](https://travis-ci.org/CollabServer/collabserver-server) |


# Overview
Server for realtime collaboration on any `CollabData` from `collab-data-crdts`
project.


# Getting Started
1. Clone project with submodules
    - Clone with recursive: `git clone --recursive https://github.com/CollabServer/collabserver-server.git`
    - To pull changes from submodules, uses: `git pull --recurse-submodules=on`
    - For further informations about submodules, check the [official Git documentation](https://git-scm.com/book/en/v2/Git-Tools-Submodules)
1. Setup CollabServer
    - Be sure you have all the system-wide dependencies and requirements
    - Install system-wide dependencies if required
    - Build collabserver-server (See build instructions)
1. Start CollabServer
    - Open a console and run collabserver executable
    - Logs are displayed here (User connection, disconnection etc...)
    - Ctrl+C to stop server.
1. Connect users
    - User implements `collab-client-interface` to connect with Server
    - Server port is 4242
    - Local IP is localhost
    - `collab-grapheditor` is an example of user


# Features
- Users
    - Connection
    - Disconnection
    - Enter room
    - Leave room
    - Create room
    - Delete room
- Collaborative Room
    - **User point of view**:
    a Collaborative room is a current instance of collaboration where several
    users are working on the same Data. The data itself is any implementation
    of `CollabData` interface with a set of `Operation` implemented
    (See `collab-data-crdts`).
    - **In server**:
    the server doesn't know anything about the concrete data implementation.
    A room only store the list of operations applied since the beginning.
    The server deals with the broadcasting system and ensure that all users in
    a room receive each operations.


# Build on Linux (CMake)
**Build executable**
```bash
# Warning: Install system-wide dependencies
# Be sure you have all requirements

mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON ..
make
make run # This start the CollabServer

# Or using build script
./build.sh
cd build
make run
```

**Build Tests**
```bash
# Warning: Install system-wide dependencies
# Be sure you have all requirements

mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON -DCOLLAB_TESTS=ON ..
make
make runAllTests

# Or using build script
./build.sh
```

**CMake options**

| CMake option Name | Description |
| --- | --- |
| COLLAB_DEPENDENCIES_DIR | (STRING) Path to a directory where to find all dependencies (By default, uses current cmake build) |
| COLLAB_DEPENDENCIES_DOWNLOAD | (ON/OFF) Set ON to also download dependencies at cmake time. This is useful the first time you setup the project. Dependencies are placed in COLLAB_DEPENDENCIES_DIR. (By default: OFF).|
| COLLAB_TESTS | (ON/OFF) Set ON to build unit tests |
| CMAKE_BUILD_TYPE | Debug, Release, RelWithDebInfo, MinSizeRel |


# Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. **Not support certified for Mac and Windows**
- CMake (2.8.2 or higher)


# Dependencies
- System-Wide (**Must be installed manually**)
    - [ZeroMQ](http://zeromq.org/) (Release 3.1.1)
        - ArchLinux: `pacman -S zeromq`
        - Ubuntu: `apt-get install libzmq3 libzmq3-dev`
        - There is also a [Windows binary here](http://zeromq.org/distro:microsoft-windows) (Not tested yet)
- Automatically downloaded and built by CMake
    - [GoogleTest](https://github.com/google/googletest) (Release 1.8.1)
    - [collab-common](https://github.com/CollabServer/collab-common.git) (Git submodule)
    - [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git) (Git submodule)

**Option: save dependencies for offline use**
> Dependencies downloaded by CMake are placed in the current CMake build folder
> (in `dependencies` folder).
> This is useful the firs time.
> To speedup the cmake process, you may keep these downloaded and built dependencies
> in a safe place and change the CMake dependencies path (See CMake options).

**Option: use environment variable for dependencies path**
> If `COLLAB_DEPENDENCIES_DIR` environment variable is set, CMake will use
> it as the current dependencies path.


# Generate Documentation
1. Install [Doxygen](https://www.stack.nl/~dimitri/doxygen/)
1. `doxygen Doxyfile`
1. Files are placed in `doc` folder


# Contribution
Feel free to ask me any question, share your ideas or open an issue.
I created this project during my master thesis at University of Montreal.
I generally try to follow the [Google C++ Coding Style](https://google.github.io/styleguide/cppguide.html)
with some exceptions (For instance, I use 4 space indentation).

Uses C++11


# Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))


