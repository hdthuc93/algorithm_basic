cmake_minimum_required(VERSION 3.7)
project(day08_Dijkstra)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TravellingCost.cpp TravellingCost.h MiceAndMaze.cpp MiceAndMaze.h TheShortestPath.cpp TheShortestPath.h TheShortestpath2.cpp TheShortestPath2.h SendingEmail.cpp SendingEmail.h)
add_executable(day08_Dijkstra ${SOURCE_FILES})