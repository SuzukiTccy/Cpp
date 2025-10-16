# === 推荐的现代CMake写法 ===
cmake_minimum_required(VERSION 3.10)  # 建议升级到更新的版本
project(Object LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../src ../bin) # 指明本项目包含一个子目录 src，
# 这样 src 目录下的 CMakeLists.txt 文件和源代码也会被处理

# 创建可执行文件Object
add_executable(Object)
# 注意：这里不再需要../src/test_cmake.cpp，因为Test库已经由src目录构建

# 分别设置源文件和头文件
target_sources(Object
    PRIVATE
        ../object.cpp
        ../src/test_cmake.cpp    # 显式列出文件更清晰
        # 而不是使用aux_source_directory
)

# 设置包含目录
target_include_directories(Object
    PUBLIC
        ../include
        ../src
)

# 命令	                        | 作用	            |  处理文件类型	       | 影响阶段
# target_sources()	           | 指定需要编译的文件	  |  .cpp, .c 等源文件  | 编译、链接
# target_include_directories() | 指定查找头文件的目录 |  目录路径	        | 预处理

# 链接库
target_link_libraries(Object PRIVATE Test)