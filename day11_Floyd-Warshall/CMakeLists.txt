cmake_minimum_required(VERSION 3.7)
project(day11_Floyd_Warshall)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Risk.cpp Risk.h PossibleFriends.cpp PossibleFriends.h ThunderMountain.cpp ThunderMountain.h MeetingProfMiguel.cpp MeetingProfMiguel.h)
add_executable(day11_Floyd_Warshall ${SOURCE_FILES})