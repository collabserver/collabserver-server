# Collab Server

[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collabserver-server/blob/dev/LICENSE.txt)
[![Build Status](https://travis-ci.org/CollabServer/collabserver-server.svg?branch=master)](https://travis-ci.org/CollabServer/collabserver-server)

| master | dev |
| :-----: | :-----: |
| [![Build Status](https://travis-ci.org/CollabServer/collabserver-server.svg?branch=master)](https://travis-ci.org/CollabServer/collabserver-server) | [![Build Status](https://travis-ci.org/CollabServer/collabserver-server.svg?branch=dev)](https://travis-ci.org/CollabServer/collabserver-server) |

## Overview

---

Server for realtime collaboration on any `CollabData` from `collab-data-crdts`
project.

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

## Getting Started

---

1. Clone project with submodules
    - Clone with recursive: `git clone --recursive https://github.com/CollabServer/collabserver-server.git`
    - To pull changes from submodules, uses: `git pull --recurse-submodules=on`
    - For further informations about submodules, check the [official Git documentation](https://git-scm.com/book/en/v2/Git-Tools-Submodules)
1. Build the server
    - Be sure you have all the requirements
    - Build collabserver-server (See build instructions)
1. Start the server
    - Open a console and run the collabserver executable
    - Logs are displayed here
    - Ctrl+C to stop server
1. Connect users
    - Users implement the [collabserver-client](https://github.com/CollabServer/collabserver-client) to connect with Server
    - Server port is 4242
    - Local IP is localhost
    - The [collabserver-grapheditor](https://github.com/CollabServer/collabserver-grapheditor) is a full example client using this server

## Features

---

- Users
  - Connection
  - Disconnection
  - Enter room
  - Leave room
  - Create room
  - Delete room
- Room
  - Room ID (to join the room of collaboration)
  - Add user
  - Remove user
  - Has user
  - Broadcast operation to all users

## Build (CMake)

---

- Requirements
  - [CMake](https://cmake.org/)
  - C++11
  - `pragma once` support
  - Tested with gcc 4.8.4
  - Tested with clang 5.0.0
  - Tested only on Linux. No support certified for Mac and Windows
- Dependencies (already in the repo and built by CMake)
  - [GoogleTest](https://github.com/google/googletest)
  - [collabserver-network](https://github.com/CollabServer/collabserver-network)
  - [collabserver-datatypes](https://github.com/CollabServer/collabserver-datatypes)

```bash
# Build and start the server
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make run # This start the CollabServer

# Or using build script
./build.sh
cd build
make run
```

```bash
# Build the tests
mkdir build
cd build
cmake -DCOLLABSERVER_TESTS=ON ..
make
make runAllTests

# Or use the build script
./build.sh
```

| CMake option | Description |
| --- | --- |
| COLLABSERVER_TESTS | (ON / OFF) Set ON to build unit tests |
| CMAKE_BUILD_TYPE | Debug, Release, RelWithDebInfo, MinSizeRel |

## Generate Documentation

---

1. Install [Doxygen](https://www.stack.nl/~dimitri/doxygen/)
1. Run `doxygen Doxyfile`
1. Files are placed in `doc` folder

## Contribution

---

Feel free to ask me any question, share your ideas or open an issue.
I started this project during my master thesis at University of Montreal.
Format uses clang-format with the Google Coding style <https://google.github.io/styleguide/cppguide.html> (see `.clang-format` for further information).
Make sure you autoformat on save (see <https://clang.llvm.org/docs/ClangFormat.html>)
