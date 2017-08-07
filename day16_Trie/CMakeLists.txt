cmake_minimum_required(VERSION 3.7)
project(day16_Trie)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp SearchEngine.cpp SearchEngine.h ConsistencyChecker.cpp ConsistencyChecker.h DNAPrefix.cpp DNAPrefix.h DiccionarioPortunol.cpp DiccionarioPortunol.h)
add_executable(day16_Trie ${SOURCE_FILES})