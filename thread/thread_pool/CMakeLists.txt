# CMake file

# cmake minimum version required
cmake_minimum_required (VERSION 2.8)

# project info
project (Thread)

# set C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# 设置头文件的搜索路径
include_directories(./include)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(.. DIR_SRCS)

# 添加 src 子目录
add_subdirectory(./src ../bin) # 指明本项目包含一个子目录 src，这样 src 目录下的 CMakeLists.txt 文件和源代码也会被处理,
                               # 并将输入文件放入../bin, 这个../bin是对于./src目录来说的, 最后bin会在根目录下

# 指定生成目标 
add_executable(Thread thread.cpp)

# 添加链接库
target_link_libraries(Thread ThreadFunc) # 指明可执行文件 Thread 需要连接一个名为 ThreadFunc 的链接库

# ggenerate executable file
# add_executable(src bin)