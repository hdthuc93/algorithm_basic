cmake_minimum_required(VERSION 3.7)
project(day15_PrimAlgorithm)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MinimumSpanningTree.cpp MinimumSpanningTree.h CobbledStreet.cpp CobbledStreet.h RoadConstruction.cpp RoadConstruction.h ACMContestAndBlackout.cpp ACMContestAndBlackout.h ConnectTheCampus.cpp ConnectTheCampus.h)
add_executable(day15_PrimAlgorithm ${SOURCE_FILES})