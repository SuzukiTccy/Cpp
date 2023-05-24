# CMake file

# cmake minimum version required
cmake_minimum_required (VERSION 2.8)

# project info
project (Object)

# set C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# ggenerate executable file
# add_executable(src bin)
ADD_SUBDIRECTORY(src ../bin)