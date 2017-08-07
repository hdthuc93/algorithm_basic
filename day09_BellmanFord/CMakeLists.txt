cmake_minimum_required(VERSION 3.7)
project(day09_BellmanFord)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Wormholes.cpp Wormholes.h ExtendedTraffic.cpp ExtendedTraffic.h XYZZY.cpp XYZZY.h 106MilesToChicago.cpp 106MilesToChicago.h)
add_executable(day09_BellmanFord ${SOURCE_FILES})