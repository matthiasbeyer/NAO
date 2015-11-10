cmake_minimum_required (VERSION 2.6)
project(nao)

set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -Wextra" )

set(INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(algo_vis_SOURCES
        src/algo_vis.cpp
        src/algo/Algorithm.cpp
        src/algo/Card.cpp
        src/algo/Draw.cpp
    )

include_directories(${INCLUDES})

add_executable(algo_vis ${algo_vis_SOURCES})

