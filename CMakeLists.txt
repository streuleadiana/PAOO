cmake_minimum_required(VERSION 3.10)
project(TemaCPP_Zoo VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(zoo_app src/main.cpp src/ZooEnclosure.cpp)