project(cpppractice)
cmake_minimum_required(VERSION 2.8)
if (MINGW)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

add_subdirectory(src)
