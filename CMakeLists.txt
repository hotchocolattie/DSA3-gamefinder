cmake_minimum_required(VERSION 3.29)
project(DSA3_gamefinder)

set(CMAKE_CXX_STANDARD 14)

include_directories(DSA3-gamefinder/src)

add_executable(DSA3_gamefinder
    DSA3-gamefinder/game_data/videogames.csv
    DSA3-gamefinder/src/Heap.cpp
    DSA3-gamefinder/src/Heap.h
    DSA3-gamefinder/src/main.cpp
    DSA3-gamefinder/src/RedBlackTree.cpp
    DSA3-gamefinder/src/RedBlackTree.h
    DSA3-gamefinder/src/SetUp.h)
