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

set(naocv_SOURCES
        src/opencv/opencv/module.cpp
        src/opencv/opencv/Objekte.cpp
        src/opencv/opencv/main.cpp
    )

include_directories(${INCLUDES})

add_executable(algo_vis ${algo_vis_SOURCES})
add_executable(naocv    ${naocv_SOURCES})

