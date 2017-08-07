cmake_minimum_required(VERSION 3.7)
project(day17_Disjoint_set_union)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp NetworkConnections.cpp NetworkConnections.h Friends.h Friends.cpp VirtualFriends.cpp VirtualFriends.h DZYLovesChemistry.cpp DZYLovesChemistry.h)
add_executable(day17_Disjoint_set_union ${SOURCE_FILES})