cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(game)
add_executable(game GameDriver.cpp Player.cpp Resources.cpp VGMap.cpp GBMap.cpp VGMapLoader.cpp GBMapLoader.cpp Cpp-Graph-Library-master/Graph.cpp Cpp-Graph-Library-master/Node.cpp)