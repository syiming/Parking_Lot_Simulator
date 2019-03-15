cmake_minimum_required(VERSION 3.6)
project(h8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ex2.cpp basic.cpp basic.h Vehicles.cpp Vehicles.h parkinglot.cpp parkinglot.h ex1.cpp ex1.h main.cpp assignment.h ex1_lot.h)
add_executable(h8 ${SOURCE_FILES})
target_link_libraries(h8 opengl32 glu32 freeglut)