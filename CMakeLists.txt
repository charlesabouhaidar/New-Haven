cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(gbmap_test)
add_executable(gbmap_test GBMapDriver.cpp GBMap.cpp Cpp-Graph-Library-master/Graph.cpp Cpp-Graph-Library-master/Node.cpp)

project(vgmap_test)
add_executable(vgmap_test VGMapDriver.cpp VGMap.cpp Cpp-Graph-Library-master/Graph.cpp Cpp-Graph-Library-master/Node.cpp)

project(maploader_test)
add_executable(gbmaploader_test MapLoaderDriver.cpp GBMapLoader.cpp VGMapLoader.cpp Cpp-Graph-Library-master/Graph.cpp Cpp-Graph-Library-master/Node.cpp)

project(resource_test)
add_executable(resource_test ResourcesDriver.cpp Resources.cpp GBMap.cpp Cpp-Graph-Library-master/Graph.cpp Cpp-Graph-Library-master/Node.cpp)

project(player_facilities_test)
add_executable(player_facilities_test PlayerDriver.cpp Player.cpp Resources.cpp VGMap.cpp GBMap.cpp Cpp-Graph-Library-master/Graph.cpp Cpp-Graph-Library-master/Node.cpp)
