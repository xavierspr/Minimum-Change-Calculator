cmake_minimum_required(VERSION 3.16)

project(changeCalculator LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(changeCalculator
    main.cpp
)
