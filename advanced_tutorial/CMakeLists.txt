# CMake file

# cmake minimum version required
cmake_minimum_required (VERSION 3.10)
project (Advanced)

# set C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

add_executable(Advance)

add_subdirectory(./src ../bin) 
# 指明本项目包含一个子目录 src，这样 src 目录下的 CMakeLists.txt 文件和源代码也会被处理
# 并将构建输出放在bin目录，bin目录的位置是 相对于执行cmake命令时所在的位置 来说的

target_sources(Advance
    PRIVATE
    ./advanced.cpp
)

target_include_directories(Advance
    PUBLIC
        ./include
)

target_link_libraries(Advance PRIVATE AdvanceFunc)