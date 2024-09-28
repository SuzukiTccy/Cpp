cmake_minimum_required( VERSION 2.8)

project(Object)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# 添加 src 子目录
add_subdirectory(./src ../bin) # 指明本项目包含一个子目录 src，这样 src 目录下的 CMakeLists.txt 文件和源代码也会被处理,
                               # 并将输入文件放入../bin, 这个../bin是对于./src目录来说的, 最后bin会在根目录下
