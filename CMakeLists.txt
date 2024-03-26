cmake_minimum_required(VERSION 3.10)
project(FsmProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加头文件搜索路径
include_directories(./ ./State ./Transition)

# 添加源文件
file(GLOB_RECURSE SRCS "*.cpp" "./Transition/*.cpp" "./State/*.cpp")


# 如果需要生成静态库libFsm.a，可以使用以下方式：
add_library(Fsm STATIC ${SRCS})

