cmake_minimum_required(VERSION 3.20.0)
project(LoongCODSim VERSION 2.0.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/simulator)
add_subdirectory(${CMAKE_SOURCE_DIR}/rtl_top)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/simulator)

add_executable(sim ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(sim SIMULATOR RTL_TOP)

set(CMAKE_BUILD_TYPE Release)