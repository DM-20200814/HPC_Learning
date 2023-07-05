# 用到的参考链接
`<官方文档>` : <http://eigen.tuxfamily.org/dox/GettingStarted.html> 
`<中文教程>` : <https://github.com/qixianyu-buaa/EigenChineseDocument> 
`<博客交程>` : <http://zhaoxuhui.top/blog/2019/08/21/eigen-note-1.html>
本学习过程采用camke，本人是cmake三脚猫使用者。
# 1. Eigen的安装(Linux22.04)
```
sudo apt install libeigen3-dev
# 查看位置
whereis eigen3
```
MARK: 本人使用的是Ubuntu22.04，安装完成后，可以在/usr/include/eigen3中看到头文件。apt是更方便的安装命令，apt-get也可以安装。现在大家建议使用apt
# 2. Eigen的使用
## 2.1 cmake入门
强烈建议看[B站小彭老师入门视频](https://space.bilibili.com/263032155/channel/collectiondetail?sid=53025)
```
# 首先是cmake的版本
cmake_minimum_required(VERSION 3.22)
# 指定项目和语言
project(EigenUse CXX)
# 指定编译标准
set(CMAKE_CXX_STANDARD 17)

# 查找Eigen3，找到一般会创建一些变量，例如下面的“EIGEN3_INCLUDE_DIR”，还有一个常用的<LibaryName>_FOUND检测是否找到
find_package(Eigen3 REQUIRED)
# 添加头文件
include_directories(${EIGEN3_INCLUDE_DIR})

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 输出一些信息，一般有三种状态：STATUS、WARNING、FATAL_ERROR
message(STATUS "Eigen3 include dir: ${EIGEN3_INCLUDE_DIR}")

# 添加可执行文件，可添加多个
add_executable(eigenVersion eigenVersion.cpp)
# 添加可执行文件program_day_num
add_executable(program_1_1 main.cpp)
```
注意Eigen是纯头文件引入，其实不用find_package也行
```
set(EIGEN3_INCLUDE_DIR /usr/include/eigen3)
include_directories(${EIGEN3_INCLUDE_DIR})
```
## 2.2 Eigen的使用
### 2.2.1 矩阵的定义
```
// 头文件
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
