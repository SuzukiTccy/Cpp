cmake_minimum_required(VERSION 2.8)

aux_source_directory(. DIR_SRCS)

# 指定生成目标 
add_executable(Object ${DIR_SRCS})