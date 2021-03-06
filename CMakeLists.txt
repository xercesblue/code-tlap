project(code-tlap)
cmake_minimum_required(VERSION 2.8)

option(CXX11 "Compile in C+11 Mode" ON)

if (UNIX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-unused-parameter -pg")
endif()
if (MINGW)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

if (CXX11)
message("CXX11 Mode Enabled")
add_definitionS(-DCXX11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
else()
message(FATAL_ERROR "Option CXX11 is required to be enabled for successful compilation.")
endif()

set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(src)
