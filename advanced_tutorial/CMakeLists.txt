# CMake file

# cmake minimum version required
cmake_minimum_required (VERSION 2.8)

# project info
project (Advanced)

# set C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# 设置头文件的搜索路径
include_directories(./include)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(.. DIR_SRCS)

# 添加 src 子目录
add_subdirectory(./src ../bin) # 指明本项目包含一个子目录 src，这样 src 目录下的 CMakeLists.txt 文件和源代码也会被处理 

# 指定生成目标 
add_executable(Advance advanced.cpp)

# 添加链接库
target_link_libraries(Advance AdvanceFunc) # 指明可执行文件 Advance 需要连接一个名为 AdvancedFunc 的链接库

# ggenerate executable file
# add_executable(src bin)