cmake_minimum_required(VERSION 3.17)
project(PlayerLink)

set(CMAKE_CXX_STANDARD 20)
add_library(PlayerLink_Core SHARED library.cpp library.h
        crypto/hash/sha/sha256.cpp
        crypto/hash/sha/sha256.h

        crypto/pki/DFH.c

        net/Protocols.h
        net/Socket.h
        )

add_executable(PlayerLink_Server main.cpp) # Builds the server.