cmake_minimum_required(VERSION 2.8)
project(src)

find_package(qibuild)

# Create a executable named test
# with the source file: main.cpp
qi_create_bin(src "main.cpp")

enable_testing()

# Here we say that our executable depends on
# - ALCOMMON (main naoqi lib)
# - ALVISION (for vision definitions)
# - OPENCV (display)
#
# It automatically links with the corresponding libraries and make their headers
# available.
qi_use_lib(src ALCOMMON ALVISION OPENCV2_CORE OPENCV2_HIGHGUI)