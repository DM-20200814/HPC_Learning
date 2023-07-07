cmake_minimum_required(VERSION 3.22)
# 指定项目和语言
project(EigenUse CXX)
# 指定编译标准
set(CMAKE_CXX_STANDARD 17)

# 查找Eigen3
find_package(Eigen3 REQUIRED)
# 添加头文件
message(STATUS "Eigen3 include dir: ${EIGEN3_INCLUDE_DIR}")

include_directories(${EIGEN3_INCLUDE_DIR})
# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 添加可执行文件1
# add_executable(eigenVersion eigenVersion.cpp)
# 添加可执行文件program_day_num
add_executable(program_2_1 program_2_1.cpp)